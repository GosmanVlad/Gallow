#include "headers.hpp"
#include "classes.hpp"
//-------------------------------------------//
ifstream lfin("cuvinte.txt"); //Dificultate mica
ifstream mfin("cuvinte_dificile.txt"); //Dificultate medie
//-------------------------------------------//
bool verificaLitera(RenderWindow &window, char literaSelectata, string Word) {
    char fWord[Word.size() + 1];
    strcpy(fWord, Word.c_str());
    if(strchr(fWord, literaSelectata))
        return true;
    return false;
}

void LoadWord() {
    int pozitie;
    char cuvantAux[255];
    srand(time(NULL));
    int i = rand()%10 + 1;
    //--------------------------//
    memset(cuvant, 0, 256);
    //-------------------------//
    for(int j = 1; j<=i; j++)
    {
        if(setari.dificultate == 0)
            lfin>>loadWord;
        else
            mfin>>loadWord;
    }
    strcpy(domeniu, loadWord.c_str());
    strcpy(cuvantAux, domeniu);
    //---------------------------------//
    for(int i=0;i<strlen(domeniu);i++)
    {
        if(domeniu[i] == ':')
        {
            for(int j = strlen(domeniu) - 1;j>=i;j--)
                strcpy(domeniu + i, domeniu + i + 1);
            pozitie = i;
            break;
        }
    }
    strcat(cuvant, cuvantAux + pozitie + 1);
}

