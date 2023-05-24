#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

void initText(Text& text, Font& font, int size, String str, float xPos, float yPos,  Color textColor);

void initButton(RectangleShape& button, float xPos, float yPos, Texture& t);

void MoveUp(Text button[], int& number);

void MoveDown(Text button[], int& number);

void buttonStartCondition(Text buttonMenu[], int& numberButton, int& checkMode);

void buttonExitCondition(Text buttonMenu[], RenderWindow& window, int& numberButton, int& checkMode);