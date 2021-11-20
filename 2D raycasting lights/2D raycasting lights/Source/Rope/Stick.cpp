#include "Stick.h"


Stick::Stick(Point* pointA, Point* pointB)
{

	this->pointA = pointA;
	this->pointB = pointB;

	this->length = Distance();
}

Point* Stick::GetPointA() const
{
	return pointA;
}

Point* Stick::GetPointB() const
{
	return pointB;
}

float Stick::Distance()
{
	float dstX = pointB->GetPosition().x - pointA->GetPosition().x;
	float dsty = pointB->GetPosition().y - pointA->GetPosition().y;

	//Get the distance of the points.
	//float distance = 
	float test = dstX * dstX + dsty * dsty;
	//TODO: check overflow
	double distance = sqrt(test);
	return (float)distance;
}


void Stick::Update()
{
	float dstX = pointB->GetPosition().x - pointA->GetPosition().x;
	float dsty = pointB->GetPosition().y - pointA->GetPosition().y;

	//Get the distance of the points.
	float distance = Distance();//sqrt(dstX * dstX + dsty * dsty);


	//Get the difference relative to what the distance should be(stick length)
	//positive if too close
	//negative if too far away
	float difference = length - distance;

	//Get how many percent of the distance it should move.
	//Divided by two, so each point can move half of the distance
	float percent = difference / distance / 2;


	//the offset amount needed to return to the correct place
	float offsetX = dstX * percent;
	float offsetY = dsty * percent;

	if (!pointA->isLocked)
	{
		pointA->Move(-offsetX, -offsetY);
		/*pointA->posX -= offsetX;
		pointA->posY -= offsetY;*/
	}

	if (!pointB->isLocked)
	{
		pointB->Move(offsetX, offsetY);
	/*	pointB->posX += offsetX;
		pointB->posY += offsetY;*/

	}


}
