#include "CircleShape.h"
#include "../../Engine/Graphics.h"

void CircleShape::Draw(Graphics* graphics, const glm::vec2 position)
{
	graphics->DrawFilledCircle(graphics->WorldToScreen(position), (int)radius, color);
}
