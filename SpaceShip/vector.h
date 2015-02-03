#ifndef VECTOR_H
#define VECTOR_H

class vector
{
public:
	vector();
	vector(float x, float y, float z);
	~vector();

	vector operator+(const vector& Other);
	vector operator-(const vector& Other);

	float x;
	float y;
	float z;
};

#endif