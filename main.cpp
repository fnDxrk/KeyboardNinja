#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    //Окно
    RenderWindow window;
    window.create(VideoMode::getDesktopMode(), "KeyBoardNinja", Style::Fullscreen);
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        Event ev;
        while (window.pollEvent(ev)) {
            if (ev.type == Event::KeyPressed) {
                if (ev.key.code == Keyboard::Escape) window.close();
            }
        }
        window.clear(Color::Black);
        window.display();
    }


    return 0;
}