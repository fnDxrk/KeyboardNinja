#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int checkMode = 0;          //0 - Menu; 1 - Game
int numberButton = 0;       //0 - Начать; 1 - Выйти

//Пути для фона кнопок
std::string logOutButtonFile = "Pictures/Button/logout.png";
std::string refreshButtonFile = "Pictures/Button/refresh.png";
std::string restartButtonFile = "Pictures/Button/restart.png";


void initText(Text& text, Font& font, int size, String str, float xPos, float yPos,  Color textColor) {
    text.setFont(font);             //Шрифт
    text.setStyle(Text::Bold);      //Толщина шрифта
    text.setCharacterSize(size);    //Размер шрифта
    text.setString(str);            //Текст

    xPos = xPos - 10 - text.getGlobalBounds().width / 2;    //Выравнивание по X
    yPos = yPos - 20 - text.getGlobalBounds().height / 2;   //Выравнивание по Y

    text.setPosition(xPos, yPos);   //Позиция текста
    text.setFillColor(textColor);   //Цвет текста

}

void initFrame(RectangleShape& board, float xSize, float ySize, float xPos, float yPos) {
    board.setSize(Vector2f(xSize, ySize));      //Размер рамки
    board.setFillColor(Color(0, 0, 0, 0));      //Внутренняя часть рамки прозрачная
    board.setOutlineThickness(2);               //Толщина рамки
    board.setOutlineColor(Color::White);        //Цвет рамки
    xPos = xPos - board.getSize().x / 2;
    yPos = yPos - board.getSize().y / 2;
    board.setPosition(xPos, yPos);              //Позиция рамки
}

void initButton(RectangleShape& button, float xPos, float yPos, Texture& t, std::string background) {
    button.setSize(Vector2f(64, 64));
    t.loadFromFile(background);
    t.setSmooth(true);
    button.setTexture(&t);
    button.setPosition(xPos, yPos);
}

void MoveUp(Text button[], int& number) {
    if (number - 1 >= -1) {
        button[number].setFillColor(Color::White);
        number--;
        if (number == -1) 
            number = 1;
        button[number].setFillColor(Color::Red);
    }
}

void MoveDown(Text button[], int& number) {
    if (number + 1 >= 1) {
        button[number].setFillColor(Color::White);
        number++;
        if (number == 2) 
            number = 0;
        button[number].setFillColor(Color::Red);
    }
}

void buttonStartCondition(Text buttonMenu[]) {
    if (Mouse::getPosition().x >= 960 - 5 - buttonMenu[0].getGlobalBounds().width / 2 &&
        Mouse::getPosition().y >= 700 - buttonMenu[0].getGlobalBounds().height / 2 &&
        Mouse::getPosition().x <= 960 + buttonMenu[0].getGlobalBounds().width / 2 &&
        Mouse::getPosition().y <= 700 + buttonMenu[0].getGlobalBounds().height / 2) {
        buttonMenu[0].setFillColor(Color::Red);
        buttonMenu[1].setFillColor(Color::White);
        if (Mouse::isButtonPressed(Mouse::Left)) {
            checkMode = 1;
        }
    }
}

void buttonExitCondition(Text buttonMenu[], RenderWindow& window) {
    if (Mouse::getPosition().x >= 960 - 5 - buttonMenu[1].getGlobalBounds().width / 2 &&
        Mouse::getPosition().y >= 800 - buttonMenu[1].getGlobalBounds().height / 2 &&
        Mouse::getPosition().x <= 960 + buttonMenu[1].getGlobalBounds().width / 2 &&
        Mouse::getPosition().y <= 800 + buttonMenu[1].getGlobalBounds().height / 2) {
        buttonMenu[1].setFillColor(Color::Red);
        buttonMenu[0].setFillColor(Color::White);
        if (Mouse::isButtonPressed(Mouse::Left)) {
            window.close();
        }
    }
}

void buttonBack(RectangleShape logOutButton, RenderWindow& window) {
    if (Mouse::getPosition().x >= 25 &&
        Mouse::getPosition().y >= 30  &&
        Mouse::getPosition().x <= 25 + logOutButton.getSize().x &&
        Mouse::getPosition().y <= 30 + logOutButton.getSize().y) {
        if (Mouse::isButtonPressed(Mouse::Left)) {
            checkMode = 0;
        }
    }
}

void buttonRefresh(RectangleShape refreshButton, RenderWindow& window) {
    if (Mouse::getPosition().x >= 1835 &&
        Mouse::getPosition().y >= 30  &&
        Mouse::getPosition().x <= 1835 + refreshButton.getSize().x &&
        Mouse::getPosition().y <= 30 + refreshButton.getSize().y) {
        if (Mouse::isButtonPressed(Mouse::Left)) {
            // Изменение текста
        }
    }
}

