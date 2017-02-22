#ifndef EMESH_H
#define EMESH_H

#include "Entity.h"


namespace dwe
{
    class EMesh : public Entity
    {
        public:
            EMesh();
            ~EMesh();

            void beginDraw();
            void endDraw();
    };
}

#endif // EMESH_H
