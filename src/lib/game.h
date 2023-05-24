#pragma once

#include <chrono>
#include <thread>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

using namespace sf;

void initFrame(RectangleShape& board, float xSize, float ySize, float xPos, float yPos);

void buttonBack(RectangleShape logOutButton, RenderWindow& window, int& checkMode);

void buttonRefresh(RectangleShape refreshButton, RenderWindow& window, RectangleShape& cube, Text& letter, int& sumLetters, int& correctTypes, int& incorrectTypes, int& flagStart);

void startTimer(Text &timeMessage, Clock& clock, RectangleShape& cube, Text& letter, int& checkMode, int& flagStart);

bool selectDifficult(int& numberDifficult, float& speedFall);

void startPositionCube(float& xPos, RectangleShape& cube, int& numberLetter, Text& letter, std::string *letters);

void gameKey(RenderWindow& window, RectangleShape& cube, Text& letter, std::string *letters, int& numberDifficult, int& flagCorrect, int& correctTypes, int& incorrectTypes, int& sumLetters, int& numberLetter);

void checkCorrect(Event& ev, int& numberLetter, int& correctTypes, int& flagCorrect, int& sumLetters, int& incorrectTypes);