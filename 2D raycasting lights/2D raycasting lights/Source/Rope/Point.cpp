#include "Point.h"
#include <random>
#include <time.h>

Point::Point(float posX, float posY, bool isLocked)
{
	this->posX = posX;
	this->posY = posY;
	this->isLocked = isLocked;

	prevX = posX + rand() % 20 - 10;
	prevY = posY  +rand() % 20 - 10;

	 bounce = 0.9f;
	 gravity = 0.5f;
	 friction = 0.999f;
}

Point::~Point()
{
}

void Point::Update()
{
	//Verlet integration
	if (isSelected)
	{
		isLocked = true;
	}
	if (!isLocked)
	{
		float velX = (posX - prevX) * friction;
		float velY = (posY - prevY) * friction;

		prevX = posX;
		prevY = posY;

		posX += velX;
		posY += velY;

		//add gravity
		posY += gravity;
	}

	

}

void Point::Constrain(float size)
{
	float velX = (posX - prevX) * friction;
	float velY = (posY - prevY) * friction;

	//When it reaches an edge it set the position inside the simulation.
	//by setting the prevX to be equal the position + the velocity, that will ensure it the velocity will change next frame to the opposite.
	if (posX > size)
	{
		posX = size;
		prevX = posX + velX * bounce;
	}
	else if (posX < 0)
	{
		posX = 0;
		prevX = posX + velX * bounce;
	}

	if (posY > size)
	{
		posY = size;
		prevY = posY + velY * bounce;
	}
	else if (posY < 0)
	{
		posY = 0;
		prevY = posY + velY * bounce;
	}

}
