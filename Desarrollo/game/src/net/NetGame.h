#ifndef NETGAME_H
#define NETGAME_H

/*
    NetGame
    =======

    Clase que gestiona la interfaz entre RakNet y nuestro juego
*/

#include "RakPeerInterface.h"
#include "ReplicaManager3.h"
#include "NatPunchthroughClient.h"
#include "CloudClient.h"
#include "FullyConnectedMesh2.h"
#include "RakNetTime.h"
#include "NetworkIDManager.h"
#include "GetTime.h"

#include "DrawableReplica.h"


#define DEFAULT_IP      "127.0.0.1"
#define DEFAULT_PT      61111
#define NET_CLOUD_KEY   "Lab21Key"
#define MAX_PLAYERS     4


namespace dwn
{
    class NetGame
    {
        public:
            static NetGame* Instance();
            virtual ~NetGame();

            void open();
            void close();
            void update();
            void addNetObject(dwn::DrawableReplica *drawReplica);
            bool isLocalObject(RakNet::RakNetGUID id);

            static bool isConnectedToNATPunchthroughServer;

            bool isMultiplayer();
            bool isConnected();
            bool connectionFailed();
            unsigned short getParticipantOrder();

            void addPlayerMate(PlayerMate* pm);
            PlayerMate* getPlayerMate(int i);
            int getNumPlayerMates();

            void startGame();   // Enviamos a los demas que empezamos
            bool getGameStarted();

        protected:

        private:
            NetGame();
            static const int                _max_players        = 32;
            static const unsigned short     _tcp_port           = 0;
            static const RakNet::TimeMS     _udp_sleep_timer    = 30;
            static const unsigned int       _time_search_server = 1500;   // Milisegundos de espera buscando servidores

            bool m_multiplayer;
            bool m_connected;
            bool m_connectionFailed;
            bool m_connectionRejected;
            bool m_isServer;
            bool m_gameStarted;
            unsigned short m_participantOrder;
            PlayerMate* m_playerMates[MAX_PLAYERS-1];
            int m_numPlayerMates;
            std::string m_IP;


            ///////////////////////////////////////////

            class Connection_RM3DireW : public RakNet::Connection_RM3
            {
                public:
                    Connection_RM3DireW(const RakNet::SystemAddress &_systemAddress, RakNet::RakNetGUID _guid) : RakNet::Connection_RM3(_systemAddress, _guid) {}
                    virtual ~Connection_RM3DireW() {}

                    virtual RakNet::Replica3 *AllocReplica(RakNet::BitStream *allocationId, RakNet::ReplicaManager3 *replicaManager3);
            };

            class ReplicaManager3DireW : public RakNet::ReplicaManager3
            {
                public:
                    virtual RakNet::Connection_RM3* AllocConnection(const RakNet::SystemAddress &systemAddress, RakNet::RakNetGUID rakNetGUID) const {
                        return new Connection_RM3DireW(systemAddress,rakNetGUID);
                    }
                    virtual void DeallocConnection(RakNet::Connection_RM3 *connection) const {
                        delete connection;
                    }
            };

            ///////////////////////////////////////////

            RakNet::RakPeerInterface *rakPeer;  // Comunicación básica
            RakNet::NetworkIDManager *networkIDManager; // Unique IDs per network object
            ReplicaManager3DireW *replicaManager3; // Replicación de objetos en red
            RakNet::NatPunchthroughClient *natPunchthroughClient; // Conexión punto a punto entre routers
            RakNet::CloudClient *cloudClient; // Used to upload game instance to the cloud
            RakNet::FullyConnectedMesh2 *fullyConnectedMesh2; // Used to find out who is the session host

            RakNet::RakString getNATTargetName(RakNet::Packet *p);

    };
}
#define NetInstance dwn::NetGame::Instance()

#endif // NETGAME_H