void StartGame(Music &muzica) {
    RenderWindow play( VideoMode(Lungime_Meniu, Inaltime_Meniu), "Sa inceapa jocul!" );
    //----------------------------------------------------------------------------------//
    LoadWord();
    //---------------------------------------------------------------------------------//
    string cuvantString = cuvant, domeniuString = domeniu;
    char l = 'A';
    int k = 50; //Distanta dintre litere
    char literaSelectata; //If you press A, then return 65 + 0 = A.
    int literePerRand = 1;
    int greseli = 0, spatiuLitereGresite = 30; //MAXIM 6 greseli
    char primaInitiala;
    Button ch[27]; //0-25 sunt litere, butonul 26 = Inapoi la meniu

    Font font;
    font.loadFromFile("Fonts/arial.ttf");

    RectangleShape line(Vector2f(Lungime_Meniu, 1)); //Separare tastatura
    line.setPosition(0, 330);

    Text wrongLetter;
    wrongLetter.setString("Litere gresite:");
    wrongLetter.setColor(Color::Red);
    wrongLetter.setPosition({20, 60});
    wrongLetter.setFont(font);
    wrongLetter.setCharacterSize(20);

    Text Domeniu[2];
    Domeniu[0].setString("Domeniu:");
    Domeniu[0].setColor(Color::Red);
    Domeniu[0].setPosition({20, 30});
    Domeniu[0].setFont(font);
    Domeniu[0].setCharacterSize(20);
    Domeniu[1].setString(domeniu);
    Domeniu[1].setColor(Color::White);
    Domeniu[1].setPosition({110, 30});
    Domeniu[1].setFont(font);
    Domeniu[1].setCharacterSize(20);
    //---------------------------------------------------------------------------------//
    Text cuvantCorect[20];
    Text lineUnderWord[20];
    int contorLitere = 0, spatiiCuvinte = 40, spatiiLinii = 40;
    for(int i = 0;i<strlen(cuvant);i++)
    {
        cuvantCorect[i].setCharacterSize(50);
        cuvantCorect[i].setFont(font);
        cuvantCorect[i].setColor(Color::Green);

        lineUnderWord[i].setFont(font);
        lineUnderWord[i].setCharacterSize(50);
        lineUnderWord[i].setColor(Color::White);
        lineUnderWord[i].setString("_");
        lineUnderWord[i].setPosition({spatiiLinii, 220});
        spatiiLinii+=47;
    }
    primaInitiala = cuvant[0];
    cuvantCorect[contorLitere].setString(cuvant[0]); //Prima litera din cuvant apare ca indiciu
    cuvantCorect[contorLitere].setPosition({spatiiCuvinte, 200});
    spatiiCuvinte = 45;
    contorLitere++;
    for(int i=1;i<strlen(cuvant);i++)
    {
        if(cuvant[i] == primaInitiala)
        {
            cuvantCorect[contorLitere].setPosition({spatiiCuvinte * (i+1)}, {200});
            cuvantCorect[contorLitere].setString(primaInitiala);
            contorLitere++;
        }

    }
    //---------------------------------------------------------------------------------//
    Text wrongs[6];
    //---------------------------------------------------------------------------------//
    CircleShape head(30);                          RectangleShape leftHand(Vector2f(50, 2));
    RectangleShape body(Vector2f(160, 2));         RectangleShape rightHand(Vector2f(50, 2));
    RectangleShape leftFoot(Vector2f(50, 2));      RectangleShape rightFoot(Vector2f(50, 2));
    //---------------------------------------------------------------------------------//
    ch[26].buttonSet('<', {250, 50}, 25, Color::Red);
    ch[26].buttonSetString("Inapoi la meniu");
    ch[26].setPosition({590, 480});
    ch[26].setFont(font);
    //---------------------------------------------------------------------------------//
    for(int i=0;i<26;i++)
    {
        if(literePerRand <= 10)
        {
            ch[i].buttonSet(l, {50, 50}, 30, Color::White);
            ch[i].setPosition({k, 330});
            ch[i].setFont(font);
        }
        else if(literePerRand <= 20)
        {
            if(k == 550)
                k=50;
            ch[i].buttonSet(l, {50, 50}, 30, Color::White);
            ch[i].setPosition({k, 390});
            ch[i].setFont(font);
        }
        else
        {
            if(k == 550)
                k = 50;
            ch[i].buttonSet(l, {50, 50}, 30, Color::White);
            ch[i].setPosition({k, 450});
            ch[i].setFont(font);
        }
        k+=50;
        l++;
        literePerRand++;
    }
    //---------------------------------------------------------------------------------//
    while(play.isOpen())
    {
        Event event;
        while(play.pollEvent(event))
        {
            if(event.type == Event::Closed)
                play.close();
            if(event.type == Event::MouseMoved)
            {
                for(int i=0;i<26;i++){
                    if(ch[i].isMouseOver(play)){
                        ch[i].setBGColor(Color::Red);
                    }
                    else ch[i].setBGColor(Color::White);
                }
                if(ch[26].isMouseOver(play))
                    ch[26].setBGColor(Color::White);
                else
                    ch[26].setBGColor(Color::Red);
            }
            if(event.type == Event::MouseButtonPressed){
                for(int i=0;i<26;i++)
                {
                    if(ch[i].isMouseOver(play))
                    {
                        literaSelectata = 65 + i; //ASCII 65 = A, 65 + 1 = B
                        if(verificaLitera(play, literaSelectata, cuvantString) && literaSelectata != primaInitiala)
                        {
                            for(int i=1;i<strlen(cuvant);i++)
                            {
                                if(literaSelectata == cuvant[i])
                                {
                                    cuvantCorect[contorLitere].setPosition({spatiiCuvinte * (i+1)}, {200});
                                    cuvantCorect[contorLitere].setString(literaSelectata);
                                    contorLitere++;
                                }
                            }
                            if(contorLitere == strlen(cuvant))
                            {
                                play.close();
                                GameWin(muzica);
                            }
                        }
                        else
                        {
                            wrongs[greseli].setString(literaSelectata);
                            wrongs[greseli].setColor(Color::White);
                            wrongs[greseli].setPosition({spatiuLitereGresite, 90});
                            wrongs[greseli].setFont(font);
                            wrongs[greseli].setCharacterSize(17);
                            greseli ++ ;
                            spatiuLitereGresite+=20;
                            //--------------------------------------------------//
                            switch(greseli)
                            {
                                case 1: drawHeadMan(play, head); break;
                                case 2: drawBodyMan(play, body, greseli); break;
                                case 3: drawBodyMan(play, rightHand, greseli); break;
                                case 4: drawBodyMan(play, leftHand, greseli); break;
                                case 5: drawBodyMan(play, rightFoot, greseli); break;
                                case 6: drawBodyMan(play, leftFoot, greseli); play.close(); GameOver(muzica); break;
                            }
                            //--------------------------------------------------//
                        }
                    }
                }
                if(ch[26].isMouseOver(play)){
                    play.close();
                    MeniuPrincipal(muzica);
                }
            }

        }
        play.display();
        //---------------------------------------//
        for(int i=0;i<27;i++) ch[i].drawTo(play);
        for(int i=0;i<2;i++) play.draw(Domeniu[i]);
        for(int i=0;i<6;i++)  play.draw(wrongs[i]);
        for(int i=0;i<contorLitere;i++){ play.draw(cuvantCorect[i]); }
        for(int i=0;i<strlen(cuvant);i++)  play.draw(lineUnderWord[i]);
        //---------------------------------------//
        switch(greseli)
        {
            case 1: play.draw(head); break;
            case 2: play.draw(body); break;
            case 3: play.draw(rightHand); break;
            case 4: play.draw(leftHand); break;
            case 5: play.draw(rightFoot); break;
            case 6: play.draw(leftFoot); break;
        }
        play.draw(line);
        deseneazaSpanzuratoare(play);
        play.draw(wrongLetter);
    }
}

