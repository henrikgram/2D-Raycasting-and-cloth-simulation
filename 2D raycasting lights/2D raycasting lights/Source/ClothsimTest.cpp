#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Rope/Point.h"
#include "Rope/Stick.h"

#include <random>
#include <time.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <algorithm>
#include<string>
#include <Windows.h>

////std::vector<sf::Vertex> walls;
float Distance(sf::Vector2f pointA, sf::Vector2f pointB)
{
	float dstX = pointB.x - pointA.x;
	float dsty = pointB.y - pointA.y;

	//Get the distance of the points.
	float distance = sqrt(dstX * dstX + dsty * dsty);
	return distance;
}

bool Intersect(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Vector2f p4)
{
	//Uses the folowing formula from wikipedia.
	//https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection

	//All values are saved as x1x2 etc.. to make it easier to follow the formula.
	float x1 = p1.x;
	float y1 = p1.y;

	float x2 = p2.x;
	float y2 = p2.y;

	float x3 = p3.x;
	float y3 = p3.y;

	float x4 = p4.x;
	float y4 = p4.y;

	float denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

	//If the deniminator is 0, it meaans that the lines are parallel and will never collide. 
	if (denominator == 0)
	{
		return false;
	}

	float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
	float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denominator;

	//if there is intersection point return true
	//"The intersection point falls within the first line segment if 0.0 ≤ t ≤ 1.0,"
	//The reason u is only check for > 0 is that they ray is thought of an endless line. 
	//and it only needs to check if it intersects with t eventually, and not only between the to given points. 
	if (t > 0 && t < 1 && u > 0 && u < 1)
	{

		return true;
	}
	else
	{
		return false;
	}
}

bool WithinRadius(sf::Vector2f pointA, sf::Vector2f pointB, float radius)
{
	float dstX = pointA.x - pointB.x;
	float dstY = pointA.y - pointB.y;
	float dst = sqrt(dstX * dstX + dstY * dstY);

	return dst < radius;
}

