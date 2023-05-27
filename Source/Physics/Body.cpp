#include "Body.h"
#include "../Physics/Shapes/Shape.h"
#include "../Physics/Shapes/CircleShape.h"
#include "Integrator.h"
#include "World.h"
#include "../Physics/Forces/GravityField.h"

void Body::ApplyForce(const glm::vec2& force)
{
	this->force += force;
}

void Body::Step(float dt)
{

	if (type != DYNAMIC) return;

	ApplyForce(-World::gravity * gravityScale * mass);

	Integrator::SemiImplicitEuler(*this, dt);
	ClearForce();
	velocity *= (1.0f / (1.0f + (damping * dt)));
}

void Body::Draw(Graphics* graphics)
{
	shape->Draw(graphics, position);
}

bool Body::Intersects(Body* body)
{
	glm::vec2 direction = position - body->position;
	float distance = glm::length(direction);
	float radius = dynamic_cast<CircleShape*>(shape)->radius + dynamic_cast<CircleShape*>(body->shape)->radius;
	return distance <= radius;
}
