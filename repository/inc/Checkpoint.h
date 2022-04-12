#ifndef INC_CHECKPOINT_H
#define INC_CHECKPOINT_H

#include <SFML/Graphics.hpp>
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Shape.hpp"

class SFML_GRAPHICS_API Checkpoint //: public sf::Drawable
{
    public :
    Checkpoint(int x, int y, int id);
    void draw();
    private :
    int X_ , Y_ , id_ ;
}
;

#endif