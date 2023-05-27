#include "Engine/Graphics.h"
#include "Engine/Random.h"
#include "Tests/ParticleTest.h"
#include "Tests/ForceTest.h"
#include "Tests/ContactTests.h"
#include "Tests/JointTest.h"
#include <iostream>
#include <SDL.h>
#include <glm/glm.hpp>

int main(int argc, char* argv[]) 
{
    Test* test = new ContactTests();
    test->Initialize();

    while (!test->IsQuit())
    {
        test->Run();
    }
    delete test;

    //Graphics graphics;
    //glm::ivec2 screen{ 800, 600 };
    //graphics.CreateWindow("Physics", screen.x, screen.y);
    //// Main loop
    //bool quit = false;
    //graphics.Clear();
    //for (int i = 0; i < 200; i++)
    //{
    //    graphics.DrawPoint({ random(0, screen.x), random(0, screen.y) }, { randomf(0, 1), randomf(0, 1), randomf(0, 1), 255 });
    //    graphics.DrawCircle({ random(0, screen.x), random(0, screen.y) }, random(5, 20), { random(0, 255), random(0, 255), random(0, 255), 255 });
    //    graphics.DrawFilledCircle({ random(0, screen.x), random(0, screen.y) }, random(5, 20), { random(0, 255), random(0, 255), random(0, 255), 255 });
    //    graphics.DrawLine({ random(0, screen.x), random(0, screen.y) }, { random(0, screen.x), random(0, screen.y) }, { random(0, 255), random(0, 255), random(0, 255), 255 });
    //}
    //graphics.Present();
    //SDL_Delay(5000);
    
    return 0;
}