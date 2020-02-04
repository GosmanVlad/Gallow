#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "defines.hpp"
using namespace sf;
//-------------------------------//
void LogoSpanzuratoare( RenderWindow &initial ) {
    Texture gallow;
    gallow.loadFromFile("Images/gallow.png");
    //---------------------------------------//
    Sprite gallowImg;
    gallowImg.setTexture( gallow );
    gallowImg.setPosition( Lungime_Meniu - 350, Inaltime_Meniu - 430 );
    initial.draw( gallowImg );
}

void deseneazaSpanzuratoare( RenderWindow &window ) {
    RectangleShape line(Vector2f(150, 2)); //floor
    line.setPosition(650, 300);

    RectangleShape line2(Vector2f(280, 2)); //"Gallow body"
    line2.setPosition(775, 20);
    line2.rotate(90);

    RectangleShape line3(Vector2f(100, 2)); // "roof"
    line3.setPosition(673, 20);

    RectangleShape line4(Vector2f(20, 2)); // "roof"
    line4.rotate(90);
    line4.setPosition(673, 20);

    window.draw(line);
    window.draw(line2);
    window.draw(line3);
    window.draw(line4);
}

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
