#pragma once
#include "SFML/Graphics.hpp"
#include <algorithm>
class Ray
{
private:

public:
	Ray(sf::Vector2f position, float angle);
	bool Cast(sf::Vector2f LineP1, sf::Vector2f lineP2);
	void Move(sf::Vector2f destination);
	bool hasIntersected;
	sf::Vector2f intersection;
	sf::Vector2f position;
	float angle;


	bool operator< (const Ray& other) const {
		return angle < other.angle;

	}
};

