//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
//#include "NewLight/Light.h"
//#include "Rope/Point.h"
//
//#include <random>
//#include <time.h>
//
//
//int size = 800-10;
//sf::RenderWindow window(sf::VideoMode(800, 800), "SFML window");
//std::vector<sf::Vertex> walls;
//
//void GenerateRandomWalls(int amount)
//{
//	srand(time(NULL));
//
//	for (int i = 0; i < amount; i++)
//	{
//		sf::Vertex p0;
//		p0.position = sf::Vector2f(rand() % 800, rand() % 800);
//		p0.color = sf::Color::White;
//
//		sf::Vertex p1;
//		p1.position = sf::Vector2f(rand() % 800, rand() % 800);
//		p1.color = sf::Color::White;
//
//		walls.push_back(p0);
//		walls.push_back(p1);
//	}
//}
//
//int main()
//{
//
//	GenerateRandomWalls(1);
//	Light light(sf::Vector2f(400, 400), walls);
//
//	while (window.isOpen())
//	{
//		window.clear();
//		// Process events
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			// Close window: exit
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
//		sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
//
//		light.UpdatePosition(worldPos);
//
//		window.draw(light.rays.data(), light.rays.size(), sf::Lines);
//
//	
//		window.draw(walls.data(), walls.size(), sf::Lines);
//
//		window.display();
//	}
//	return 0;
//}