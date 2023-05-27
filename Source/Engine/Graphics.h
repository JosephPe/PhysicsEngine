#pragma once
#include "Primitives.h"
#include <glm/glm.hpp>

class Graphics
{
public:
	Graphics();
	~Graphics();

	void CreateWindow(const char* title, int width, int height, float size);
	void Clear();
	void Present();
	void SetColor(const glm::vec4& color);

	void DrawPoint(const glm::ivec2& point, const glm::vec4& color);
	void DrawCircle(const glm::ivec2& point, int radius, const glm::vec4& color);
	void DrawFilledCircle(const glm::ivec2& point, int radius, const glm::vec4& color);
	void DrawLine(const glm::ivec2& start, const glm::ivec2& end, const glm::vec4& color);

	glm::vec2 ScreenToWorld(const glm::ivec2& screen);
	glm::ivec2 WorldToScreen(const glm::vec2& world);
	int WorldToPixels(float world);

	const glm::vec2& GetWorldExtents() const { return m_extents; }

	static glm::ivec4 ConvertColor(const glm::vec4& color);

private:
	struct SDL_Window* m_window = nullptr;
	struct SDL_Renderer* m_renderer = nullptr;

	int m_width{ 0 };
	int m_height{ 0 };
	glm::vec2 m_extents{ 0 };
};