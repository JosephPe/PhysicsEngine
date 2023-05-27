#include "Graphics.h"
#include "Random.h"
#include <SDL.h>
#include <iostream>


Graphics::Graphics()
{
    SDL_Init(SDL_INIT_VIDEO);
}

Graphics::~Graphics()
{
    // Clean up and exit
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Graphics::CreateWindow(const char* title, int width, int height, float size)
{
    m_width = width;
    m_height = height;
    // The window pointer

    float ratio = (float)m_width / m_height;
    m_extents = glm::vec2{ size, size };

    // Create the window
    m_window = SDL_CreateWindow
    (
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    //Create the renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

void Graphics::Clear()
{
    SDL_RenderClear(m_renderer);
}

void Graphics::Present()
{
    //Update Screen
    SDL_RenderPresent(m_renderer);
}

void Graphics::SetColor(const glm::vec4& color)
{
    glm::ivec4 intColor = ConvertColor(color);

    SDL_SetRenderDrawColor(m_renderer, intColor.r, intColor.g, intColor.b, intColor.a);

}

glm::ivec4 Graphics::ConvertColor(const glm::vec4& color)
{
    glm::ivec4 intColor;
    intColor.r = (int)(color.r * 255);
    intColor.g = (int)(color.g * 255);
    intColor.b = (int)(color.b * 255);
    intColor.a = (int)(color.a * 255);

    return intColor;
}

void Graphics::DrawPoint(const glm::ivec2& point, const glm::vec4& color)
{
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderDrawPoint(m_renderer, point.x, point.y);
}

void Graphics::DrawCircle(const glm::ivec2& point, int radius, const glm::vec4& color)
{
    glm::ivec4 icolor = ConvertColor(color);
    circleRGBA(m_renderer, point.x, point.y, radius, icolor.r, icolor.g, icolor.b, icolor.a);
}

void Graphics::DrawFilledCircle(const glm::ivec2& point, int radius, const glm::vec4& color)
{
    glm::ivec4 icolor = ConvertColor(color);

    filledCircleRGBA(m_renderer, point.x, point.y, radius, icolor.r, icolor.g, icolor.b, icolor.a);
}

void Graphics::DrawLine(const glm::ivec2& start, const glm::ivec2& end, const glm::vec4& color)
{
    SetColor(color);

    SDL_RenderDrawLine(m_renderer, start.x, start.y, end.x, end.y);
}

glm::vec2 Graphics::ScreenToWorld(const glm::ivec2& screen)
{
    float x = screen.x / (float)m_width; // screen x (0 - 800) -> x (0 - 1)
    float y = (m_height - screen.y) / (float)m_height; // screen y (0 - 600) -> (0 - 1) flip

    glm::vec2 world;
    world.x = ((1 - x) * -m_extents.x) + (x * m_extents.x);
    world.y = ((1 - y) * -m_extents.y) + (y * m_extents.y);

    return world;
}

glm::ivec2 Graphics::WorldToScreen(const glm::vec2& world)
{
    float x = (world.x + m_extents.x) / (m_extents.x * 2); // world.x = 0 -> (0 + 6.66) / 13.33 -> 0.5
    float y = (world.y + m_extents.y) / (m_extents.y * 2); // world.y = 0 -> (0 + 5) / 10 = 0.5

    glm::vec2 screen;
    screen.x = x * m_width;
    screen.y = (1.0f - y) * m_height;

    return screen;
}

int Graphics::WorldToPixels(float world)
{
    return (int)(world * (m_height / (m_extents.y * 2)));
}