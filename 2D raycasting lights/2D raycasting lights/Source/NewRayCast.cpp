#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "NewLight/Light.h"
#include "Rope/Point.h"

#include <random>
#include <time.h>


int size = 800-10;
sf::RenderWindow window(sf::VideoMode(800, 800), "SFML window");
std::vector<sf::Vertex> walls;

void GenerateRandomWalls(int amount)
{
	srand(time(NULL));

	for (int i = 0; i < amount; i++)
	{
		sf::Vertex pointA;
		pointA.position = sf::Vector2f(rand() % 800, rand() % 800);
		pointA.color = sf::Color::Red;

		sf::Vertex pointB;
		pointB.position = sf::Vector2f(rand() % 800, rand() % 800);
		pointB.color = sf::Color::Blue;

		walls.push_back(pointA);
		walls.push_back(pointB);
	}
}

//bool Intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
//{
//	//Uses the folowing formula from wikipedia.
//	//https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection
//
//	//All values are saved as x1x2 etc.. to make it easier to follow the formula.
//	//double x1 = p1.x;
//	//double y1 = p1.y;
//
//	//double x2 = p2.x;
//	//double y2 = p2.y;
//
//	//double x3 = p3.x;
//	//double y3 = p3.y;
//
//	//double x4 = p4.x;
//	//double y4 = p4.y;
//
//	double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
//
//	//If the deniminator is 0, it meaans that the lines are parallel and will never collide. 
//	if (denominator == 0)
//	{
//		return false;
//	}
//
//	double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
//	double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denominator;
//
//	//if there is intersection point return true
//	//"The intersection point falls within the first line segment if 0.0 ≤ t ≤ 1.0,"
//	//The reason u is only check for > 0 is that they ray is thought of an endless line. 
//	//and it only needs to check if it intersects with t eventually, and not only between the to given points. 
//	if (t > 0 && t < 1 && u > 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

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

	float t =  ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
	float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denominator;

	//if there is intersection point return true
	//"The intersection point falls within the first line segment if 0.0 ≤ t ≤ 1.0,"
	//The reason u is only check for > 0 is that they ray is thought of an endless line. 
	//and it only needs to check if it intersects with t eventually, and not only between the to given points. 
	if (t > 0 && t < 1 && u > 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{

	sf::VertexArray lines(sf::Lines, 2);

	GenerateRandomWalls(1);
	sf::Vertex a = walls[0];
	/*a.position = sf::Vector2f(693, 724);
	a.color = sf::Color::Red;*/

	sf::Vertex b = walls[1];
	//b.position = sf::Vector2f(742, 243);
	//b.color = sf::Color::Blue;

	sf::Vertex c;
	c.position = sf::Vector2f(400, 400);
	c.color = sf::Color::White;

	sf::Vertex d;
	d.position = a.position;

	sf::Vertex e;
	e.position = b.position;

	double angle = atan2(a.position.y - 400, a.position.x - 400);
	double dx = cos(angle);
	double dy = sin(angle);

	double rayx = 400 + dx;
	double rayy = 400 + dy;

	sf::Vertex f;
	f.position = c.position;
	f.color = sf::Color::Yellow;

	sf::Vertex g;
	g.position = sf::Vector2f(400 + dx * 1000, 400 + dy * 1000);
	g.color = sf::Color::Yellow;
	
	//Intersect(a.position, b.position, sf::Vector2f(400, 400), sf::Vector2f(rayx, rayy));
	Intersect(a.position,b.position,c.position,sf::Vector2f(400+dx,400+dy));

	 angle = atan2(a.position.y - 400, a.position.x - 400);
	 double newangle = angle - 0.0001;
	 dx = cos(newangle);
	 dy = sin(newangle);

	 rayx = 400 + dx;
	 rayy = 400 + dy;

	 sf::Vertex h;
	 h.position = c.position;
	 h.color = sf::Color::Magenta;

	 sf::Vertex i;
	 i.position = sf::Vector2f(400 + dx * 1000, 400 + dy * 1000);
	 i.color = sf::Color::Magenta;


	 Intersect(a.position, b.position, c.position, i.position);

	angle = atan2(a.position.y - 400, a.position.x - 400);
	newangle = angle + 0.0001;
	dx = cos(newangle);
	dy = sin(newangle);

	rayx = 400 + dx;
	rayy = 400 + dy;

	sf::Vertex j;
	j.position = c.position;
	j.color = sf::Color::Green;

	sf::Vertex k;
	k.position = sf::Vector2f(400 + dx * 1000, 400 + dy * 1000);
	k.color = sf::Color::Green;


	Intersect(a.position, b.position, c.position, sf::Vector2f(400 + dx, 400 + dy));

	//d.position = sf::Vector2f(c.position.x+dx*100, c.position.y + dy*100);
	//d.color = sf::Color::Yellow;

	lines.append(a);
	lines.append(b);

	lines.append(c);
	lines.append(d);

	lines.append(c);
	lines.append(e);

	lines.append(f);
	lines.append(g);

	lines.append(h);
	lines.append(i);

	lines.append(j);
	lines.append(k);



	//Light light(sf::Vector2f(400, 400), walls);

	//sf::VertexArray walls2 = sf::VertexArray(sf::LinesStrip,2);
	//walls2[0] = pointA;
	//walls2[1] = pointB;
	//light.rays2[0].Cast(&walls2);


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

		//window.draw(light.rays.data(), light.rays.size(), sf::Lines);

	/*	sf::VertexArray ray = sf::VertexArray(sf::Lines, 2);
		ray[0].position = light.rays2[0].ray[0].position;
		ray[1].position = sf::Vector2f(100,200);
		ray[0].color = sf::Color::Green;
		ray[1].color = sf::Color::Green;*/
	

		window.draw(lines);

	/*	window.draw(ray);*/

		window.display();
	}
	return 0;
}