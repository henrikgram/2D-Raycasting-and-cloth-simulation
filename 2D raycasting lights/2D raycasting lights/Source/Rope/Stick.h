#pragma once
#include "Point.h"
#include <math.h>
class Stick
{
private:

	float length;
	float maxStretch;

	Point* pointA;
	Point* pointB;

public:
	Stick(Point* pointA, Point* pointB);
	Stick(Point* pointA, Point* pointB, float distance);
	Point* GetPointA() const;
	Point* GetPointB() const;

	float Distance();

	bool isBroken;

	void Update();


};

