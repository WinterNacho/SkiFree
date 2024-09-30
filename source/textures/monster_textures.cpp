#include "textures.h"

Nothofagus::ColorPallete monsterPallete{
    {0.0, 0.0, 0.0, 0.0}, // transparente
    {0.0, 0.0, 0.0, 1.0},
    {1.0, 0.5, 0.1, 1.0},
    {1.0, 0.0, 0.0, 1.0}, 
    {1.0, 1.0, 1.0, 1.0},

};

Nothofagus::Texture setupMonster(){
    Nothofagus::Texture monsterTexture({32, 32}, { 0.5, 0.5, 0.5, 1.0 });
    monsterTexture.setPallete(monsterPallete)
        .setPixels(
            {
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,2,2,2,2,1,1,1,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,1,2,2,3,3,2,3,3,2,2,1,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,1,2,2,3,3,2,3,3,2,2,1,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,1,0,0,0,0,1,1,1,2,2,2,2,2,1,1,1,0,0,0,0,1,0,0,0,0,0,
                0,0,0,0,0,0,1,0,0,0,0,1,4,1,1,1,1,1,1,1,4,1,0,0,0,0,1,0,0,0,0,0,
                0,0,0,0,0,1,0,0,0,0,0,1,4,1,4,1,4,1,4,1,4,1,0,0,0,0,0,1,0,0,0,0,
                0,0,0,0,0,1,0,0,0,0,0,0,1,2,1,1,1,1,1,2,1,0,0,0,0,0,0,1,0,0,0,0,
                0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,
                0,0,0,0,0,0,0,1,0,0,0,1,1,2,2,2,2,2,2,2,1,1,0,0,0,1,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,1,0,1,2,2,2,2,2,2,2,2,2,2,2,1,0,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,1,1,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

            }
        );
    return monsterTexture;
};
