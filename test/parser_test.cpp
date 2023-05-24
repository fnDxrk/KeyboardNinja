#include <ctest.h>

#include <fileLoad.h>
#include <difficult.h>
#include <menu.h>
#include <game.h>

CTEST (ctest, loadFontFromFile) {
    Font fontTrue;
    bool checkFontTrue = loadFontFromFile(fontTrue, "Resource/Font/Raleway/static/Raleway-Thin.ttf") ;
    ASSERT_TRUE(checkFontTrue);
    

    Font fontFalse;
    bool checkFontFalse = loadFontFromFile(fontFalse, "Resource/Font/Raleway/static/Ralewy-Thin.ttf") ;
    ASSERT_FALSE(checkFontFalse);
}

CTEST (ctest, loadTextureFromFile) {
    Texture screenTrue;
    bool checkScreenTrue = loadTextureFromFile(screenTrue, "Resource/Pictures/Background/3.jpg") ;
    ASSERT_TRUE(checkScreenTrue);
    

    Texture screenFalse;
    bool checkScreenFalse = loadTextureFromFile(screenFalse, "Resource/Pictures/Background/3333.jpg") ;
    ASSERT_FALSE(checkScreenFalse);
}

CTEST (ctest, MoveUp) {
    Text button[2];
    int numberTrue = 0;
    bool MoveUpTrue = MoveUp(button, numberTrue);
    ASSERT_TRUE(MoveUpTrue);
    
    int numberFalse = -4;
    bool MoveUpFalse = MoveUp(button, numberFalse);
    ASSERT_FALSE(MoveUpFalse);
}

CTEST (ctest, MoveDown) {
    Text button[2];
    int numberTrue = 1;
    bool MoveUpTrue = MoveUp(button, numberTrue);
    ASSERT_TRUE(MoveUpTrue);
    
    int numberFalse = -1;
    bool MoveUpFalse = MoveUp(button, numberFalse);
    ASSERT_FALSE(MoveUpFalse);
}

CTEST (ctest, MoveUpDifficult) {
    Text button[3];
    int numberTrue = 0;
    bool MoveUpDifficultTrue = MoveUpDifficult(button, numberTrue);
    ASSERT_TRUE(MoveUpDifficultTrue);

    int numberFalse = -5;
    bool MoveUpDifficultFalse = MoveUpDifficult(button, numberFalse);
    ASSERT_FALSE(MoveUpDifficultFalse);
}

CTEST (ctest, MoveDownDifficult) {
    Text button[3];
    int numberTrue = 0;
    bool MoveDownDifficultTrue = MoveDownDifficult(button, numberTrue);
    ASSERT_TRUE(MoveDownDifficultTrue);

    int numberFalse = -5;
    bool MoveDownDifficultFalse = MoveDownDifficult(button, numberFalse);
    ASSERT_FALSE(MoveDownDifficultFalse);
}

CTEST (ctest, selectDifficult) {
    int numberDifficultTrue = 0;
    float speedFall;
    bool selectDifficultTrue = selectDifficult(numberDifficultTrue, speedFall);
    ASSERT_TRUE(selectDifficultTrue );
    
    int numberDifficultFalse = -4;
    bool selectDifficultFalse = selectDifficult(numberDifficultFalse, speedFall);
    ASSERT_FALSE(selectDifficultFalse );
}

CTEST (ctest, startPositionCube) {
    float xPos = 600;
    RectangleShape cube;
    int numberLetter;
    Text letter;
    std::string letters[26];
    startPositionCube(xPos, cube, numberLetter, letter, letters);
    ASSERT_TRUE(cube.getPosition().x == xPos);
}