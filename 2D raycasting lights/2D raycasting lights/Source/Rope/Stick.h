#pragma once
#include "Point.h"
#include <math.h>
class Stick
{
private:

	float length;
public:
	Stick(Point* p0, Point* p1);

	float Distance();

	Point* p0;
	Point* p1;

	void Update();


};

