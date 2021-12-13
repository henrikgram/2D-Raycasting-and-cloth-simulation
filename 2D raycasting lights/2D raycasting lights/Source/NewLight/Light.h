#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "Ray.h"

#define PI 3.1415

class Light
{
private:
	
public:
	Light(sf::Vector2f position, sf::VertexArray& walls);
	Light(sf::Vector2f position, sf::VertexArray& walls, sf::Vector2f offSet);
	std::vector<Ray> rays;
	std::vector<Ray> instersections;
	sf::Vector2f position;
	void UpdatePosition(sf::Vector2f position, sf::VertexArray& walls);
	void CastRays(sf::VertexArray& walls);
	void CreateRays(sf::VertexArray& walls);
	
	double Distance(sf::Vector2f pointA, sf::Vector2f pointB);
	float angleOffset;
	sf::Vector2f offSetPosition;

	
};

