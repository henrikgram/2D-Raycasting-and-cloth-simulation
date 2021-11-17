#include "Light.h"


Light::Light(sf::Vector2f position, std::vector<sf::Vertex>& walls)
{
	//TODO: this doesnt seem right
	this->walls = &walls;

	rays.reserve(walls.size()*4);


	for (int i = 0; i < walls.size(); i++)
	{
		sf::Vertex p0;
		p0.position = sf::Vector2f(position.x, position.y);
		p0.color = sf::Color::Yellow;

		sf::Vertex p1;
		p1.position = walls[i].position;
		p1.color = sf::Color::Yellow;

		sf::Vertex c;
		c.position = sf::Vector2f(position.x, position.y);
		c.color = sf::Color::Yellow;

		sf::Vertex d;
		d.position = sf::Vector2f(walls[i].position.x, walls[i].position.y);
		d.color = sf::Color::Yellow;

		rays.push_back(p0);
		rays.push_back(p1);
		rays.push_back(c);
		rays.push_back(d);
	}

}

void Light::UpdatePosition(sf::Vector2f position)
{
	this->position = position;
	for (int i = 0; i < rays.size(); i+=2)
	{
		rays[i].position = position;

	}
}
