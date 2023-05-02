#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

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

    while (window.isOpen()) {
        Event ev;
        while (window.pollEvent(ev)) {
            if (ev.type == Event::KeyPressed) {
                if (ev.key.code == Keyboard::Escape) window.close();
            }
        }
        window.clear();
        window.draw(background);
        window.display();
    }


    return 0;
}