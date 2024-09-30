#include <random>
#include <cmath>
#include <rusty_audio.h>
#include <nothofagus.h>
#include "./source/vector2d.h"
#include "./source/bounding_box.h"
#include "./source/obstacles.h"
#include "./source/globals.h"
#include "./source/textures/textures.h"
int main()
{   
    // SONIDO
    constexpr unsigned int sampleRate = 48000;
    constexpr unsigned int channels = 2;

    // Sonido Collision
    RustyAudio::Builder soundBuilderCollision;
    soundBuilderCollision.appendSinusoids({
        {200, 0.2, 250},
        {300, 0.3, 150},

    });
    RustyAudio::Buffer soundBufferCollision = soundBuilderCollision.generate(sampleRate, channels);
    RustyAudio::Player soundCollision;
    soundCollision.init(soundBufferCollision);

    // sonido rampa 

    RustyAudio::Builder soundBuilderRamp;
    soundBuilderRamp.appendSinusoids({
        {50, 0.2, 750},
        {50, 0.3, 850},
        {200, 0.4, 950},

    });
    RustyAudio::Buffer soundBufferRamp = soundBuilderRamp.generate(sampleRate, channels);
    RustyAudio::Player soundRamp;
    soundRamp.init(soundBufferRamp);

    // Start game

    RustyAudio::Builder soundBuilderStart;
    soundBuilderStart.appendSinusoids({
        {200, 0.5, 440},
        {150, 0.5, 523},
        {150, 0.4, 659},
        {100, 0.6, 880},
        {200, 0.5, 523},
        {150, 0.4, 659},
        {300, 0.3, 440},
    });
    RustyAudio::Buffer soundBufferStart = soundBuilderStart.generate(sampleRate, channels);
    RustyAudio::Player soundStart;
    soundStart.init(soundBufferStart);
    // End game

    RustyAudio::Builder soundBuilderEnd;
    soundBuilderEnd.appendSinusoids({
        {300, 0.5, 220},  // A3 (300 ms)
        {200, 0.4, 165},  // E3 (200 ms)
        {150, 0.3, 130},  // C3 (150 ms)
        {300, 0.2, 110},  // A2 (300 ms)
        {150, 0.4, 165},  // E3 (150 ms)
        {200, 0.3, 220},  // A3 (200 ms)
    });
    RustyAudio::Buffer soundBufferEnd = soundBuilderEnd.generate(sampleRate, channels);
    RustyAudio::Player soundEnd;
    soundEnd.init(soundBufferEnd);

    // Screen and Canvas
    Nothofagus::ScreenSize screenSize{(unsigned int)SCREEN_SIZE_X, (unsigned int)SCREEN_SIZE_Y};
    Nothofagus::Canvas canvas(screenSize, "SkiFree", {0.7, 0.7, 0.7}, 2);

    // Player
    std::vector<Nothofagus::Texture> playerTextures = setupPlayerTextures();
    std::vector<Nothofagus::Bellota*> PlayerBellotas;  // Almacenar punteros
    for(auto& tex: playerTextures){  // Usar referencia para evitar copias
        Nothofagus::TextureId TextureId = canvas.addTexture(tex);
        Nothofagus::BellotaId bellotaId = canvas.addBellota({ {{SCREEN_SIZE_X/2, SCREEN_SIZE_X/2 - 100}}, TextureId });
        Nothofagus::Bellota& bellotaPlayer = canvas.bellota(bellotaId);
        PlayerBellotas.push_back(&bellotaPlayer);  // Almacenar puntero
    }
    Actor player({(float)SCREEN_SIZE_X/2, (float)SCREEN_SIZE_X/2 -100}, {0.0f, 0.0f}, {Vector2D(14.0f,4.0f), Vector2D(20.0f,6.0f)}, *PlayerBellotas[3]);

    // Obstacles
    Nothofagus::Texture textureHydrant = setupHydrantTextures();
    Nothofagus::Texture textureTree = setupTreeTextures(); 
    Nothofagus::Texture textureRamp = setupRampTextures(); 
    Nothofagus::TextureId textureIdHydrant = canvas.addTexture(textureHydrant);
    Nothofagus::TextureId textureIdTree = canvas.addTexture(textureTree);
    Nothofagus::TextureId textureIdRamp = canvas.addTexture(textureRamp);
    
    std::vector<Actor> obstacles;
    std::vector<Actor> Ramps;
    for (int i = 0; i < 10; ++i) { // Ramp
        float newPosX = randomPosition();
        float newPosY = -220.0f * i;
        Nothofagus::Bellota newBellota{ {{newPosX, newPosY}}, textureIdRamp };
        Nothofagus::BellotaId bellotaId = canvas.addBellota(newBellota);
        Nothofagus::Bellota& bellota = canvas.bellota(bellotaId);
        Ramp newRamp(Vector2D(newPosX, newPosY), bellota);
        Ramps.push_back(newRamp);
    }
    for (int i = 0; i < 10; ++i) { // Hydrant
        float newPosX = randomPosition();
        float newPosY = -340.0f * i;
        Nothofagus::Bellota newBellota{ {{newPosX, newPosY}}, textureIdHydrant};
        Nothofagus::BellotaId bellotaId = canvas.addBellota(newBellota);
        Nothofagus::Bellota& bellota = canvas.bellota(bellotaId);
        Hydrant newHydrant(Vector2D(newPosX, newPosY), bellota);
        obstacles.push_back(newHydrant);
    }
    for (int i = 0; i < 50; ++i) { // Tree
        float newPosX = randomPosition();
        float newPosY = -60.0f * i;

        Nothofagus::Bellota newBellota{ {{newPosX, newPosY}}, textureIdTree};
        Nothofagus::BellotaId bellotaId = canvas.addBellota(newBellota);
        Nothofagus::Bellota& bellota = canvas.bellota(bellotaId);
        Tree newTree(Vector2D(newPosX, newPosY), bellota);
        obstacles.push_back(newTree);
    }

    // Monster
    Nothofagus::Texture monsterTexture = setupMonster(); 
    Nothofagus::TextureId monsterTextureId = canvas.addTexture(monsterTexture);
    Nothofagus::BellotaId bellotaIdMonster = canvas.addBellota({ {{450.0f, 450.0f}}, monsterTextureId });
    Nothofagus::Bellota& bellotaMonster = canvas.bellota(bellotaIdMonster);
    bellotaMonster.visible() = false;

    Actor monster({ 450.0f, 450.0f }, { 0.0f, 0.0f }, {Vector2D(14.0f,4.0f), Vector2D(20.0f,6.0f)}, bellotaMonster);

    // Directions
    std::vector<Vector2D> directions = {{
        {0.0f, 0.0f}, // direction 0
        {0.18f, 0.2f}, // direction 1
        {0.1, 0.2f}, // direction 2
        {0.0f, 0.2f}, // direction 3
        {-0.1, 0.2f}, // direction 4
        {-0.18f, 0.2f}, // direction 5
        {0.0f, 0.0f}, // direction 6
        {0.0f, 0.0f}, // direction 7 -> Collision 
        {0.0f, 0.6f}, // direction 8 -> Ramp
    }};

    int direction = 3;
    int lastDirection;
    // ImGui
    float time = 0.0f;
    float dist = 0;
    int speed = 0;;

    // collision
    bool collision = false, rampJump = false;
    float collisionTimer = 0, inmunityTimer = 0, rampTimer = 0;
    const float collisionDuration = 2000; 
    const float inmunityDuration = 2500;    
    const float RampDuration = 1500;
    bool inmunity = false;

    // Monster 
    float monsterSpawnTime = 0;//randomPosition(120000, 240000);
    bool end = false;
    Vector2D monsterDirecction(0,0);

    soundStart.play();
    auto update = [&](float dt)
        {
            if(!end)
                time += dt;

            //ImGui
            long long total_seconds = time / 1000;
            int minutes = total_seconds / 60;
            int seconds = total_seconds % 60;
            int milliseconds = static_cast<int>((long long)time % 1000);
            ImGui::Begin("SkiFree");
            ImGui::Text("Time: %02d:%02d:%02d", minutes, seconds, milliseconds);
            ImGui::Text("Dist: %dm", (long long)dist/50);
            ImGui::Text("Speed: %d", speed);
            ImGui::End();

            for (auto& obs : obstacles) {
                if (player.collision(obs) and !inmunity) {
                    soundCollision.play();
                    collision = true; inmunity = true;
                    collisionTimer = time; inmunityTimer = time;
                    lastDirection = direction;
                    direction = 7;
                }
                obs.move(directions[direction].x* dt, directions[direction].y* dt);
            }

            for (auto& ramp : Ramps) {
                if (player.collision(ramp) and !rampJump) {
                    soundRamp.play();
                    inmunity = true;
                    rampJump = true;
                    inmunityTimer = time;
                    rampTimer = time;
                    lastDirection = direction;
                    direction = 8;
                }
                ramp.move(directions[direction].x* dt, directions[direction].y* dt);
            }
            
            // Timer Collision
            if (collision && (time > collisionTimer + collisionDuration)) {
                direction = 3; 
                collision = false;
                direction = lastDirection;
            }

            // Timer Jump
            else if (rampJump) {
                if (time > rampTimer + RampDuration) {
                    rampJump = false;
                    inmunity = false;
                    direction = 3;
                }
            }

            // Stop inmunity
            else if (inmunity && (time > inmunityTimer + inmunityDuration)) {
                inmunity = false; 
            }

            //Player textures 
            for (int i = 0; i <= 8; i++) {
                if (direction == i) {
                    PlayerBellotas[i]->visible() = true; 
                } else {
                    PlayerBellotas[i]->visible() = false;
                }
            }

            speed = directions[direction].y *10;
            dist += directions[direction].y;

            if(time > monsterSpawnTime){
                bellotaMonster.visible() = true;
                monsterDirecction.x = monster.getPosition().x - player.getPosition().x;
                monsterDirecction.y = monster.getPosition().y - player.getPosition().y;
                float magnitud = std::sqrt(monsterDirecction.x * monsterDirecction.x + monsterDirecction.y * monsterDirecction.y);
                monsterDirecction.x = monsterDirecction.x / magnitud; monsterDirecction.y = monsterDirecction.y / magnitud;
                monster.move(directions[direction].x* dt/1.2 , directions[direction].y* dt/1.2);
                monster.move(- monsterDirecction.x/5, - monsterDirecction.y/5);
            }
            if(monster.collision(player)){
                end = true;
                soundEnd.play();
                direction = 7;
            }

        };

    Nothofagus::Controller controller;
    controller.registerAction({Nothofagus::Key::LEFT, Nothofagus::DiscreteTrigger::Press}, [&]()
    {
        //leftKeyPressed = true;
            if (direction < 7)
            direction = std::max(direction-1, 0);
    });
    controller.registerAction({Nothofagus::Key::A, Nothofagus::DiscreteTrigger::Press}, [&]()
    {
        //leftKeyPressed = true;
            if (direction < 7)
            direction = std::max(direction-1, 0);
    });
    controller.registerAction({Nothofagus::Key::RIGHT, Nothofagus::DiscreteTrigger::Press}, [&]()
    {
        //rightKeyPressed = true;
        if (direction < 7)
            direction = std::min(direction +1, 6);
    });
        controller.registerAction({Nothofagus::Key::D, Nothofagus::DiscreteTrigger::Press}, [&]()
    {
        //rightKeyPressed = true;
        if (direction < 7)
            direction = std::min(direction +1, 6);
    });

    canvas.run(update, controller);

}