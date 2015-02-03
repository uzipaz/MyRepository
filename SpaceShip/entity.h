#ifndef ENTITY_H
#define ENTITY_H

#include "miscellaneous.h"
#include "vector.h"

#include <Windows.h>
#include <gl\GL.h>

#include <cmath>

class entity
{
public:
	virtual void init() = 0;
	virtual void render() = 0;
	virtual void NextFrameCalc(int DeltaTime) = 0;

private:
};

#endif