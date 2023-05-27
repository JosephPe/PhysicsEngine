#pragma once
#include "Body.h"
#include <list>
#include <glm/glm.hpp>
#include <vector>


class World
{
public:
	~World();
	void Step(float dt);
	void Draw(class Graphics* graphics);
	void AddBody(Body* body);
	void RemoveBody(Body* body);

	void AddJoint(class Joint* joint);
	void RemoveJoint(class Joint* joint);

	void AddForceGenerator(class ForceGenerator* m_forceGenerator);

public:
	static glm::vec2 gravity;
private:
	std::list<Body*> m_bodies;
	std::list<class Joint*> m_joints;
	std::vector<class ForceGenerator*> m_forceGenerator;
};
