#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
class Light
{
private:
	std::vector<sf::Vertex>* walls;
	sf::Vector2f position;
	//std::vector<sf::Vertex> rays;
public:
	Light(sf::Vector2f position, std::vector<sf::Vertex>& walls);
	std::vector<sf::Vertex> rays;

	void UpdatePosition(sf::Vector2f position);



};

