#ifndef MISCELLANEOUS
#define MISCELLANEOUS

#include <cmath>

struct Point
{
    float x;
    float y;
};

template <typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T& a, T&b)
{
	if (a < b)
		return a;

	return b;
}

inline float getEuclideanDistance(Point& a, Point& b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

#endif
