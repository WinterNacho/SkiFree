#include <rusty_audio.h>
#include <nothofagus.h>
#include <iomanip>
int main()
{
    Nothofagus::ScreenSize screenSize{150, 100};
    Nothofagus::Canvas canvas(screenSize, "Keyboard test", {0.7, 0.7, 0.7}, 6);

    Nothofagus::ColorPallete pallete{
    {0.0, 0.0, 0.0, 0.0}, // transparente
    {0.0, 0.0, 0.0, 1.0}, // skate
    {1.0, 1.0, 0.0, 1.0}, // ruedas
    {0.0, 0.75, 0.0, 1.0}, // zapatillas
    {0.0, 0.0, 1.0, 1.0}, // pantalon
    {1.0, 0.0, 1.0, 1.0}, // Brazos
    {1.0, 0.0, 0.0, 1.0}, // Manos, gorra y boca
    {0.75, 0.75, 0, 1.0}, // Piel
    {0.0, 0.0, 0.75, 1.0}, // Ojo
    };

    Nothofagus::Texture texture({ 32, 32 }, { 0.5, 0.5, 0.5, 1.0 });
    texture.setPallete(pallete)
        .setPixels(
            {
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,7,8,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,5,5,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,5,4,4,4,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,5,4,4,4,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,5,5,4,4,4,4,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,5,5,4,4,4,4,4,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,5,5,4,4,4,4,4,0,5,5,6,6,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,6,6,4,4,4,4,4,0,0,0,6,6,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,6,6,0,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,3,3,4,4,0,4,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,1,0,0,0,0,3,3,3,3,0,0,3,3,3,3,0,0,0,0,1,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            }
            );
    Nothofagus::TextureId textureId = canvas.addTexture(texture);
    Nothofagus::BellotaId bellotaId = canvas.addBellota({ {{75.0f, 75.0f}}, textureId });

    float time = 0.0f;
    int dist = 0;
    int speed = 0;
    int syle = 0;
    auto update = [&](float dt)
        {
            time += dt;

            long long total_seconds = time / 1000;
            int minutes = total_seconds / 60;
            int seconds = total_seconds % 60;
            int milliseconds = static_cast<int>((long long)time % 1000);
            ImGui::Begin("SkiFree");
            ImGui::Text("Time: %02d:%02d:%02d", minutes, seconds, milliseconds);
            ImGui::Text("Dist: %dm", dist);
            ImGui::Text("Speed: %dm", speed);
            ImGui::Text("Style: %dm", syle);
            ImGui::End();
       

        };
    canvas.run(update);
    
 
    
    

}