void GameWin(Music &muzica) {
    RenderWindow gwin( VideoMode(Lungime_Meniu, Inaltime_Meniu), "Felicitari! Ai castigat!" );
    //-------------------------------------------------------------------------------//
    Font font, font2;
    Text intro, word, info;
    Button options[3];

    font.loadFromFile("Fonts/ARIALN.ttf");
    font2.loadFromFile("Fonts/game_over.ttf");

    intro.setString("Game WIN!!!");
    intro.setFont(font2);
    intro.setCharacterSize(170);
    intro.setPosition({100, 0});
    intro.setColor(Color::Red);

    word.setFont(font);
    word.setCharacterSize(45);
    word.setPosition({80, 70});

    info.setString("Felicitari! Ai castigat aceasta runda!\n Daca ti s-a parut prea usor,\n seteaza nivelul mediu din setari.");
    info.setFont(font);
    info.setColor(Color::White);
    //info.setCharacterSize(25);
    info.setPosition({30, 200});

    options[0].buttonSet('<', {150, 50}, 25, Color::Red);
    options[0].buttonSetString("Inapoi la meniu");
    options[0].setPosition({0, 480});
    options[0].setFont(font);

    options[1].buttonSet('<', {250, 50}, 25, Color::Red);
    options[1].buttonSetString("Joaca din nou");
    options[1].setPosition({320, 480});
    options[1].setFont(font);

    options[2].buttonSet('<', {150, 50}, 25, Color::Red);
    options[2].buttonSetString("Paraseste jocul");
    options[2].setPosition({650, 480});
    options[2].setFont(font);

    while(gwin.isOpen())
    {
        Event event;
        while(gwin.pollEvent(event))
        {
            if(event.type == Event::Closed)
                gwin.close();
            else if(event.type == Event::MouseMoved)
            {
                for(int i=0;i<3;i++){
                    if(options[i].isMouseOver(gwin)){
                        options[i].setBGColor(Color::Red);
                    }
                    else options[i].setBGColor(Color::White);
                }
            }
            else if(event.type == Event::MouseButtonPressed){
                    if(options[0].isMouseOver(gwin))
                    {
                        gwin.close();
                        MeniuPrincipal(muzica);
                    }
                    else if(options[1].isMouseOver(gwin))
                    {
                        gwin.close();
                        StartGame(muzica);
                    }
                    else if(options[2].isMouseOver(gwin))
                        gwin.close();
            }

        }
        gwin.display();
        gwin.draw(intro);
        gwin.draw(word);
        gwin.draw(info);
        for(int i=0;i<3;i++)
            options[i].drawTo(gwin);
    }
}