int Index(int x, int y, int width)
{
	return y * width + x;
}
int maisn()
{
	float cursorRadius = 20;
	float size = 800;
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML window");

	std::vector<Point*> points;
	sf::VertexArray lines(sf::Lines, 2);



	int offset = 200;

	int ClothWidth = 46;
	int clothHeight = 30;

	int spacing = 10;

	points.reserve(ClothWidth * clothHeight);

	for (int y = 0; y < clothHeight; y++)
	{
		for (int x = 0; x < ClothWidth; x++)
		{
			if (y == 0 /*&& x % 9 == 0*/ )
			{
				points.push_back(new Point(x * spacing + offset, y * spacing + offset,true));
			}
			else
			{
				points.push_back(new Point(x * spacing + offset, y * spacing + offset));
			}
		
		}
	}

	std::vector<Stick*> sticks;
	sticks.reserve(ClothWidth * ClothWidth);


	for (int y = 0; y < clothHeight; y++)
	{
		for (int x = 0; x < ClothWidth; x++)
		{
			if (Index(x+1,y, ClothWidth) < points.size() && x < ClothWidth-1)
			{
				sticks.push_back(new Stick(points[Index(x, y, ClothWidth)], points[Index(x + 1, y, ClothWidth)]));
			}

			if (Index(x, y + 1, ClothWidth) < points.size())
			{
				sticks.push_back(new Stick(points[Index(x, y, ClothWidth)], points[Index(x, y + 1, ClothWidth)]));
			}
		}
	}


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
					points[i]->DeSelect();

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
		point.setPosition(sf::Vector2f(worldPos.x - cursorRadius, worldPos.y - cursorRadius));
		point.setRadius(cursorRadius);
		//window.draw(point);

		sf::VertexArray line(sf::Lines, 2);
		line[0].position = sf::Vector2f(worldPos.x + cursorRadius/3, worldPos.y );
		line[1].position = sf::Vector2f(worldPos.x - cursorRadius/3, worldPos.y );
		window.draw(line);

		sf::VertexArray line2(sf::Lines, 2);
		line2[0].position = sf::Vector2f(worldPos.x , worldPos.y + cursorRadius / 3);
		line2[1].position = sf::Vector2f(worldPos.x, worldPos.y - cursorRadius / 3);
		window.draw(line2);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{

			for (int i = 0; i < points.size(); i++)
			{
				if (WithinRadius(points[i]->GetPosition(), worldPos, cursorRadius) && !points[i]->IsLocked())
				{
					points[i]->Select();
				}
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
		{

			for (int i = 0; i < sticks.size(); i++)
			{

				if (Intersect(line[0].position, line[1].position, sticks[i]->GetPointA()->GetPosition(), sticks[i]->GetPointB()->GetPosition()) ||
					Intersect(line2[0].position, line2[1].position, sticks[i]->GetPointA()->GetPosition(), sticks[i]->GetPointB()->GetPosition()))
				{
					sticks.erase(sticks.begin() + i);
				}

			}

		}

		auto start = std::chrono::high_resolution_clock::now();


		for (int i = 0; i < points.size(); i++)
		{
			if (points[i]->IsSelected())
			{
				points[i]->MoveTo(pixelPos.x, pixelPos.y);
				/*points[i]->GetPosition().x = pixelPos.x;
				points[i]->GetPosition().y = pixelPos.y;*/

			}
			else
			{
				points[i]->Update();
			}

		}


		//Stabilizing the simulation
		for (int j = 0; j < 5; j++)
		{
			for (int i = 0; i < points.size(); i++)
			{
				points[i]->Constrain(750);
			}

			for (int i = 0; i < sticks.size(); i++)
			{
				if (sticks[i]->isBroken)
				{
					sticks.erase(sticks.begin() + i);
				}
				else
				{
					sticks[i]->Update();
				}

			}
		}


		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		std::cout << "Time taken by Update(): " << duration.count() << " microseconds" << std::endl;




		//// i hate this
		//for (int i = 0; i < points.size(); i++)
		//{
		//	Point* p = points[i];
		//	sf::CircleShape point;
		//	point.setRadius(10);
		//	point.setPosition(p->GetPosition().x - point.getRadius()/2, p->GetPosition().y - point.getRadius() / 2);
		//	

		//	if (p->IsLocked())
		//	{
		//		point.setFillColor(sf::Color::Red);
		//	}
		//	window.draw(point);
		//}

		 //i hate this pt. 2


	/*	for (int i = 0; i < sticks.size(); i++)
		{
			sf::VertexArray line(sf::LineStrip, 2);
			line[0].position = sf::Vector2f(sticks[i]->GetPointA()->GetPosition().x + 1, sticks[i]->GetPointA()->GetPosition().y + 1);
			line[1].position = sf::Vector2f(sticks[i]->GetPointB()->GetPosition().x + 1, sticks[i]->GetPointB()->GetPosition().y + 1);

			window.draw(line);
		}*/

	

		//for (int y = 0; y < ClothWidth; y++)
		//{
		//	for (int x = 0; x < ClothWidth; x++)
		//	{
		//		/*if (Index(x + 1, y, ClothWidth) < sticks.size() && x < ClothWidth)
		//		{
		//			lines[Index(x, y, ClothWidth)].position     = sf::Vector2f(sticks[Index(x, y, ClothWidth)]->GetPointA()->GetPosition().x + 1, sticks[Index(x, y, ClothWidth)]->GetPointA()->GetPosition().y + 1);
		//			lines[Index(x + 1, y, ClothWidth)].position = sf::Vector2f(sticks[Index(x + 1, y, ClothWidth)]->GetPointB()->GetPosition().x + 1, sticks[Index(x + 1, y, ClothWidth)]->GetPointB()->GetPosition().y + 1);
		//		}*/

		//		if (Index(x, y + 1, ClothWidth) < sticks.size())
		//		{
		//			//lines.append(sf::Vector2f(sticks[Index(x, y, ClothWidth)]->GetPointA()->GetPosition().x + 1, sticks[Index(x, y, ClothWidth)]->GetPointA()->GetPosition().y + 1));
		//			lines.append(sf::Vector2f(sticks[Index(x, y, ClothWidth)]    ->GetPointA()->GetPosition().x + 1, 
		//									  sticks[Index(x, y + 1, ClothWidth)]->GetPointA()->GetPosition().y + 1));
		//		}
		//	}
		//}

		/*lines.resize(sticks.size() * 2);

		for (int i = 0; i < sticks.size(); i++)
		{
			lines[2 * i].position = sticks[i]->GetPointA()->GetPosition();
			lines[2 *i+1].position = sticks[i]->GetPointB()->GetPosition();
		}*/

		lines.resize(sticks.size() * 2);

		for (int i = 0; i < sticks.size(); i++)
		{
			lines[2 * i].position = sticks[i]->GetPointA()->GetPosition();
			lines[2 * i + 1].position = sticks[i]->GetPointB()->GetPosition();
		}


		window.draw(lines);


		//window.draw(walls.data(), walls.size(), sf::Lines);

		window.display();
	}
	return 0;
}