#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "Ray.h"
#include "..\Rope\Point.h";

#define PI 3.1415

class Light
{
private:
	std::vector<Ray> rays;
	std::vector<Ray>* instersections;

	sf::Vector2f position;
	float angleOffset;
	sf::Vector2f offSetPosition;

	bool isChild;
	Point* parent;
public:
	Light(sf::Vector2f position, sf::VertexArray& walls, Point* parent);
	Light(sf::Vector2f position, sf::VertexArray& walls, sf::Vector2f offSet, Point* parent);

	void UpdatePosition(sf::Vector2f position, sf::VertexArray& walls);
	void CastRays(sf::VertexArray& walls);
	void CreateRays(sf::VertexArray& walls);
	
	sf::Vector2f GetPosition();
	std::vector<Ray>* GetIntersections();

	double Distance(sf::Vector2f pointA, sf::Vector2f pointB);
};