void GameOver(Music &muzica) {
    RenderWindow window( VideoMode(Lungime_Meniu, Inaltime_Meniu), "Ai pierdut!" );
    //-------------------------------------------------------------------------------//
    Font font, font2;
    Text intro, word, info;
    Button options[3];

    font.loadFromFile("Fonts/ARIALN.ttf");
    font2.loadFromFile("Fonts/game_over.ttf");

    intro.setString("Game Over");
    intro.setFont(font2);
    intro.setCharacterSize(170);
    intro.setPosition({100, 0});
    intro.setColor(Color::Red);

    word.setFont(font);
    word.setCharacterSize(45);
    word.setPosition({80, 70});

    info.setString("Nu te descuraja! Incearca din nou!\n Nu uita ca ai doar 6 incercari in ghicirea cuvantului,\n altfel, Smith va fi ucis!");
    info.setFont(font);
    info.setColor(Color::White);
    //info.setCharacterSize(25);
    info.setPosition({30, 200});

    options[0].buttonSet('<', {150, 50}, 25, Color::Red);
    options[0].buttonSetString("Inapoi la meniu");
    options[0].setPosition({0, 480});
    options[0].setFont(font);

    options[1].buttonSet('<', {250, 50}, 25, Color::Red);
    options[1].buttonSetString("Joaca din nou");
    options[1].setPosition({320, 480});
    options[1].setFont(font);

    options[2].buttonSet('<', {150, 50}, 25, Color::Red);
    options[2].buttonSetString("Paraseste jocul");
    options[2].setPosition({650, 480});
    options[2].setFont(font);

    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                window.close();
            else if(event.type == Event::MouseMoved)
            {
                for(int i=0;i<3;i++){
                    if(options[i].isMouseOver(window)){
                        options[i].setBGColor(Color::Red);
                    }
                    else options[i].setBGColor(Color::White);
                }
            }
            else if(event.type == Event::MouseButtonPressed){
                    if(options[0].isMouseOver(window))
                    {
                        window.close();
                        MeniuPrincipal(muzica);
                    }
                    else if(options[1].isMouseOver(window))
                    {
                        window.close();
                        StartGame(muzica);
                    }
                    else if(options[2].isMouseOver(window))
                        window.close();
            }

        }
        window.display();
        window.draw(intro);
        window.draw(word);
        window.draw(info);
        for(int i=0;i<3;i++)
            options[i].drawTo(window);
    }
}

