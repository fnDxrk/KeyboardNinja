#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

void MoveUpDifficult(Text button[], int& number);

void MoveDownDifficult(Text button[], int& number);

void buttonEasyCondition(Text buttonDifficult[], int& numberDifficult, int& checkMode);

void buttonNormalCondition(Text buttonDifficult[], int& numberDifficult, int& checkMode);

void buttonHardCondition(Text buttonDifficult[], int& numberDifficult, int& checkMode);
