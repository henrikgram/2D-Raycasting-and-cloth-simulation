#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "NewLight/Light.h"
#include "Rope/Point.h"


#include <chrono>

#include <iostream>


#include <random>
#include <time.h>
#include "Rope/Stick.h"


int size = 800 - 10;
sf::RenderWindow window(sf::VideoMode(800, 1200), "SFML window");
sf::VertexArray walls(sf::Lines);
sf::VertexArray rays(sf::Lines);
sf::VertexArray lines(sf::Lines);

sf::VertexArray lightshape(sf::Triangles);
std::vector<Point*> points;
std::vector<Stick*> sticks;
std::vector<Light> lights;

sf::VertexArray raysNonInstersect(sf::Lines);

bool drawCone = true;
bool drawRays;
int FuzzyResolution = 4;

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

		walls.append(pointA);
		walls.append(pointB);
	}
}

void SetupBounds(int offset)
{

	sf::Vertex c;
	sf::Vertex d;

	sf::Vertex e;
	sf::Vertex f;

	sf::Vertex i;
	sf::Vertex j;

	sf::Vertex k;
	sf::Vertex l;

	c.position = sf::Vector2f(0 + offset, 0 + offset);
	d.position = sf::Vector2f(800 - offset, 0 + offset);

	e.position = sf::Vector2f(800 - offset, 0 + offset);
	f.position = sf::Vector2f(800 - offset, 800 - offset);

	i.position = sf::Vector2f(800 - offset, 800 - offset);
	j.position = sf::Vector2f(0 + offset, 800 - offset);

	k.position = sf::Vector2f(0 + offset, 800 - offset);
	l.position = sf::Vector2f(0 + offset, 0 + offset);


	walls.append(c);
	walls.append(d);

	walls.append(e);
	walls.append(f);

	walls.append(i);
	walls.append(j);

	walls.append(k);
	walls.append(l);

}

