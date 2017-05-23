#ifndef NETCOMMON_H
#define NETCOMMON_H
#include "MessageIdentifiers.h"

using namespace RakNet;

enum GameMessages
{
    ID_GAME_PARTICIPANT_ORDER = ID_USER_PACKET_ENUM+1,
    ID_GAME_STARTED,
    ID_DOOR_OPEN,
    ID_DOOR_CLOSE,
    ID_GENERATOR_ACTIVE,
    ID_PROJECTILE_CREATE,
    ID_PROJECTILEGRENADE_CREATE,
    ID_CONSUMABLE_TAKEN,
    ID_WEAPON_TAKEN,
    ID_ENEMY_UPDATE,
    ID_SEND_MEDKIT,
    ID_SEND_AMMO,
    ID_ACTIVE_ENEMY,
    ID_DEACTIVE_ENEMY,
    ID_CHEAT_DOOR_OPEN,
    ID_SWAP_WEAPON,

    MAX_ID_CUSTOM_NET_MESSAGES,
};

const int NUM_CUSTOM_NET_MESSAGES = MAX_ID_CUSTOM_NET_MESSAGES - ID_USER_PACKET_ENUM;

#endif // NETCOMMON_H
