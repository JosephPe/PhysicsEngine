#pragma once

class Body;

class Joint
{
public:
	Joint(Body* bodyA, Body* bodyB, float stiffness, float restLenth = 0);

	void Step(float dt);
	void Draw(class Graphics* graphics);

private:
	float m_restLength{ 0 };
	float m_stiffness{ 0 };

protected:
	Body* m_bodyA{ nullptr };
	Body* m_bodyB{ nullptr };
};