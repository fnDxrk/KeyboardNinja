#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int checkMode = 0;

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

void windowGame() {

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
    initTextMenu(buttonMenu[0], font, 70, L"Начать", 960, 700, Color::White);
    initTextMenu(buttonMenu[1], font, 70, L"Выйти", 960, 800, Color::White);


    while (window.isOpen()) {
        Event ev;
        while (window.pollEvent(ev)) {
            if (ev.type == Event::KeyPressed) {
                if (ev.key.code == Keyboard::Escape) window.close();
            }
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