#include "SpaceShip.h"

#include <iostream>

SpaceShip::SpaceShip(point3D position, float thrust, float HeadingChangeLimit, float length, float width)
{
	this->position = position;
	this->thrust = thrust;
	this->HeadingChangeLimit = HeadingChangeLimit;

	this->CurrentThrust = 0;
	this->CurrentHeading = 0;

	this->length = length;
	this->width = width;

	this->FlagDecHeading = false;
	this->FlagIncHeading = false;
}

SpaceShip::~SpaceShip()
{
}

void SpaceShip::setThrust(bool set)
{
	if (set)
		CurrentThrust = thrust;

	else CurrentThrust = 0.0;
}

void SpaceShip::SetIncrementHeadingFlag(bool state)
{
	FlagIncHeading = state;
}

void SpaceShip::SetDecrementHeadingFlag(bool state)
{
	FlagDecHeading = state;
}

void SpaceShip::resetPosition()
{
	position.x = 0;
	position.y = 0;
	position.z = 0;
}

void SpaceShip::init()
{
}

void SpaceShip::NextFrameCalc(int DeltaTime)
{
	if (FlagDecHeading)
	{
		CurrentHeading = CurrentHeading - HeadingChangeLimit * (DeltaTime / (float) 1000);

		if (CurrentHeading < 0.0)
			CurrentHeading = 360.0;
	}

	if (FlagIncHeading)
	{
		CurrentHeading = CurrentHeading + HeadingChangeLimit * (DeltaTime / (float) 1000);

		if (CurrentHeading > 360.0)
			CurrentHeading = 0.0;
	}

	float AccelerationMagnitude = (CurrentThrust) * (DeltaTime / (float) 1000);
	acceleration.x = AccelerationMagnitude * cos( (CurrentHeading * 3.14159265359f) / 180.0f );
	acceleration.y = AccelerationMagnitude * sin( (CurrentHeading * 3.14159265359f) / 180.0f );

	velocity = velocity + acceleration;	
	position = position + velocity;
}

void SpaceShip::render()
{
	glPushMatrix();

	glTranslatef(position.x, position.y, position.z);
	glRotatef(CurrentHeading, 0, 0, 1);

	glTranslatef(-length * 0.5f, 0, 0);
	glRotatef(-90.0, 0, 0, 1);

	glBegin(GL_LINE_LOOP);
		glVertex3f(0, 0, 0);
		glVertex3f(-width, 0, 0);

		glVertex3f(-width, 0, 0);
		glVertex3f(0, length, 0);

		glVertex3f(0, length, 0);
		glVertex3f(width, 0, 0);
	glEnd();

	glPopMatrix();
}