void SetupRope()
{

	for (int i = 0; i < 20; i++)
	{
		points.push_back(new Point(0 + 40 * i, 0));
	
	}

	points[0]->Lock();
	points[points.size()-1]->Lock();

	for (int i = 0; i < points.size()-1; i++)
	{
		sticks.push_back(new Stick(points[i], points[i + 1]));
	}

	int size = 50;
	int startX = 400;

	Point* p4 = new Point(startX, 0);

	Point* p5 = new Point(startX + size, -size);
	Point* p6 = new Point(startX + size * 2, -size * 2);
	Point* p7 = new Point(startX + size * 3, -size * 3);

	Point* p0 = new Point(startX + size * 4, -size * 4);
	Point* p1 = new Point(startX + size * 4, -size * 5);
	Point* p2 = new Point(startX + size * 5, -size * 5);
	Point* p3 = new Point(startX + size * 5, -size * 4);

	//Point* specialBoi = new Point(500, 400);
	sticks.push_back(new Stick(p4, points[9]));

	points.push_back(p0);
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);

	points.push_back(p4);
	points.push_back(p5);
	points.push_back(p6);
	points.push_back(p7);

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

	size = 50;
	startX = 600;

	Point* p12 = new Point(startX, 0);
	Point* p13 = new Point(startX + size, -size);
	Point* p14 = new Point(startX + size * 2, -size * 2);
	Point* p15 = new Point(startX + size * 3, -size * 3);

	sticks.push_back(new Stick(p12, points[12]));

	Point* p8 = new Point(startX + size * 4, -size * 4);
	Point* p9 = new Point(startX + size * 4, -size * 5);
	Point* p10 = new Point(startX + size * 5, -size * 5);
	Point* p11 = new Point(startX + size * 5, -size * 4);

	//Point* specialBoi = new Point(500, 400);
	
	points.push_back(p8);
	points.push_back(p9);
	points.push_back(p10);
	points.push_back(p11);

	points.push_back(p12);
	points.push_back(p13);
	points.push_back(p14);
	points.push_back(p15);

	Stick* stick9 = new Stick(p8, p9);
	Stick* stick10 = new Stick(p9, p10);
	Stick* stick11 = new Stick(p10, p11);
	Stick* stick12 = new Stick(p11, p8);
	Stick* stick13 = new Stick(p8, p10);

	Stick* stick14 = new Stick(p12, p13);
	Stick* stick15 = new Stick(p13, p14);
	Stick* stick16 = new Stick(p14, p15);
	Stick* stick17 = new Stick(p15, p8);

	sticks.push_back(stick9);
	sticks.push_back(stick10);
	sticks.push_back(stick11);
	sticks.push_back(stick12);
	sticks.push_back(stick13);

	sticks.push_back(stick14);
	sticks.push_back(stick15);
	sticks.push_back(stick16);
	sticks.push_back(stick17);


	size = 50;
	startX = 800;

	Point* p20 = new Point(startX, 0);
	Point* p21 = new Point(startX + size, -size);
	Point* p22 = new Point(startX + size * 2, -size * 2);
	Point* p23 = new Point(startX + size * 3, -size * 3);

	sticks.push_back(new Stick(p20, points[18]));

	Point* p16 = new Point(startX + size * 4, -size * 4);
	Point* p17 = new Point(startX + size * 4, -size * 5);
	Point* p18 = new Point(startX + size * 5, -size * 5);
	Point* p19 = new Point(startX + size * 5, -size * 4);

	//Point* specialBoi = new Point(500, 400);
	points.push_back(p16);
	points.push_back(p17);
	points.push_back(p18);
	points.push_back(p19);

	points.push_back(p20);
	points.push_back(p21);
	points.push_back(p22);
	points.push_back(p23);

	Stick* stick18= new Stick(p16, p17);
	Stick* stick19 = new Stick(p17, p18);
	Stick* stick20 = new Stick(p18, p19);
	Stick* stick21 = new Stick(p19, p16);
	Stick* stick22 = new Stick(p16, p18);

	Stick* stick23 = new Stick(p20, p21);
	Stick* stick24 = new Stick(p21, p22);
	Stick* stick25 = new Stick(p22, p23);
	Stick* stick26 = new Stick(p23, p16);

	sticks.push_back(stick18);
	sticks.push_back(stick19);
	sticks.push_back(stick20);
	sticks.push_back(stick21);
	sticks.push_back(stick22);

	sticks.push_back(stick23);
	sticks.push_back(stick24);
	sticks.push_back(stick25);
	sticks.push_back(stick26);

	lines.resize(sticks.size() * 2);

}

void DrawLight(Light& light)
{
	
	float alpha = 50;

	std::vector<Ray>* intersections = light.GetIntersections();

	for (int i = 0; i < intersections->size() - 1; i++)
	{
		sf::Vertex a = light.GetPosition();
		sf::Vertex b = intersections->at(i).GetIntersection();

		a.color = sf::Color::Yellow;
		b.color = sf::Color::Yellow;

		rays.append(a);
		rays.append(b);

		sf::Vertex c = light.GetPosition();
		c.color = sf::Color(255, 255, 255, alpha);

		sf::Vertex d = intersections->at(i).GetIntersection();
		d.color = sf::Color(255, 255, 255, alpha);

		sf::Vertex e = intersections->at(i+1).GetIntersection();
		e.color = sf::Color(255, 255, 255, alpha);

		lightshape.append(c);
		lightshape.append(d);
		lightshape.append(e);

	}

	sf::Vertex c = light.GetPosition();
	c.color = sf::Color(255, 255, 255, alpha);

	sf::Vertex d = intersections->at(intersections->size() - 1).GetIntersection();
	d.color = sf::Color(255, 255, 255, alpha);

	sf::Vertex e = intersections->begin()->GetIntersection();
	e.color = sf::Color(255, 255, 255, alpha);

	lightshape.append(c);
	lightshape.append(d);
	lightshape.append(e);
}

