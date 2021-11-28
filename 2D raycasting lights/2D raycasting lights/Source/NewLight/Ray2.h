#pragma once
#include "SFML/Graphics.hpp"
class Ray2
{
public:
	Ray2(sf::Vector2f position, float angle);
	sf::Vector2f position;
	float angle;
	sf::VertexArray ray;

	bool Cast(sf::VertexArray* wall);
	sf::Vector2f intersection;
};

