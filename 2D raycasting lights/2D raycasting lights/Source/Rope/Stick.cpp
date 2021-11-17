#include "Stick.h"


Stick::Stick(Point* p0, Point* p1)
{

	this->p0 = p0;
	this->p1 = p1;

	this->length = Distance();
}

float Stick::Distance()
{
	float dstX = p1->posX - p0->posX;
	float dsty = p1->posY - p0->posY;

	//Get the distance of the points.
	//float distance = 
	float test = dstX * dstX + dsty * dsty;
	//TODO: check overflow
	double distance = sqrt(test);
	return (float)distance;
}


void Stick::Update()
{
	float dstX = p1->posX - p0->posX;
	float dsty = p1->posY - p0->posY;

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

	p0->posX -= offsetX;
	p0->posY -= offsetY;

	p1->posX += offsetX;
	p1->posY += offsetY;


}
