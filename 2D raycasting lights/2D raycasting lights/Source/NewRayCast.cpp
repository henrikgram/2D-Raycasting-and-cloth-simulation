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
//		sf::Vertex pointA;
//		pointA.position = sf::Vector2f(rand() % 800, rand() % 800);
//		pointA.color = sf::Color::Red;
//
//		sf::Vertex pointB;
//		pointB.position = sf::Vector2f(rand() % 800, rand() % 800);
//		pointB.color = sf::Color::Blue;
//
//		walls.push_back(pointA);
//		walls.push_back(pointB);
//	}
//}
//
//int main()
//{
//
//	//GenerateRandomWalls(1);
//	sf::Vertex pointA;
//	pointA.position = sf::Vector2f(150, 200);
//	pointA.color = sf::Color::Red;
//
//	sf::Vertex pointB;
//	pointB.position = sf::Vector2f(300, 500);
//	pointB.color = sf::Color::Blue;
//
//	walls.push_back(pointA);
//	walls.push_back(pointB);
//
//	Light light(sf::Vector2f(400, 400), walls);
//
//	sf::VertexArray walls2 = sf::VertexArray(sf::LinesStrip,2);
//	walls2[0] = pointA;
//	walls2[1] = pointB;
//	light.rays2[0].Cast(&walls2);
//
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
//		//light.UpdatePosition(worldPos);
//
//		//window.draw(light.rays.data(), light.rays.size(), sf::Lines);
//
//		sf::VertexArray ray = sf::VertexArray(sf::Lines, 2);
//		ray[0].position = light.rays2[0].ray[0].position;
//		ray[1].position = sf::Vector2f(100,200);
//		ray[0].color = sf::Color::Green;
//		ray[1].color = sf::Color::Green;
//	
//
//		window.draw(walls.data(), walls.size(), sf::Lines);
//
//		window.draw(ray);
//
//		window.display();
//	}
//	return 0;
//}