void DrawRope()
{

	// i hate this
	/*for (int i = 0; i < points.size(); i++)
	{
		Point* p = points[i];
		sf::CircleShape point;
		point.setFillColor(sf::Color::Black);
		point.setPosition(p->GetPosition().x, p->GetPosition().y);
		point.setRadius(2);

		if (p->IsLocked())
		{
			point.setFillColor(sf::Color::Red);
		}
		window.draw(point);
	}*/

	lines.clear();

	for (int i = 0; i < sticks.size(); i++)
	{
		sf::Vertex a;
		sf::Vertex b;
		a.color = sf::Color::Black;
		b.color = sf::Color::Black;
		a.position = sf::Vector2f(sticks[i]->GetPointA()->GetPosition().x + 2, sticks[i]->GetPointA()->GetPosition().y + 2);
		b.position = sf::Vector2f(sticks[i]->GetPointB()->GetPosition().x + 2, sticks[i]->GetPointB()->GetPosition().y + 2);

		lines.append(a);
		lines.append(b);

	}

	window.draw(lines);
}

void UpdateLights(sf::Vector2f worldPos)
{
	for (int i = 0; i < lights.size(); i++)
	{
		lights[i].UpdatePosition(worldPos, walls);
	}

	for (int i = 0; i < lights.size(); i++)
	{
		lights[i].CastRays(walls);
	}


	rays.clear();
	raysNonInstersect.clear();


	lightshape.clear();

	for (int i = 0; i < lights.size(); i++)
	{
		DrawLight(lights[i]);
	}


	if (drawCone)
	{
		window.draw(lightshape);
	}

}

void UpdateRope(sf::Vector2f pixelPos)
{



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


}

void SetupBoxes()
{
	int   height = 80;
	int offset = 400;
	walls.append(sf::Vector2f(114.16627,/*  /*  height -*/ 664.27052 + offset));
	walls.append(sf::Vector2f(339.50439,/*  /*  height -*/  696.61571 + offset));

	walls.append(sf::Vector2f(339.50439, /*  height -*/0696.61571 + offset));
	walls.append(sf::Vector2f(353.52064, /*  height -*/0583.40756 + offset));

	walls.append(sf::Vector2f(114.16627, /*  height -*/0664.27052 + offset));
	walls.append(sf::Vector2f(353.52064, /*  height -*/0583.40756 + offset));



	walls.append(sf::Vector2f(596.10953, /*  height -*/0547.82786 + offset));
	walls.append(sf::Vector2f(640.31461, /*  height -*/0548.90603 + offset));

	walls.append(sf::Vector2f(596.10953, /*  height -*/0547.82786 + offset));
	walls.append(sf::Vector2f(637.08009, /*  height -*/0376.39838 + offset));

	walls.append(sf::Vector2f(640.31461, /*  height -*/0548.90603 + offset));
	walls.append(sf::Vector2f(668.34711, /*  height -*/0368.85117 + offset));

	walls.append(sf::Vector2f(637.08009, /*  height -*/0376.39838 + offset));
	walls.append(sf::Vector2f(668.34711, /*  height -*/0368.85117 + offset));


	walls.append(sf::Vector2f(25.7561, /*  height -*/0394.72732 + offset));
	walls.append(sf::Vector2f(112.00993, /*  height -*/0334.34964 + offset));
	walls.append(sf::Vector2f(112.00993, /*  height -*/0334.34964 + offset));
	walls.append(sf::Vector2f(279.12672, /*  height -*/0414.13443 + offset));
	walls.append(sf::Vector2f(279.12672, /*  height -*/0414.13443 + offset));
	walls.append(sf::Vector2f(159.44953, /*  height -*/0188.79631 + offset));
	walls.append(sf::Vector2f(159.44953, /*  height -*/0188.79631 + offset));
	walls.append(sf::Vector2f(25.7561, /*  height -*/0394.72732 + offset));


	walls.append(sf::Vector2f(400, /*  height -*/0400 + offset));
	walls.append(sf::Vector2f(500, /*  height -*/0300 + offset));
	walls.append(sf::Vector2f(500, /*  height -*/0300 + offset));
	walls.append(sf::Vector2f(400, /*  height -*/0200 + offset));
	walls.append(sf::Vector2f(400, /*  height -*/0200 + offset));
	walls.append(sf::Vector2f(300, /*  height -*/0300 + offset));
	walls.append(sf::Vector2f(300, /*  height -*/0300 + offset));
	walls.append(sf::Vector2f(400, /*  height -*/0400 + offset));

	walls.append(sf::Vector2f(628.45471, /*  height -*/0151.06026 + offset));
	walls.append(sf::Vector2f(672.6598, /*  height -*/049.71201 + offset));

	walls.append(sf::Vector2f(672.6598, /*  height -*/049.71201 + offset));
	walls.append(sf::Vector2f(500, /*  height -*/0100 + offset));

	walls.append(sf::Vector2f(628.45471, /*  height -*/0151.06026 + offset));
	walls.append(sf::Vector2f(500, /*  height -*/0100 + offset));

}

