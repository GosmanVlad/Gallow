#ifndef CLASSES_HPP_INCLUDED
#define CLASSES_HPP_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//-----------------------------//
class Button {
public:
    Button() { }
    void buttonSet(char t, Vector2f size, int charSize, Color textcolor) //char t for letters
    {
        text.setString(t);
        text.setColor(textcolor);
        text.setCharacterSize(charSize);

        button.setSize(size);
        button.setFillColor(Color::Black);
    }
    void buttonSetString(string t) { //to add string, not only letters
        text.setString(t);
        text.setColor(Color::Red);
    }
    void setFont(Font &font) {
        text.setFont(font);
    }

    void setBGColor(Color color) {
        text.setColor(color);
    }
    void setBoxColor(Color color){
        button.setFillColor(color);
    }
    void setTextColor(Color color) {
        text.setColor(color);
    }

    void setPosition(Vector2f pos) {
        button.setPosition(pos);

        float xPos = (pos.x + button.getLocalBounds().width / 10) - (text.getLocalBounds().width / 10);
        float yPos = (pos.y + button.getLocalBounds().height / 4) - (text.getLocalBounds().height / 4);
        text.setPosition({xPos, yPos});
    }
    void drawTo(RenderWindow &window) {
        window.draw(button);
        window.draw(text);
    }
    bool isMouseOver(RenderWindow &window) {
        float mouseX = Mouse::getPosition(window).x;
        float mouseY = Mouse::getPosition(window).y;

        float btnPosX = button.getPosition().x;
        float btnPosY = button.getPosition().y;

        float btnxPosWidht = button.getPosition().x + button.getLocalBounds().width;
        float btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;

        if(mouseX < btnxPosWidht && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
            return true;
        }
        return false;
    }
private:
    Text text;
    RectangleShape button;
};
//-----------------------------//
#endif
