#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "NewLight/Light.h"

#include <random>
#include <time.h>



sf::RenderWindow window(sf::VideoMode(800, 800), "SFML window");
std::vector<sf::Vertex> walls;

void GenerateRandomWalls(int amount)
{
	srand(time(NULL));

	for (int i = 0; i < amount; i++)
	{
		sf::Vertex a;
		a.position = sf::Vector2f(rand() % 800, rand() % 800);
		a.color = sf::Color::White;

		sf::Vertex b;
		b.position = sf::Vector2f(rand() % 800, rand() % 800);
		b.color = sf::Color::White;

		walls.push_back(a);
		walls.push_back(b);
	}
}

int main()
{
	//sf::Vertex line[2];

	GenerateRandomWalls(1);
	Light light(sf::Vector2f(400, 400), walls);

	
	
	while (window.isOpen())
	{
		window.clear();
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

		//light.UpdatePosition(worldPos);

		window.draw(walls.data(), walls.size(), sf::Lines);
		window.draw(light.rays.data(), light.rays.size(), sf::Lines);
	
		window.display();
	}
	return 0;
}