#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int checkMode = 0;
int numberButton = 0;

void initTextMenu(Text& text, Font& font, int size, String str, float xPos, float yPos,  Color textColor) {
    text.setFont(font);             //Шрифт
    text.setStyle(Text::Bold);      //Толщина шрифта
    text.setCharacterSize(size);    //Размер шрифта
    text.setString(str);            //Текст

    xPos = xPos - 10 - text.getGlobalBounds().width / 2;    //Выравнивание по X
    yPos = yPos - 20 - text.getGlobalBounds().height / 2;   //Выравнивание по Y

    text.setPosition(xPos, yPos);   //Позиция текста
    text.setFillColor(textColor);   //Цвет текста

}

void windowMenu(RenderWindow& window, Text& title, Text& button1, Text& button2) {
    window.draw(title);
    window.draw(button1);
    window.draw(button2);
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

void windowGame() {

}

void modeMenu (RenderWindow& window, Event &ev, Text buttonMenu[]) {
    if (checkMode == 0) {
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

void modeGame() {
    if (checkMode == 1) {

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
    initTextMenu(title, font, 120, L"Keyboard Ninja", 960, 300, Color::White);

    //Кнопки
    Text buttonMenu[2];
    initTextMenu(buttonMenu[0], font, 70, L"Начать", 960, 700, Color::Red);
    initTextMenu(buttonMenu[1], font, 70, L"Выйти", 960, 800, Color::White);


    while (window.isOpen()) {
        Event ev;
        while (window.pollEvent(ev)) {
            modeMenu(window, ev, buttonMenu);
            modeGame();
        }

        window.clear();
        window.draw(background);

        switch (checkMode) {
            case 0 :
                windowMenu(window, title, buttonMenu[0], buttonMenu[1]);
                break;
        }

        window.display();
    }

    return 0;
}