#pragma once
#include "Test.h"

class ContactTests : public Test
{
public:
	void Initialize() override;
	void Run() override;

	void Update() override;
	// Inherited via Test
	virtual void FixedUpdate() override;
	virtual void Render() override;
private:
	class Body* m_user{ nullptr };
protected:

};