void Settings(Music &muzica, Font font) {
    int selectie = 0;
    RenderWindow settings( VideoMode(Lungime_Meniu, Inaltime_Meniu), "Setari - spanzuratoarea" );
    settings.setKeyRepeatEnabled( false );

    Text butoaneSetari[8];
    for(int i=0;i<7;i++)
    {
        i == 0 ? butoaneSetari[i].setColor(Color::Red) : butoaneSetari[i].setColor(Color::White);
        butoaneSetari[i].setFont(font);
        butoaneSetari[i].setCharacterSize(50);
    }
    butoaneSetari[0].setString(" Dificultate: ");
    butoaneSetari[0].setPosition(130, 100);

    butoaneSetari[1].setString("Usor");
    butoaneSetari[1].setPosition(380, 100);
    butoaneSetari[1].setColor(Color::Red);

    butoaneSetari[2].setString("Mediu");
    butoaneSetari[2].setPosition(500, 100);

    butoaneSetari[3].setString(" Muzica: ");
    butoaneSetari[3].setPosition(130, 200);

    butoaneSetari[4].setString(" On ");
    butoaneSetari[4].setPosition(380, 200);
    butoaneSetari[4].setColor(Color::Red);

    butoaneSetari[5].setString(" Off ");
    butoaneSetari[5].setPosition(500, 200);


    butoaneSetari[6].setString(" Inapoi ");
    butoaneSetari[6].setPosition(130, 300);
    while(settings.isOpen())
    {
        Event event;
        while(settings.pollEvent(event))
        {
            if(event.type == Event::Closed)
                settings.close();

            else if(event.type == Event::KeyPressed)
            {
                if(event.key.code == Keyboard::Up)
                    if(selectie == 0)
                        selectie = 2;
                    else selectie--;

                else if(event.key.code == Keyboard::Down)
                    if(selectie == 2)
                        selectie = 0;
                    else selectie++;

                if(event.key.code == Keyboard::Right)
                    if(selectie == 0)
                        if(setari.dificultate==0)
                            setari.dificultate++;
                        else setari.dificultate--;
                     else if(selectie == 1)
                        if(!setari.musicOn)
                            setari.musicOn = true;
                        else setari.musicOn = false;

                if(event.key.code == Keyboard::Left)
                {
                    if(selectie == 0 && setari.dificultate == 1)
                        setari.dificultate--;
                    else if(selectie == 1)
                        if(!setari.musicOn)
                            setari.musicOn = true;
                        else setari.musicOn = false;
                }
                if(event.key.code == Keyboard::Enter)
                    if(selectie == 2) { settings.close(); MeniuPrincipal(muzica); }

            }
        }

        if(setari.musicOn && setari.muzicaOprita)
        {
            muzica.play();
            butoaneSetari[4].setColor(Color::Red);
            butoaneSetari[5].setColor(Color::White);
            setari.muzicaOprita = false;
        }
        else if(!setari.musicOn)
        {
            muzica.pause();
            butoaneSetari[5].setColor(Color::Red);
            butoaneSetari[4].setColor(Color::White);
            setari.muzicaOprita = true;
        }
        //--------------------------------------------//
        if(setari.dificultate == 0)
        {
            butoaneSetari[1].setColor(Color::Red);
            butoaneSetari[2].setColor(Color::White);
        }
        else
        {
            butoaneSetari[1].setColor(Color::White);
            butoaneSetari[2].setColor(Color::Red);
        }
        //--------------------------------------------//
        if(selectie == 0)
        {
            butoaneSetari[0].setColor(Color::Red);
            butoaneSetari[3].setColor(Color::White);
            butoaneSetari[6].setColor(Color::White);
        }
        else if(selectie == 1)
        {
            butoaneSetari[0].setColor(Color::White);
            butoaneSetari[3].setColor(Color::Red);
            butoaneSetari[6].setColor(Color::White);
        }
        else if(selectie == 2)
        {
            butoaneSetari[0].setColor(Color::White);
            butoaneSetari[3].setColor(Color::White);
            butoaneSetari[6].setColor(Color::Red);
        }
        settings.display();

        for(int i=0;i<7;i++) settings.draw(butoaneSetari[i]);
    }
}

void MeniuPrincipal(Music &muzica) {
    RenderWindow initialmenu(VideoMode(Lungime_Meniu, Inaltime_Meniu), "Spanzuratoarea");
    initialmenu.setKeyRepeatEnabled(false);

    if(setari.musicOn && setari.muzicaOprita) { muzica.play(); setari.muzicaOprita = false; }
    //---------------------------------------------------------------//
    Font font, font2;
    font.loadFromFile("Fonts/menu.ttf");
    font2.loadFromFile("Fonts/arial.ttf");
    //---------------------------------------------------------------//
    Text info;
    info.setString("Foloseste sagetile, respectiv tasta ENTER pentru a naviga in meniu.");
    info.setCharacterSize(20);
    info.setFont(font2);
    info.setPosition({10, 10});

    Text menuText[4];
    menuText[0].setString("Incepe jocul");
    menuText[1].setString("Setari");
    menuText[2].setString("Exit");

    menuText[0].setPosition(130, 100); //Start
    menuText[1].setPosition(130, 200); //Settings
    menuText[2].setPosition(130, 300); //Exit

    for(int i=0;i<3;i++)
    {
        menuText[i].setFont(font);
        menuText[i].setCharacterSize(50);
        menuText[i].setFillColor(Color::White);
    }

    int selectie = 0;
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
                    if(selectie == 0)
                        selectie = 2;
                    else
                        selectie--;
                else if(event.key.code == Keyboard::Down)
                    if(selectie == 2)
                        selectie = 0;
                    else selectie++;
                if(event.key.code == Keyboard::Enter)
                    if(selectie == 0) { initialmenu.close(); StartGame(muzica); }
                    else if(selectie == 1) { initialmenu.close(); Settings(muzica, font); }
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
        LogoSpanzuratoare(initialmenu);
        initialmenu.draw(info);
    }
}

int main()
{
    sf::Music muzica;
    muzica.openFromFile("sounds/thinking.wav");
    MeniuPrincipal(muzica);
    return 0;
}
