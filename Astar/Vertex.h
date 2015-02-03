#ifndef VERTEX
#define VERTEX

#include "LinkedList.h"

struct edge
{
	int to;
	float cost;

	bool operator==(const edge& rhs) const
	{
		return (this->to == rhs.to) && (this->cost == rhs.cost);
	}
};

class Vertex
{
public:
	Vertex();
	~Vertex();

	void insertEdge(edge Edge);
	void removeEdge(edge Edge); // Incompatibility with LinkedList's remove() function

	LinkedList<edge>& getEdges();
private:
	LinkedList<edge> Edges;
};

#endif