#ifndef FACHADEDIREENGINE_H
#define FACHADEDIREENGINE_H

#define GLEW_STATIC

#include <GL/glui.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <irrlicht.h>
#include <string>
#include <AppReceiver.h>

#include <Box2D/Box2D.h>
#include <Box2D/Common/b2Math.h>

using namespace std;

// Aun estando los namespace sigo definiendo las propiedades
// de los objetos con irr::core... para que c:b autocomplete bien
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class AppReceiver;

namespace dwe
{

    ///////////////////////////////////////////////
    // AnimationType
    // =============
    //
    ///////////////////////////////////////////////
    enum AnimationType {
        eAnimNone,
        eAnimStand,
        eAnimWalk,
        eAnimRun,
        eAnimAttack
    };


    ///////////////////////////////////////////////
    // vec2
    // ====
    //
    ///////////////////////////////////////////////
    template <class T>
    class vec2
    {
    public:
        T x;
        T y;

        // Constructor con xyz a cero
        vec2() : x(0), y(0) {};
        // Constructor con el mismo valor para xyz
        vec2(T _p) : x(_p), y(_p) {};
        // Constructor con valores xyz
        vec2(T _x, T _y) : x(_x), y(_y) {};
        // Constructor con los valores de otro vec2
        vec2(const vec2<T>& v) : x(v.x), y(v.y) {};
    };
    typedef vec2<f32> vec2f;
    typedef vec2<int> vec2i;


    ///////////////////////////////////////////////
    // vec3
    // ====
    //
    ///////////////////////////////////////////////
    template <class T>
    class vec3
    {
    public:
        T x;
        T y;
        T z;

        // Constructor con xyz a cero
        vec3() : x(0), y(0), z(0) {};
        // Constructor con el mismo valor para xyz
        vec3(T _p) : x(_p), y(_p), z(_p) {};
        // Constructor con valores xyz
        vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {};
        // Constructor con los valores de otro vec3
        vec3(const vec3<T>& v) : x(v.x), y(v.y), z(v.z) {};
    };
    typedef vec3<f32> vec3f;
    typedef vec3<int> vec3i;

    template<typename T> vec3<T> irrVector2dwe(irr::core::vector3d<T> irrV)
    {
        vec3<T> v;
        v.x = irrV.X;
        v.y = irrV.Y;
        v.z = irrV.Z;
        return v;
    }

    template<typename T> irr::core::vector3d<T> dweVector2irr(vec3<T> dweV)
    {
        irr::core::vector3df v;
        v.X = dweV.x;
        v.Y = dweV.y;
        v.Z = dweV.z;
        return v;
    }


    ///////////////////////////////////////////////
    // Node
    // ====
    //
    ///////////////////////////////////////////////
    template <class T>
    class NodeTemplate
    {
        public:
            NodeTemplate();
            NodeTemplate(T* n);
            void move(vec3f v);

            vec3f getPosition();
            void setPosition(vec3f v);

            vec3f getRotation();
            void setRotation(vec3f v);

            void setNode(T* n);
            /**T* getNode();**/
            void remove();

            vec3f getBoundingBox();

            void setAnimation(AnimationType a);

            vec3f getTransformedBoundingBox();
            void setTransformedBoundingBox(vec3f v);

            bool intersects(scene::IAnimatedMeshSceneNode* n);
            T* getNode();

            /***/ // TODO: �se puede quitar? No se puede poner algo as� en la fachada
            void setIAnimNode (scene::IAnimatedMeshSceneNode* n);
            scene::IAnimatedMeshSceneNode* getIAnimNode();
            /**/

        private:
            T* m_node;
            scene::IAnimatedMeshSceneNode* ianim_node;  /**/ // TODO: �se puede quitar? No se puede poner algo as� en la fachada
    };

    //typedef NodeTemplate<ISceneNode> Node;
    typedef NodeTemplate<IAnimatedMeshSceneNode> Node;
    /**typedef NodeTemplate<Node> IAnimatedMeshSceneNode;**/

    #include "GraphicsEngineTemplates.cpp"  // La implementaci�n de templates se tiene que incluir siempre en el h




    ///////////////////////////////////////////////
    // GraphicsEngine
    // ==============
    //
    ///////////////////////////////////////////////
    class GraphicsEngine
    {
    public:
        static GraphicsEngine* Instance();

        void init();
        void release();
        void close();
        bool isRunning();
        void draw();
        Node* createNode(std::string meshName);
        bool isWindowActive();
        void yield();


        //////////////////////////////
        // Eventos de teclado y rat�n
        AppReceiver receiver;

        void updateCamera(const vec3f playerPosition);


    private:
        irr::IrrlichtDevice*            m_device;
        irr::video::IVideoDriver*       m_driver;
        irr::scene::ISceneManager*      m_smgr;
        irr::gui::IGUIEnvironment*      m_guienv;

        scene::IAnimatedMeshSceneNode* createIrrAnimatedMeshSceneNode(std::string meshName);

        // Camara
        float tarUD;
        float tarLR;
        static const unsigned short _camera_desviation  = 50;
        static const float          _camera_progression = 0.5f;
        static const int            _camera_y           = 250;
        static const int            _camera_z_offset    = -100;

        GraphicsEngine() {};
    };
}

#define GEInstance dwe::GraphicsEngine::Instance()

#endif // FACHADEDIREENGINE_H