void modeMenu (RenderWindow& window, Event &ev, Text buttonMenu[]) {
    if (checkMode == 0) {
        buttonStartCondition(buttonMenu);
        buttonExitCondition(buttonMenu, window);
        switch (ev.type) {
            case Event::KeyPressed :
                switch (ev.key.code) {
                    case Keyboard::Escape :
                        window.close();
                    case Keyboard::Up :
                        MoveUp(buttonMenu, numberButton);
                        break;
                    case Keyboard::Down :
                        MoveDown(buttonMenu, numberButton);
                        break;
                    case Keyboard::Enter :
                        if (numberButton == 0)
                            checkMode = 1;
                        else if (numberButton == 1) 
                            window.close();
                }
        }
    }
}

void modeGame(RenderWindow &window, Event &ev, Text &text, RectangleShape logOutButton, RectangleShape refreshButton) {
    if (checkMode == 1) {
        buttonBack(logOutButton, window);
        buttonRefresh(refreshButton, window);
        switch (ev.type) {
            case Event::KeyPressed :
                switch (ev.key.code) {
                    case Keyboard::Escape :
                        checkMode = 0;
                }
        }
    }
}

void windowMenu(RenderWindow& window, Text& title, Text& button1, Text& button2) {
    window.draw(title);     //Заголовок
    window.draw(button1);   //Кнопка "Начать"
    window.draw(button2);   //Кнопка "Выход"
}

void windowGame(RenderWindow& window, RectangleShape& board, Text& text, Text& titleGame1, Text& titleGame2, 
                RectangleShape& logOutButton, RectangleShape& refreshButton) {
    window.draw(board);
    //window.draw(text);
    window.draw(titleGame1);
    window.draw(titleGame2);
    window.draw(logOutButton);
    window.draw(refreshButton);
}

void splitText (std::string text, std::string *textChar) {
    int j = 0;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == '\n') {
            i += 1;
            textChar[j] = " ";
            j++;
        }
        textChar[j] = text[i];
        j++;
    }
}

int main() {
    //Окно
    RenderWindow window;
    window.create(VideoMode::getDesktopMode(), "KeyBoardNinja", Style::Fullscreen);
    window.setFramerateLimit(60);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Фон меню
    RectangleShape background(Vector2f(1920, 1080));
    Texture screen;
    if (!screen.loadFromFile("Pictures/Background/3.jpg")) return 1;
    background.setTexture(&screen);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Шрифт
    Font font;
    if (!font.loadFromFile("Font/Raleway/static/Raleway-Thin.ttf")) return 2;
    //if (!font.loadFromFile("Font/Mont/mont_extralightdemo.ttf")) return 2;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Заголовок
    Text title;
    initText(title, font, 120, L"Keyboard Ninja", 960, 300, Color::White);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Кнопки
    Text buttonMenu[2];
    initText(buttonMenu[0], font, 70, L"Начать", 960, 700, Color::Red);
    initText(buttonMenu[1], font, 70, L"Выйти", 960, 800, Color::White);

    RectangleShape logOutButton;    //Кнопка назад
    Texture logOutTexture;
    initButton(logOutButton, 25, 30, logOutTexture, logOutButtonFile);

    RectangleShape refreshButton;   //Кнопка перезапуска
    Texture refreshTexture;
    initButton(refreshButton, 1835, 30, refreshTexture, refreshButtonFile);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Текст
    Text titleGame1;
    String titleGame1Text = L"Начните печать";
    initText(titleGame1, font, 80, titleGame1Text, 960, 880, Color::White);

    Text titleGame2;
    String titleGame2Text = L"Отсчет времени начнется после ввода текста";
    initText(titleGame2, font, 50, titleGame2Text, 960, 980, Color::White);

    Text text;

    std::string textB = "Here you can find activities to practise your reading skills.\nReading will help you to improve your understanding of\nthe language and build your vocabulary.";
    std::string textChar[textB.length()];

    splitText(textB, textChar); //Делим наш текст на символы
    initText(text, font, 50, textB, 960, 500, Color::White);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Рамки
    RectangleShape board;
    // board.setSize(Vector2f(1500, 640));
    // board.setFillColor(Color(0, 0, 0, 0));
    // board.setOutlineThickness(2);
    // board.setOutlineColor(Color::White);
    // float xpos = 960 - board.getSize().x / 2;
    // float ypos = 460 - board.getSize().y / 2;
    // board.setPosition(xpos, ypos);
    initFrame(board, 1500, 640, 960, 450);

    
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    while (window.isOpen()) {
        Event ev;
        while (window.pollEvent(ev)) {
            modeMenu(window, ev, buttonMenu);
            modeGame(window, ev, titleGame1, logOutButton, refreshButton);
        }

        window.clear();
        window.draw(background);

        switch (checkMode) {
            case 0 :
                windowMenu(window, title, buttonMenu[0], buttonMenu[1]);
                break;
            case 1 :
                windowGame(window, board, text, titleGame1, titleGame2, logOutButton, refreshButton);
                break;
        }

        window.display();
    }

    return 0;
}