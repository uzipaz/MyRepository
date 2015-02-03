#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED

#include "obstacle.h"

class agent: public obstacle
{
public:

private:
    void moveTo(stack<Point2D> path);
};

#endif // AGENT_H_INCLUDED
