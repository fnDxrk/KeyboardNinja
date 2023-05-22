#include <iostream>

#include <difficult.h>
#include <game.h>
#include <menu.h>
#include <globals.h>
#include <mode.h>
#include <window.h>
#include <fileLoad.h>

using namespace sf;

int main() {

    //Окно
    RenderWindow window;
    window.create(VideoMode::getDesktopMode(), "KeyBoardNinja", Style::Fullscreen);
    window.setFramerateLimit(60);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Фон меню
    RectangleShape background(Vector2f(1920, 1080));
    Texture screen;
    loadTextureFromFile(screen, "Resource/Pictures/Background/3.jpg");
    background.setTexture(&screen);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Шрифт
    Font font;
    loadFontFromFile(font, "Resource/Font/Raleway/static/Raleway-Thin.ttf"); 

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Заголовок
    Text title;
    initText(title, font, 120, L"Keyboard Ninja", 960, 300, Color::White);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Кнопки

    Text buttonMenu[2];
    initText(buttonMenu[0], font, 70, L"Начать", 960, 700, Color::Red);
    initText(buttonMenu[1], font, 70, L"Выйти", 960, 800, Color::White);

    Text buttonDifficult[3];
    initText(buttonDifficult[0], font, 70, L"Легко", 960, 440, Color::Red);
    initText(buttonDifficult[1], font, 70, L"Нормально", 960, 540, Color::White);
    initText(buttonDifficult[2], font, 70, L"Сложно", 960, 630, Color::White);

    RectangleShape logOutButton;    //Кнопка назад
    Texture logOutTexture;
    loadTextureFromFile(logOutTexture, "Resource/Pictures/Button/logout.png");
    initButton(logOutButton, 25, 30, logOutTexture);

    RectangleShape refreshButton;   //Кнопка перезапуска
    Texture refreshTexture;
    loadTextureFromFile(refreshTexture, "Resource/Pictures/Button/refresh.png");
    initButton(refreshButton, 1835, 30, refreshTexture);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Текст
    Text typeGamelvl[3];
    initText(typeGamelvl[0], font, 80, L"Уровень : Легкий", 960, 920, Color::White);
    initText(typeGamelvl[1], font, 80, L"Уровень : Нормальный", 960, 920, Color::White);
    initText(typeGamelvl[2], font, 80, L"Уровень : Сложный", 960, 920, Color::White);
    
    Text noticeMessage;
    String noticeMessage_str = L"Отсчет времени начнется после нажатия SPACE";
    initText(noticeMessage, font, 50, noticeMessage_str, 960, 1020, Color::White);

    Text timeMessage;
    timeMessage.setFont(font);
    timeMessage.setStyle(Text::Bold);
    timeMessage.setCharacterSize(60);
    timeMessage.setFillColor(Color::White);    

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Рамки
    RectangleShape board;

    initFrame(board, 1300, 750, 960, 450);

    
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Таймер

    Clock clock;
    int timer;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Кубик

    RectangleShape cube;
    float xSize = 50, ySize = 50;
    float xPos = 935, yPos = 100;
    initFrame(cube, xSize, ySize, xPos, yPos);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Буквы
    
    std::string letters[26]; 

    int z = 0;
    for (int i = 'A'; i <= 'Z'; i++) {
        letters[z] = i;
        z++;
    }

    Text letter;
    initText(letter, font, 40, "A", 935 + 10, 100 + 10, Color::White);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    //Результат

    Text titleResult;
    initText(titleResult, font, 120, L"Результат", 960, 300, Color::White);
    Text textSumLetters;
    Text textCorrectTypes;
    Text textIncorrectTypes;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    while (window.isOpen()) {
        Event ev;
        while (window.pollEvent(ev)) {
            modeMenu(window, ev, buttonMenu);
            modeDifficult(window, ev, buttonDifficult, logOutButton);
            modeGame(window, ev, logOutButton, refreshButton, clock, cube, letter);
            modeResult(window, ev, logOutButton);
        }

        window.clear();
        window.draw(background);

        switch (checkMode) {
            case 0 :
                windowMenu(window, title, buttonMenu[0], buttonMenu[1]);
                break;
            case 1 :
                windowDifficult(window, logOutButton, buttonDifficult[0], buttonDifficult[1], buttonDifficult[2]);
                break;
            case 2 :
                windowGame(window, board, typeGamelvl, noticeMessage, timeMessage, logOutButton, refreshButton, clock, timer, cube, letter, letters);
                break;
            case 3:
                windowResult(window, font, titleResult, textSumLetters, textCorrectTypes, textIncorrectTypes, logOutButton);
                break;
        }

        window.display();
    }

    return 0;
}