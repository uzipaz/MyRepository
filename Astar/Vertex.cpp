#include "Vertex.h"

Vertex::Vertex()
{
}

Vertex::~Vertex()
{
}

void Vertex::insertEdge(edge Edge)
{
	Edges.insert(Edge);
}

void Vertex::removeEdge(edge Edge)
{
	Edges.remove();
}

LinkedList<edge>& Vertex::getEdges()
{
	return Edges;
}