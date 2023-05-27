#include "GravityField.h"
#include "../World.h"
#include "../Body.h"

void GravityField::Apply(std::vector<class Body*> bodies)
{
	for (size_t i = 0; i < bodies.size() - 1; i++)
	{
		for (size_t j = i + 1; j < bodies.size(); j++)
		{
			Body* firstBody = bodies[i];
			Body* secondBody = bodies[j];

			glm::vec2 direction = firstBody->position - secondBody->position;

			float distance = glm::length(direction);
			if (distance == 0) continue;

			distance = glm::max(1.0f, distance);

			float force = m_strength *((firstBody->mass * secondBody->mass) / distance);

			glm::vec2 ndirection = glm::normalize(direction);
			firstBody->ApplyForce(ndirection * force);
			secondBody->ApplyForce(ndirection * force);
			// apply gravitational force
			//firstBody->ApplyForce({ 0, -m_strength });
			//secondBody->ApplyForce({ 0, -m_strength });
		}
	}
}
