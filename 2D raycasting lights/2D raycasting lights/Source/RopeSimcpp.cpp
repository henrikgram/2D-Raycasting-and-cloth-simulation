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
	float cursorRadius = 20;
	float size = 800;
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML window");

	std::vector<Point*> points;
	Point* p0 = new Point(400, 400);
	Point* p1 = new Point(500, 400);
	Point* p3 = new Point(400, 500);
	Point* p2 = new Point(500, 500);

	Point* p4 = new Point(400, 0, true);
	Point* p5 = new Point(400, 100);
	Point* p6 = new Point(400, 200);
	Point* p7 = new Point(400, 300);

	//Point* specialBoi = new Point(500, 400);


	points.push_back(p0);
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);

	points.push_back(p4);
	points.push_back(p5);
	points.push_back(p6);
	points.push_back(p7);

	std::vector<Stick*> sticks;
	Stick* stick0 = new Stick(p0, p1);
	Stick* stick1 = new Stick(p1, p2);
	Stick* stick2 = new Stick(p2, p3);
	Stick* stick3 = new Stick(p3, p0);
	Stick* stick4 = new Stick(p0, p2);

	Stick* stick5 = new Stick(p4, p5);
	Stick* stick6 = new Stick(p5, p6);
	Stick* stick7 = new Stick(p6, p7);
	Stick* stick8 = new Stick(p7, p0);

	sticks.push_back(stick0);
	sticks.push_back(stick1);
	sticks.push_back(stick2);
	sticks.push_back(stick3);
	sticks.push_back(stick4);

	sticks.push_back(stick5);
	sticks.push_back(stick6);
	sticks.push_back(stick7);
	sticks.push_back(stick8);


	window.setFramerateLimit(60);

	while (window.isOpen())
	{


		window.clear();
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			switch (event.type)
			{
			case(sf::Event::Closed):
				window.close();
				break;
			case(sf::Event::MouseButtonReleased):
			{

				for (int i = 0; i < points.size(); i++)
				{
					points[i]->isSelected = false;
					
				}
				break;
			}
			default:
				break;
			}
		
		}



		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);


		sf::CircleShape point;
		point.setPosition(worldPos);
		point.setRadius(cursorRadius);
		window.draw(point);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			
			for (int i = 0; i < points.size(); i++)
			{
				
				if (point.getGlobalBounds().contains(points[i]->posX, points[i]->posY))
				{
					points[i]->isSelected = true;
				}
			}

		}




		for (int i = 0; i < points.size(); i++)
		{
			if (points[i]->isSelected)
			{
				points[i]->posX = pixelPos.x;
				points[i]->posY = pixelPos.y;

			}
			else
			{
				points[i]->Update();
			}

		}

		//Stabilizing the simulation
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < points.size(); i++)
			{
				points[i]->Constrain(size);
			}

			for (int i = 0; i < sticks.size(); i++)
			{
				sticks[i]->Update();
			}
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

		for (int i = 0; i < sticks.size(); i++)
		{
			sf::VertexArray line(sf::LineStrip, 2);
			line[0].position = sf::Vector2f(sticks[i]->p0->posX + 10, sticks[i]->p0->posY + 10);
			line[1].position = sf::Vector2f(sticks[i]->p1->posX + 10, sticks[i]->p1->posY + 10);

			window.draw(line);
		}





		//window.draw(walls.data(), walls.size(), sf::Lines);

		window.display();
	}
	return 0;
}