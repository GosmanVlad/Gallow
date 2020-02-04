#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
//-------------------------------//
void drawHeadMan(RenderWindow &window, CircleShape &head){
    head.setOutlineThickness(5);
    head.setOutlineColor(Color::White);
    head.setPosition({643, 45});
}

void drawBodyMan(RenderWindow &window, RectangleShape &body, int step){
    switch(step)
    {
        case 2: //body
        {
            body.setPosition(673, 65);
            body.rotate(90);
            break;
        }
        case 3: //right hand
        {
            body.setPosition(672, 155);
            body.rotate(-45);
            break;
        }
        case 4: //left hand
        {
            body.setPosition(672, 155);
            body.rotate(220);
            break;
        }
        case 5: //right foot
        {
            body.setPosition(672, 223);
            body.rotate(45);
            break;
        }
        case 6: //left foot
        {
            body.setPosition(636, 259);
            body.rotate(-45);
            break;
        }
    }
}
