#pragma once
#include "Point.h"
#include <math.h>
class Stick
{
private:

	float length;
	Point* pointA;
	Point* pointB;

public:
	Stick(Point* pointA, Point* pointB);
	Point* GetPointA() const;
	Point* GetPointB() const;

	float Distance();



	void Update();


};

