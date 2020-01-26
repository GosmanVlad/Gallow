<<<<<<< HEAD
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void StartGame()
{

}
void Settings()
{
    RenderWindow settings(VideoMode(700, 500), "Setari - spanzuratoarea");
    settings.setKeyRepeatEnabled(false);
    int selectie = 0;
    bool onKeyHold = false;
    while(settings.isOpen())
    {
        Event event;
        while(settings.pollEvent(event))
        {
            if(event.type == Event::Closed)
                settings.close();
        }
        settings.display();
    }
}

void MeniuPrincipal()
{
    RenderWindow initialmenu(VideoMode(500, 500), "Spanzuratoarea");
    initialmenu.setKeyRepeatEnabled(false);
    //---------------------------------------------------------------//
    Font font;
    font.loadFromFile("Fonts/menu.ttf");
    //---------------------------------------------------------------//
    Text menuText[4];
    menuText[0].setString("Incepe jocul");
    menuText[1].setString("Setari");
    menuText[2].setString("Exit");
    menuText[0].setPosition(130, 100);
    menuText[1].setPosition(130, 200);
    menuText[2].setPosition(130, 300);
    for(int i=0;i<3;i++)
    {
        menuText[i].setFont(font);
        menuText[i].setCharacterSize(50);
        menuText[i].setFillColor(Color::White);
    }

    int selectie = 0;
    bool onKeyHold = false;
    while(initialmenu.isOpen())
    {
        Event event;
        while(initialmenu.pollEvent(event))
        {
            if(event.type == Event::Closed)
                initialmenu.close();

            else if(event.type == Event::KeyPressed)
            {
                if(event.key.code == Keyboard::Up)
                    selectie--;
                else if(event.key.code == Keyboard::Down)
                    selectie++;

                if(event.key.code == Keyboard::Enter)
                    if(selectie == 0) { initialmenu.close(); StartGame(); }
                    else if(selectie == 1) Settings();
                    else if(selectie == 2) initialmenu.close();
            }
        }
        if(selectie == 0)
        {
            menuText[0].setFillColor(Color::Red);
            menuText[1].setFillColor(Color::White);
            menuText[2].setFillColor(Color::White);
        }
        else if(selectie == 1)
        {
            menuText[0].setFillColor(Color::White);
            menuText[1].setFillColor(Color::Red);
            menuText[2].setFillColor(Color::White);
        }
        else if(selectie == 2)
        {
            menuText[0].setFillColor(Color::White);
            menuText[1].setFillColor(Color::White);
            menuText[2].setFillColor(Color::Red);
        }
        initialmenu.display();

        for(int i=0;i<3;i++)
            initialmenu.draw(menuText[i]);
    }
}

int main()
{
    MeniuPrincipal();
    return 0;
}
=======
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void StartGame()
{

}
void Settings()
{
    RenderWindow settings(VideoMode(700, 500), "Setari - spanzuratoarea");
    settings.setKeyRepeatEnabled(false);
    int selectie = 0;
    bool onKeyHold = false;
    while(settings.isOpen())
    {
        Event event;
        while(settings.pollEvent(event))
        {
            if(event.type == Event::Closed)
                settings.close();
        }
        settings.display();
    }
}

void MeniuPrincipal()
{
    RenderWindow initialmenu(VideoMode(500, 500), "Spanzuratoarea");
    initialmenu.setKeyRepeatEnabled(false);
    //---------------------------------------------------------------//
    Font font;
    font.loadFromFile("Fonts/menu.ttf");
    //---------------------------------------------------------------//
    Text menuText[4];
    menuText[0].setString("Incepe jocul");
    menuText[1].setString("Setari");
    menuText[2].setString("Exit");
    menuText[0].setPosition(130, 100);
    menuText[1].setPosition(130, 200);
    menuText[2].setPosition(130, 300);
    for(int i=0;i<3;i++)
    {
        menuText[i].setFont(font);
        menuText[i].setCharacterSize(50);
        menuText[i].setFillColor(Color::White);
    }

    int selectie = 0;
    bool onKeyHold = false;
    while(initialmenu.isOpen())
    {
        Event event;
        while(initialmenu.pollEvent(event))
        {
            if(event.type == Event::Closed)
                initialmenu.close();

            else if(event.type == Event::KeyPressed)
            {
                if(event.key.code == Keyboard::Up)
                    selectie--;
                else if(event.key.code == Keyboard::Down)
                    selectie++;

                if(event.key.code == Keyboard::Enter)
                    if(selectie == 0) { initialmenu.close(); StartGame(); }
                    else if(selectie == 1) Settings();
                    else if(selectie == 2) initialmenu.close();
            }
        }
        if(selectie == 0)
        {
            menuText[0].setFillColor(Color::Red);
            menuText[1].setFillColor(Color::White);
            menuText[2].setFillColor(Color::White);
        }
        else if(selectie == 1)
        {
            menuText[0].setFillColor(Color::White);
            menuText[1].setFillColor(Color::Red);
            menuText[2].setFillColor(Color::White);
        }
        else if(selectie == 2)
        {
            menuText[0].setFillColor(Color::White);
            menuText[1].setFillColor(Color::White);
            menuText[2].setFillColor(Color::Red);
        }
        initialmenu.display();

        for(int i=0;i<3;i++)
            initialmenu.draw(menuText[i]);
    }
}

int main()
{
    MeniuPrincipal();
    return 0;
}
>>>>>>> First commit
