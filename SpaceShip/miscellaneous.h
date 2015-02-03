#ifndef MISCELLANEOUS_H
#define MISCELLANEOUS_H

#include "vector.h"

struct point3D
{
	float x;
	float y;
	float z;

	point3D(float x = 0.0, float y = 0.0, float z = 0.0)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	point3D operator+(const vector& rhs)
	{
		return point3D(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	point3D operator-(const vector& rhs)
	{
		return point3D(x - rhs.x, y - rhs.y, z - rhs.z);
	}
};

#endif