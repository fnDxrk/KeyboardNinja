#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int checkMode = 0;
int numberButton = 0;

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

void initFrame(RectangleShape& board, Text& text) {
    float xSize = text.getGlobalBounds().width + 100;
    float ySize = text.getGlobalBounds().height + 90;

    board.setSize(Vector2f(xSize, ySize));
    board.setFillColor(Color(0, 0, 0, 0));
    board.setOutlineThickness(5);
    board.setOutlineColor(Color::White);
    float xPos = text.getPosition().x - 50;
    float yPos = text.getPosition().y - 35;
    board.setPosition(xPos, yPos);
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

void modeGame(RenderWindow &window, Event &ev, Text &text) {
    if (checkMode == 1) {
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
    window.draw(title);
    window.draw(button1);
    window.draw(button2);
}

void windowGame(RenderWindow& window, RectangleShape& boardText, Text& text, Text& titleGame1, Text& titleGame2, RectangleShape& refresh) {
    window.draw(boardText);
    window.draw(text);
    window.draw(titleGame1);
    window.draw(titleGame2);
    window.draw(refresh);
}

void splitText (std::string text, std::string *textChar) {
    int j = 0;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == '\n') {
            i+= 1;
            textChar[j] = " ";
            j++;
        }
        textChar [j] = text[i];
        j++;
    }
}

int main() {
    //Окно
    RenderWindow window;
    window.create(VideoMode::getDesktopMode(), "KeyBoardNinja", Style::Fullscreen);
    window.setFramerateLimit(60);

    //Фон
    RectangleShape background(Vector2f(1920, 1080));
    Texture screen;
    if (!screen.loadFromFile("Pictures/Background3.jpg")) return 1;
    background.setTexture(&screen);

    //Шрифт
    Font font;
    if (!font.loadFromFile("Font/Raleway/static/Raleway-Thin.ttf")) return 2;
    //if (!font.loadFromFile("Font/Mont/mont_extralightdemo.ttf")) return 2;

    //Заголовок
    Text title;
    initText(title, font, 120, L"Keyboard Ninja", 960, 300, Color::White);

    //Кнопки
    Text buttonMenu[2];
    initText(buttonMenu[0], font, 70, L"Начать", 960, 700, Color::Red);
    initText(buttonMenu[1], font, 70, L"Выйти", 960, 800, Color::White);

    //Текст
    Text titleGame1;
    Text titleGame2;
    Text text;
    std::string textB = "Here you can find activities to practise your reading skills.\nReading will help you to improve your understanding of\nthe language and build your vocabulary.";
    std::string textChar[textB.length()];
    splitText(textB, textChar);
    initText(text, font, 50, textB, 960, 500, Color::White);
    initText(titleGame1, font, 100, L"Начните печать", 960, 150, Color::Yellow);
    initText(titleGame2, font, 60, L"Отсчет времени начнется автоматически", 960, 250, Color::Yellow);
    
    //Рамка
    RectangleShape boardText;
    initFrame(boardText, text);

    //Кнопки
    RectangleShape refresh(Vector2f(80, 80));
    Texture refreshT;
    if (!refreshT.loadFromFile("Pictures/refresh-button.png")) return 1;
    refreshT.setSmooth(true);
    refresh.setTexture(&refreshT);
    refresh.setPosition(1820, 20);


    while (window.isOpen()) {
        Event ev;
        while (window.pollEvent(ev)) {
            modeMenu(window, ev, buttonMenu);
            modeGame(window, ev, titleGame1);
        }

        window.clear();
        window.draw(background);

        switch (checkMode) {
            case 0 :
                windowMenu(window, title, buttonMenu[0], buttonMenu[1]);
                break;
            case 1 :
                windowGame(window, boardText, text, titleGame1, titleGame2, refresh);
                break;
        }

        window.display();
    }

    return 0;
}