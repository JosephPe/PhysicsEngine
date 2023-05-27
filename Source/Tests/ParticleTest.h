#pragma once
#include "Test.h"

class ParticleTest : public Test
{
public:
	void Initialize() override;

	void Update() override;
	// Inherited via Test
	virtual void FixedUpdate() override;
	virtual void Render() override;
private:

protected:

};