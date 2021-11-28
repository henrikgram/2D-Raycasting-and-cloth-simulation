#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "Ray2.h"
class Light
{
private:
	std::vector<sf::Vertex>* walls;
	sf::Vector2f position;
	//std::vector<sf::Vertex> rays;
public:
	Light(sf::Vector2f position, std::vector<sf::Vertex>& walls);
	std::vector<sf::Vertex> rays;
	std::vector<Ray2> rays2;

	void UpdatePosition(sf::Vector2f position);
	
	double Distance(sf::Vector2f pointA, sf::Vector2f pointB);


};

