#include <ctest.h>

#include <fileLoad.h>
#include <difficult.h>
#include <menu.h>
#include <game.h>
#include <mode.h>

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

CTEST(renderwindow_test, mode_result_test) {
    RenderWindow window(VideoMode(800, 600), "Mode Result Test");

    RectangleShape logOutButton(sf::Vector2f(100, 50));
    int checkMode = 3;
    int sumLetters = 10;
    int correctTypes = 5;
    int incorrectTypes = 2;

    Event ev;
    ev.type = Event::KeyPressed;
    ev.key.code = Keyboard::Escape;
    modeResult(window, ev, logOutButton, checkMode, sumLetters, correctTypes, incorrectTypes);

    ASSERT_EQUAL(0, checkMode);
    ASSERT_EQUAL(0, sumLetters);
    ASSERT_EQUAL(0, correctTypes);
    ASSERT_EQUAL(0, incorrectTypes);
}

CTEST(renderwindow_test, mode_menu_test) {
    RenderWindow window(VideoMode(800, 600), "Mode Menu Test");
    Font font;
    Text buttonMenu[2];
    buttonMenu[0].setFont(font);
    buttonMenu[0].setString("Start");
    buttonMenu[1].setFont(font);
    buttonMenu[1].setString("Exit");
    int numberButton = 0;
    int checkMode = 0;
    Event ev;
    ev.type = Event::KeyPressed;

    ev.key.code = Keyboard::Up;
    modeMenu(window, ev, buttonMenu, numberButton, checkMode);
    ASSERT_EQUAL(1, numberButton);
    
    ev.key.code = Keyboard::Down;
    modeMenu(window, ev, buttonMenu, numberButton, checkMode);
    ASSERT_EQUAL(0, numberButton);
    
    ev.key.code = Keyboard::Enter;
    numberButton = 1;
    modeMenu(window, ev, buttonMenu, numberButton, checkMode);
    ASSERT_EQUAL(0, window.isOpen());
}