#include <fileLoad.h>

bool loadTextureFromFile(Texture& texture, std::string path) {
    if (!texture.loadFromFile(path)) return false;
    return true;
}

bool loadFontFromFile(Font& font, std::string path) {
    if (!font.loadFromFile(path)) return false;
    return true;
}