int main()
{
	float cursorRadius = 20;
	SetupBounds(-500);
	SetupRope();
	SetupBoxes();

	//GenerateRandomWalls(5);
	//window.setFramerateLimit(60);
	//Light in the center
	Light light(sf::Vector2f(400, 400), walls, points[20]);

	lights.push_back(light);
	float radius = 10;

	//In a radius of 10, make a circle of lights

	for (float angle = 0; angle < PI * 2; angle += (PI * 2) / FuzzyResolution)
	{
		float dx = cos(angle) * radius;
		float dy = sin(angle) * radius;
		sf::Vector2f offsetPosition = sf::Vector2f(dx, dy);

		lights.push_back(Light(sf::Vector2f(light.GetPosition().x + dx, light.GetPosition().y + dy), walls, offsetPosition, points[20]));
	}

	Light light2(sf::Vector2f(400, 400), walls, points[29]);


	for (float angle = 0; angle < PI * 2; angle += (PI * 2) / FuzzyResolution)
	{
		float dx = cos(angle) * radius;
		float dy = sin(angle) * radius;
		sf::Vector2f offsetPosition = sf::Vector2f(dx, dy);

		lights.push_back(Light(sf::Vector2f(light2.GetPosition().x + dx, light2.GetPosition().y + dy), walls, offsetPosition, points[29]));
	}

	Light light3(sf::Vector2f(400, 400), walls, points[36]);


	for (float angle = 0; angle < PI * 2; angle += (PI * 2) / FuzzyResolution)
	{
		float dx = cos(angle) * radius;
		float dy = sin(angle) * radius;
		sf::Vector2f offsetPosition = sf::Vector2f(dx, dy);

		lights.push_back(Light(sf::Vector2f(light3.GetPosition().x + dx, light3.GetPosition().y + dy), walls, offsetPosition, points[36]));
	}


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
		window.draw(point);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{

			for (int i = 0; i < points.size(); i++)
			{

				if (point.getGlobalBounds().contains(points[i]->GetPosition().x, points[i]->GetPosition().y))
				{
					points[i]->Select();
				}
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
		{
			drawRays = !drawRays;
			//drawCone = !drawCone;
		}
		auto start = std::chrono::high_resolution_clock::now();

		UpdateRope(worldPos);
		UpdateLights(points[20]->GetPosition());

		DrawRope();

		window.draw(walls);

		if (drawRays)
		{
			window.draw(rays);
		}

		window.display();

		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		std::cout << "Time taken by Update(): " << duration.count() << " microseconds" << std::endl;
	}
	return 0;
}