#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <menu.h>
#include <difficult.h>
#include <game.h>

using namespace sf;

void modeMenu(RenderWindow& window, Event& ev, Text buttonMenu[], int& numberButton, int& checkMode);

void modeDifficult(RenderWindow &window, Event &ev, Text buttonDifficult[], RectangleShape& logOutButton, 
                   int& numberDifficult, int& checkMode, int& sumLetters, int& correctTypes, int& incorrectTypes);

void modeGame(RenderWindow &window, Event &ev, RectangleShape& logOutButton, RectangleShape& refreshButton, 
              Clock& clock, RectangleShape& cube, Text& letter, int& checkMode, int& flagStart, int& sumLetters, 
              int& numberLetter, int& correctTypes, int& flagCorrect, int& incorrectTypes);

void modeResult(RenderWindow& window, Event& ev, RectangleShape& logOutButton, int& checkMode, int& sumLetters, int& correctTypes, int& incorrectTypes);