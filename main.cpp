#include <random>
#include <rusty_audio.h>
#include <nothofagus.h>
#include "./source/vector2d.h"
#include "./source/bounding_box.h"
#include "./source/obstacles.h"
#include "./source/globals.h"

int main()
{   
    Nothofagus::ScreenSize screenSize{(unsigned int)SCREEN_SIZE_X, (unsigned int)SCREEN_SIZE_Y};
    Nothofagus::Canvas canvas(screenSize, "SkiFree", {0.7, 0.7, 0.7}, 2);

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

    Nothofagus::Texture texturePlayer({ 32, 32 }, { 0.5, 0.5, 0.5, 1.0 });
    texturePlayer.setPallete(pallete)
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

    Nothofagus::ColorPallete palleteHydrant{
        {0.0, 0.0, 0.0, 0.0}, // transparente
        {1.0, 0.0, 0.0, 1.0},
        {0.8, 0.0, 0.0, 1.0}
    
    };
    Nothofagus::Texture textureHydrant({ 16, 16 }, { 0.5, 0.5, 0.5, 1.0 });
    textureHydrant.setPallete(palleteHydrant)
        .setPixels(
            {
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,
                0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,
                0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,
                0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,
                0,0,0,0,1,1,1,2,2,1,1,1,0,0,0,0,
                0,0,0,1,1,1,2,1,1,2,1,1,1,0,0,0,
                0,0,0,0,1,1,1,2,2,1,1,1,0,0,0,0,
                0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,
                0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,
                0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,
                0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,
                0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,
                0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


            }
            );
    
    Nothofagus::ColorPallete palleteTree{
            {0.0, 0.0, 0.0, 0.0}, // transparente
            {0.3, 0.1, 0.0, 1.0},
            {0.0, 0.6, 0.2, 1.0}
        
        };
    Nothofagus::Texture textureTree({20, 32}, { 0.5, 0.5, 0.5, 1.0 });
    textureTree.setPallete(palleteTree)
        .setPixels(
            {
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,
                0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,
                0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,
                0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,
                0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,
                0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,
                0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,
                0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,
                0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,
                0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,
                0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,
                0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,
                0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,
                0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,
                0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,
                0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,
                0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,
                0,0,0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
                0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


            }
            );


    // Player
    Nothofagus::TextureId textureIdPlayer = canvas.addTexture(texturePlayer);
    Nothofagus::BellotaId bellotaIdPlayer = canvas.addBellota({ {{SCREEN_SIZE_X/2, SCREEN_SIZE_X/2}}, textureIdPlayer });
    Nothofagus::Bellota& bellotaPlayer = canvas.bellota(bellotaIdPlayer);
    Actor player({(float)SCREEN_SIZE_X/2, (float)SCREEN_SIZE_X/2}, {0.0f,0.0f}, {Vector2D(0.0f,0.0f), Vector2D(300.0f,600.0f)}, bellotaPlayer);

    // Obstacles            
    Nothofagus::TextureId textureIdHydrant = canvas.addTexture(textureHydrant);
    Nothofagus::TextureId textureIdTree = canvas.addTexture(textureTree);

    // Variables controlador
    int direction = 3; // Entre 0 y 6. los extremos son izq y der respectivamente
    bool collision = false;
    bool leftKeyPressed = false;
    bool rightKeyPressed = false;
    float tiempoAcumulado = 0.0f;
    float intervaloAccion = 1000.0f;
    std::vector<Vector2D> directions = {{
        {0.0f, 0.0f}, // direction 0
        {0.90f, 1.0f}, // direction 1
        {0.50f, 1.0f}, // direction 2
        {0.00f, 1.0f}, // direction 3
        {-0.50f, 1.0f}, // direction 4
        {-0.90f, 1.0f}, // direction 5
        {0.00f, 0.0f}, // direction 6
 
    }};

    float time = 0.0f;
    int dist = 0;
    int speed = 0;
    int syle = 0;

    std::vector<Actor> obstacles;

    for (int i = 0; i < 10; ++i) { //Hydrant
        float newPosX = randomPosition();
        float newPosY = -100.0f * i;

        Nothofagus::Bellota newBellota{ {{newPosX, newPosY}}, textureIdHydrant};
        Nothofagus::BellotaId bellotaId = canvas.addBellota(newBellota);
        Nothofagus::Bellota& bellota = canvas.bellota(bellotaId);
        Hydrant newHydrant(Vector2D(newPosX, newPosY), bellota);
        obstacles.push_back(newHydrant);
    }

    // for (int i = 0; i < 10; ++i) { //Tree
    //     float newPosX = randomPosition();
    //     float newPosY = -100.0f * i;

    //     Nothofagus::Bellota newBellota{ {{newPosX, newPosY}}, textureIdTree};
    //     Nothofagus::BellotaId bellotaId = canvas.addBellota(newBellota);
    //     Nothofagus::Bellota& bellota = canvas.bellota(bellotaId);
    //     obstacles.push_back(&bellota);
    // }

    auto update = [&](float dt)
        {
            time += dt;

            //ImGui
            long long total_seconds = time / 1000;
            int minutes = total_seconds / 60;
            int seconds = total_seconds % 60;
            int milliseconds = static_cast<int>((long long)time % 1000);
            ImGui::Begin("SkiFree");
            ImGui::Text("Time: %02d:%02d:%02d", minutes, seconds, milliseconds);
            ImGui::Text("Dist: %dm", dist);
            ImGui::Text("Speed: %dm", speed);
            ImGui::Text("Style: %dm", syle);
            ImGui::Text("POS: %dm", direction); // ELIMINAR DESPUES
            ImGui::Text("COLLISION: %d", collision); // ELIMINAR DESPUES
            ImGui::Text("pos X: %d", obstacles[0].getPosition().x); // ELIMINAR DESPUES
            ImGui::Text("pos Y: %d", obstacles[0].getPosition().y); // ELIMINAR DESPUES
            ImGui::End();


            for (auto& obs : obstacles) {
                collision = player.collision(obs);
                obs.move(directions[direction].x* dt/10, directions[direction].y* dt/10);
            }

            
            // if (tiempoAcumulado >= intervaloAccion) {
            //     if (leftKeyPressed)
            //         pos = std::max(pos-1, 0);

            //     if (rightKeyPressed)
            //         pos = std::min(pos +1, 6);

            //     tiempoAcumulado -= intervaloAccion;
            // }
   
        };

    Nothofagus::Controller controller;
    controller.registerAction({Nothofagus::Key::A, Nothofagus::DiscreteTrigger::Press}, [&]()
    {
        //leftKeyPressed = true;
        direction = std::max(direction-1, 0);
    });
    // controller.registerAction({Nothofagus::Key::A, Nothofagus::DiscreteTrigger::Release}, [&]()
    // {
    //     leftKeyPressed = false;
    //     tiempoAcumulado = intervaloAccion;
    // });
    controller.registerAction({Nothofagus::Key::D, Nothofagus::DiscreteTrigger::Press}, [&]()
    {
        //rightKeyPressed = true;
        direction = std::min(direction +1, 6);
    });
    // controller.registerAction({Nothofagus::Key::D, Nothofagus::DiscreteTrigger::Release}, [&]()
    // // {
    //     rightKeyPressed = false;
    //     tiempoAcumulado = intervaloAccion;
    // });
    canvas.run(update, controller);
    
 
    
    

}