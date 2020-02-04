#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
//-------------------------------//
void drawHeadMan(RenderWindow &window, CircleShae &head)
{
    head.setOutlineThickness(5);
    head.setOutlineColor(Color::White);
    head.setPosition({663, 55});
}
//-------------------------------//
void drawBodyMan(RenderWindow &window, RectangleShape &body, int step)
{
    switch(step)
    {
        case 2: //body
        {
            line2.setPosition(700, 65);
            line2.rotate(90);
            break;
        }

    }
}
