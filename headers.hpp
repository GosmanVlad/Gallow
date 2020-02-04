#ifndef HEADERS_HPP_INCLUDED
#define HEADERS_HPP_INCLUDED
/***************************/
#include <iostream>
#include <fstream>
#include <stdlib.h> //random numbers
#include <cstring>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include "defines.hpp"
#include "structures.hpp"
#include "draws.hpp"
/***************************/
using namespace std;
using namespace sf;
/***************************/
void MeniuPrincipal(Music &muzica);
void Settings();
void StartGame(Music &muzica);
void LogoSpanzuratoare();
void GameOver(Music &muzica);
void GameWin(Music &muzica);
/***************************/
string loadWord;
char domeniu[256];
char cuvant[256];
/***************************/
#endif
