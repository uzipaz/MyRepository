#include "vector.h"

vector::vector()
{
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}

vector::vector(float x = 0.0, float y = 0.0, float z = 0.0)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

vector::~vector()
{
}

vector vector::operator+(const vector& Other)
{
	return vector(x + Other.x, y + Other.y, z + Other.z);
}

vector vector::operator-(const vector& Other)
{
	return vector(x - Other.x, y - Other.y, z - Other.z);
}