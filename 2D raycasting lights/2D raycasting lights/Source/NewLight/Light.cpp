#include "Light.h"



Light::Light(sf::Vector2f position, std::vector<sf::Vertex>& walls)
{
	//TODO: this doesnt seem right
	this->walls = &walls;


	//	sf::Vertex pointA;
	//	pointA.position = sf::Vector2f(position.x, position.y);
	//	pointA.color = sf::Color::Yellow;

	//	sf::Vertex pointB;

	//	double angle = atan2(pointA.position.x - pointB.position.x, pointA.position.y - pointB.position.y);

	//	pointB.position.x = cos(angle) + walls[0].position.x;
	//	pointB.position.y = sin(angle) + walls[0].position.y;

	//	rays2.push_back(Ray2(position, angle));

	//rays.reserve(walls.size() * 4);


	for (int i = 0; i < walls.size(); i += 2)
	{


		sf::Vertex pointA;
		pointA.position = sf::Vector2f(position.x, position.y);
		pointA.color = sf::Color::Yellow;

		sf::Vertex pointB;

		double angle = atan2(pointA.position.x - walls[i].position.x, pointA.position.y -walls[i].position.y);
		double degrees = angle * 180 / 3.14;

		pointB.position.x = cos(angle) *40 + position.x;
		pointB.position.y = sin(angle) *40+ position.y;

		//sf::Vertex pointAA;
		//pointAA.position = sf::Vector2f(position.x, position.y);
		//pointAA.color = sf::Color::Yellow;

		//sf::Vertex pointBB;
		//pointBB.position = sf::Vector2f(angle + 0.00001f, angle + 0.00001f);
		//pointBB.color = sf::Color::Green;


		sf::Vertex c;
		c.position = sf::Vector2f(position.x, position.y);
		c.color = sf::Color::Yellow;

		sf::Vertex d;

		 angle = atan2(c.position.x - walls[i + 1].position.x, c.position.y - walls[i + 1].position.y);
		 degrees = angle * 180 / 3.14;

		d.position.x = cos(angle) + position.x;
		d.position.y = sin(angle) + position.y;

		rays.push_back(pointA);
		rays.push_back(pointB);

		rays.push_back(c);
		rays.push_back(d);

		//rays.push_back(pointAA);
		//rays.push_back(pointBB); */



		//rays.push_back(pointCC);
		//rays.push_back(pointDD);


	}

}

void Light::UpdatePosition(sf::Vector2f position)
{
	this->position = position;
	for (int i = 0; i < rays.size(); i += 2)
	{
		rays[i].position = position;

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
