#ifndef TAG_ENTITY_H
#define TAG_ENTITY_H

#include <string>
#include <stack>
#include <glm/glm.hpp>
#include <stack>

#include "tag/ResourceManager.h"
#include "tag/Types.h"

namespace tag
{
    class Entity
    {
        public:
            Entity();
            virtual ~Entity();

            virtual void beginDraw() = 0;
            virtual void endDraw() = 0;
            virtual vec3f getBoundingBox() = 0;

            static glm::mat4 modelMatrix;  // glm la inicializa a entidad
            static glm::mat4 viewMatrix;  // glm la inicializa a entidad
            static glm::mat4 projectionMatrix;
            static std::stack<glm::mat4> TStack;
            static ResourceManager resourceManager;

            static const uint8_t _diffuseTextureIndex   = 1;
            static const uint8_t _specularTextureIndex  = 2;
            static const uint8_t _normalTextureIndex    = 3;

        private:
    };
}

#endif // TAG_ENTITY_H
