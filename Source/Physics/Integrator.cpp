#include "Integrator.h"

void Integrator::ExplicitEuler(Body& body, float dt)
{
	body.position = body.position + body.velocity * dt;
	body.velocity = body.velocity + (body.force / body.mass) * dt;
}

void Integrator::SemiImplicitEuler(Body& body, float dt)
{
	body.velocity = body.velocity + (body.force / body.mass) * dt;
	body.position = body.position + body.velocity * dt;
}
