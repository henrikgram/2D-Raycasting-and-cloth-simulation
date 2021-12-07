#pragma once
#include "SFML/Graphics.hpp"
class Ray2
{
private:

	

public:
	Ray2(sf::Vector2f position, float angle);
	bool Cast(sf::Vector2f LineP1, sf::Vector2f lineP2);
	sf::Vector2f position;
	float angle;
	void Move(sf::Vector2f destination);
	sf::Vector2f intersection;
};

