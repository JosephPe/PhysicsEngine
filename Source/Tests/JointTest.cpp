#include "JointTest.h"
#include "../Physics/Shapes/CircleShape.h"
#include "../Physics/World.h"
#include "../Physics/Body.h"
#include "../Physics/Contraints/Joint.h"

#define SPRING_STIFFNESS 250
#define SPRING_LENGTH 50
#define BODY_DAMPING 10
#define CHAIN_SIZE 5
#define CHAIN

void JointTest::Initialize()
{
	Test::Initialize();

	m_anchor = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 400, 100 }, { 0, 0 });
	m_world->AddBody(m_anchor);

#if defined(CHAIN)
	// chain code
	auto prevBody = m_anchor;

	for (int i = 0; i < CHAIN_SIZE; i++)
	{
		auto body = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 400, 200 }, { 0, 0 });
		body->gravityScale = 250;
		body->damping = BODY_DAMPING;
		m_world->AddBody(body);

		auto joint = new Joint(prevBody, body, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint);

		prevBody = body;
	}
#else
	// grid code
	Body* prevA = nullptr;
	Body* prevB = nullptr;
	auto joint = nullptr;

	for (int i = 0; i < CHAIN_SIZE; i++)
	{
		auto bodyA = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 400, 200 }, { 0, 0 }, 1, Body::DYNAMIC);
		m_world->AddBody(bodyA);

		auto bodyB = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 600, 400 }, { 0, 0 }, 1, Body::DYNAMIC);
		m_world->AddBody(bodyB);

		auto joint = new Joint(bodyA, bodyB, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint);

		if (i == 0)
		{
			auto joint1 = new Joint(bodyA, m_anchor, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint1);

			auto joint2 = new Joint(bodyB, m_anchor, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint2);

		}
		else
		{
			auto joint3 = new Joint(bodyA, prevA, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint3);

			auto joint4 = new Joint(bodyB, prevB, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint4);

			auto joint5 = new Joint(bodyA, prevB, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint5);

			auto joint6 = new Joint(bodyB, prevA, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint6);

		}
		prevA = bodyA;
		prevB = bodyB;
	}

#endif	
	/*body = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 400, 200 }, { 0, 0 }, 1, Body::DYNAMIC);
	body->gravityScale = 250;
	body->damping = BODY_DAMPING;
	m_world->AddBody(body);

	joint = new Joint(body, prevBody, SPRING_STIFFNESS, SPRING_LENGTH);
	m_world->AddJoint(joint);*/
}

void JointTest::Update()
{
	Test::Update();
	m_anchor->position = m_graphics->ScreenToWorld(m_input->GetMousePosition());
}

void JointTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void JointTest::Render()
{
	m_world->Draw(m_graphics);
	m_graphics->DrawCircle(m_input->GetMousePosition(), 10, { randomf(), randomf(), randomf(), 1 });
}