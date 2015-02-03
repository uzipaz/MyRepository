#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "entity.h"

class SpaceShip : public entity
{
public:
	//SpaceShip(point3D Position, float g, float ThrustFactor, float size);
	SpaceShip(point3D Position, float thrust, float HeadingChangeLimit, float length, float width);
	~SpaceShip();

	void init();
	void render();
	void NextFrameCalc(int DeltaTime);

	void setThrust(bool set);

	void SetIncrementHeadingFlag(bool state);
	void SetDecrementHeadingFlag(bool state);

	void resetPosition();

private:
	point3D position;
	vector velocity;
	vector acceleration;

	//float g;
	float thrust;

	float CurrentThrust;
	float CurrentHeading;

	float HeadingChangeLimit;

	float length;
	float width;

	bool FlagIncHeading;
	bool FlagDecHeading;
};


#endif