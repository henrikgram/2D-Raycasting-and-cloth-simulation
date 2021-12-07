#include "Ray2.h"

Ray2::Ray2(sf::Vector2f position, float angle)
{
	this->position = position;
	this->angle = angle;
}

bool Ray2::Cast(sf::Vector2f LineP1, sf::Vector2f lineP2)
{
	//Uses the folowing formula from wikipedia.
	//https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection

	//All values are saved as x1x2 etc.. to make it easier to follow the formula.
	float x1 = LineP1.x;
	float y1 = LineP1.y;

	float x2 = lineP2.x;
	float y2 = lineP2.y;

	float x3 = position.x;
	float y3 = position.y;

	//Convert the angle in radians to vector
	float x4 = position.x + cos(angle);
	float y4 = position.y + sin(angle);

	float denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

	//If the deniminator is 0, it meaans that the lines are parallel and will never collide. 
	if (denominator == 0)
	{
		return false;
	}

	float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
	float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denominator;

	//if there is intersection point return true
	//"The intersection point falls within the first line segment if 0.0 ≤ t ≤ 1.0,"
	//The reason u is only check for > 0 is that they ray is thought of an endless line. 
	//and it only needs to check if it intersects with t eventually, and not only between the to given points. 
	if (t > 0 && t < 1 && u > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Ray2::Move(sf::Vector2f destination)
{
	position = destination;
}

