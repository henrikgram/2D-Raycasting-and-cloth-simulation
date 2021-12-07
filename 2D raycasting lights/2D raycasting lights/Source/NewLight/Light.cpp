#include "Light.h"



Light::Light(sf::Vector2f position, std::vector<sf::Vertex>& walls)
{
	//TODO: this doesnt seem right
	this->walls = &walls;
	rays.reserve(walls.size() * 3);
	for (int i = 0; i < walls.size(); i ++)
	{
		float angle = atan2(walls[i].position.y - position.y, walls[i].position.x - position.x);

		rays.push_back(Ray2(position, angle + 0.0001f));
		rays.push_back(Ray2(position, angle));
		rays.push_back(Ray2(position, angle + 0.0001f));
	}

}

void Light::UpdatePosition(sf::Vector2f position)
{
	this->position = position;
	for (int i = 0; i < rays.size(); i += 2)
	{
		rays[i].Move(position);
	}
}

double Light::Distance(sf::Vector2f pointA, sf::Vector2f pointB)
{
	float dstX = pointB.x - pointA.x;
	float dsty = pointB.y - pointA.y;

	//Get the distance of the points.
	//float distance = 
	float test = dstX * dstX + dsty * dsty;
	//TODO: check overflow
	double distance = sqrt(test);

	return (float)distance;
}
