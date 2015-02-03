#include <iostream>
using namespace std;

#include <fstream>
#include <sstream>
#include <ctime>
#include <cfloat>

#include "Vertex.h"
#include "PriorityQueue.h"
#include "miscellaneous.h"

//#define MAX_POS_INT_32BIT 2147483647

//const char* FILE_ADDRESS_DISTANCE_MATRIX = "distance matrix.txt";
//const char* FILE_ADDRESS_COORDINATES = "coordinates.txt";
const char* FILE_ADDRESS_DATA = "data.txt";
const char* FILE_ADDRESS_INFO = "info.txt";

int* getOptimalPath(Vertex Graph[], int size, int start, int goal)
{
    PriorityQueue<float> PQ;
    LinkedList<edge>* Edges;
    int current, next, i;
	float NewCost;

    float *CostSoFar = new float[size];
    for (i = 1; i < size; i++)
		CostSoFar[i] = FLT_MAX;
    CostSoFar[0] = 0.0;

    int* parent = new int[size];

    //PQ.insert(start, getEuclideanDistance(Coordinates[start], Coordinates[goal]));
    PQ.insert(start, 0);
    while (!PQ.isEmpty())
    {	
		//PQ.Print();
        current = PQ.remove();
        if (current == goal)
        {
            delete [] CostSoFar;
            return parent;
        }

        else
        {
            Edges = &Graph[current].getEdges();
            for (Edges->begin(); !Edges->end(); Edges->next())
            {
                next = Edges->getCurrent().to;
                NewCost = CostSoFar[current] + Edges->getCurrent().cost /*+ getEuclideanDistance(Coordinates[next], Coordinates[goal])*/;
                if (NewCost < CostSoFar[next])
                {
                    CostSoFar[next] = NewCost;
                    parent[next] = current;

                    PQ.insert(next, NewCost);
                }
            }
        }
    }

    delete [] CostSoFar;
    return NULL;
}

/*bool readFromFileDistanceMatrix(Vertex *Graph)
{
    ifstream source;
    source.open(FILE_ADDRESS_DISTANCE_MATRIX, ios::in);
    if (!source.is_open())
        return false;

    string line;
    int i, j;

    getline(source, line);
    istringstream in(line);
    edge e;

    for (i = 1; getline(source, line); i++)
    {
        istringstream in(line);
        for (j = 0; j < i; j++)
        {
            in >> e.cost;

            e.to = i;
            Graph[j].insertEdge(e);

            e.to = j;
            Graph[i].insertEdge(e);
        }
    }

	source.close();
    return true;
}

bool readFromFileCoordinates(Point *Coordinates)
{
    ifstream source;
    source.open(FILE_ADDRESS_COORDINATES, ios::in);
    if (!source.is_open())
        return false;

    string line;
    int i;

    for (i = 0 ;getline(source, line); i++)
    {
        istringstream in(line);
        in >> Coordinates[i].x;
        in >> Coordinates[i].y;
    }

	source.close();
    return true;
}*/

bool readFromFileData(Vertex *&Graph, int &size)
{
	ifstream source;
	source.open(FILE_ADDRESS_DATA, ios::in);
	if (!source.is_open())
		return false;

	int edges, i, j;
	edge e;

	string line;
	getline(source, line);
	istringstream in(line);

	in >> size;

	getline(source, line);
	in >> edges;

	Graph = new Vertex[size];
	for (; getline(source, line); )
	{
		istringstream in(line);
		in >> i;
		in >> j;
		in >> e.cost;

		e.to = j;
		Graph[i].insertEdge(e);
	}

	source.close();
	return true;
}

bool readFromFileInfo(int &start, int &goal)
{
	ifstream source;
	source.open(FILE_ADDRESS_INFO, ios::in);
	if (!source.is_open())
		return false;

	string line;
	getline(source, line);
	istringstream in(line);

	in >> start;
	in >> goal;

	source.close();
	return true;
}

int main()
{
 	int size = 0, start, goal, current;
	Vertex *Graph = NULL;
	//Point *Coordinates = NULL;

	if (readFromFileData(Graph, size) && readFromFileInfo(start, goal))
	{
		//Graph = new Vertex[size];
		//Coordinates = new Point[size];
		//if (readFromFileCoordinates(Coordinates) && readFromFileDistanceMatrix(Graph))
		//{
			cout << "Executing algorithm\n";
			clock_t t = clock();
			//int* path = getOptimalPath(Graph, Coordinates, size, start, goal);
			int* path = getOptimalPath(Graph, size, start, goal);
			t = clock() - t;

			current = goal;
			cout << current << " ";
			while (current != start)
			{
				current = path[current];
				cout << current << " ";
			}

			cout << "\nThe approx. clock cycles taken by the algorithm are " << t << '\n';
			delete [] path;
		//}

		/*else
		{
			cout << "Unable to read input data\n";
		}*/
	}

    else cout << "Unable to read input data\n";

       /* LinkedList<edge> *Edges;
        int i;
        for (i = 0; i < size; i++)
        {
            Edges = &Graph[i].getEdges();
            for (Edges->begin(); !Edges->end(); Edges->next())
            {
                cout << Edges->getCurrent().cost << " ";
            }

            cout << '\n';
        }*/

    if (Graph != NULL)
		delete [] Graph;

	//if (Coordinates != NULL)
		//delete [] Coordinates;

    cin.get();
    return 0;
}
