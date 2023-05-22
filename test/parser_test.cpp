#include "../thirdparty/ctest.h"

#include <fileLoad.h>
#include <game.h>

CTEST (ctest, loadFontFromFile) {
    Font fontTrue;
    bool checkFontTrue = loadFontFromFile(fontTrue, "Resource/Font/Raleway/static/Raleway-Thin.ttf") ;
    ASSERT_TRUE(checkFontTrue);
    

    Font fontFalse;
    bool checkFontFalse = loadFontFromFile(fontFalse, "Resource/Font/Raleway/static/Ralewy-Thin.ttf") ;
    ASSERT_FALSE(checkFontFalse);
}

// CTEST (ctest, loadTextureFromFile) {
//     Texture screenTrue;
//     bool checkScreenTrue = loadTextureFromFile(screenTrue, "Resource/Pictures/Background/3.jpg") ;
//     ASSERT_TRUE(checkScreenTrue);
    

//     Texture screenFalse;
//     bool checkScreenFalse = loadTextureFromFile(screenFalse, "Resource/Pictures/Background/3333.jpg") ;
//     ASSERT_FALSE(checkScreenFalse);
// }
