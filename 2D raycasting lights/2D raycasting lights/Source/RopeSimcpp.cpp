#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Rope/Point.h"
#include "Rope/Stick.h"

#include <random>
#include <time.h>


//std::vector<sf::Vertex> walls;
float Distance(Point* p0, Point* p1)
{
	float dstX = p1->posX - p0->posX;
	float dsty = p1->posY - p0->posY;

	//Get the distance of the points.
	float distance = sqrt(dstX * dstX + dsty * dsty);
	return distance;
}


int main()
{

	float size = 800;
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML window");

	std::vector<Point*> points;
	Point* p0 = new Point(100, 150);
	Point* p1 = new Point(200, 100);
	points.push_back(p0);
	points.push_back(p1);

	Stick stick(p0, p1);


	window.setFramerateLimit(30);

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


		for (int i = 0; i < points.size(); i++)
		{
			points[i]->Update();
		}

		for (int i = 0; i < points.size(); i++)
		{
			//for (int j = 0; j < 5; j++)
			{
				points[i]->Constrain(size);
			}

		}
		for (int i = 0; i < 5; i++)
		{
			stick.Update();
		}


		// i hate this
		for (int i = 0; i < points.size(); i++)
		{
			Point* p = points[i];
			sf::CircleShape point;
			point.setPosition(p->posX, p->posY);
			point.setRadius(10);
			window.draw(point);
		}

		// i hate this pt. 2


		sf::VertexArray line(sf::LineStrip, 2);
		line[0].position = sf::Vector2f(stick.p0->posX + 10, stick.p0->posY + 10);
		line[1].position = sf::Vector2f(stick.p1->posX + 10, stick.p1->posY + 10);

		window.draw(line);



		//window.draw(walls.data(), walls.size(), sf::Lines);

		window.display();
	}
	return 0;
}