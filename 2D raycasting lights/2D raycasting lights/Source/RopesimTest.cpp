//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
//
//
//#include <random>
//#include <time.h>
//
//
//
//class Point2
//{
//public:
//	Point2(float x, float y)
//	{
//		this->x = x;
//		this->y = y;
//		oldx = x - 5;
//		oldy = y - 5;
//	}
//
//	float x; float y; float oldx; float oldy;
//	float bounce = 0.9f;
//	float gravity = 0.5f;
//	float friction = 0.999f;
//};
//
//float Distance(Point2* p0, Point2* p1)
//{
//	float dx = p1->x - p0->x,
//		dy = p1->y - p0->y;
//	return sqrt(dx * dx + dy * dy);
//}
//
//
//class Stick2
//{
//public:
//	Stick2(Point2* p0, Point2* p1)
//	{
//		this->p0 = p0;
//		this->p1 = p1;
//		length = Distance(p0, p1);
//	}
//
//
//	Point2* p0;
//	Point2* p1;
//	float length = 0;
//};
//
//
//std::vector<Point2*> points;
//std::vector<Stick2*> sticks;
//
//void UpdatePoints()
//{
//	for (int i = 0; i < points.size(); i++)
//	{
//		Point2* p = points[i];
//		float
//			vx = (p->x - p->oldx) * p->friction,
//			vy = (p->y - p->oldy) * p->friction;
//
//		p->oldx = p->x;
//		p->oldy = p->y;
//		p->x += vx;
//		p->y += vy;
//		p->y += p->gravity;
//	}
//}
//
//void ConstrainPoints()
//{
//	for (int i = 0; i < points.size(); i++)
//	{
//		Point2* p = points[i];
//		float vx = (p->x - p->oldx) * p->friction,
//			  vy = (p->y - p->oldy) * p->friction;
//
//		if (p->x > 800) {
//			p->x = 800;
//			p->oldx = p->x + vx * p->bounce;
//		}
//		else if (p->x < 0) {
//			p->x = 0;
//			p->oldx = p->x + vx * p->bounce;
//		}
//		if (p->y > 800) {
//			p->y = 800;
//			p->oldy = p->y + vy * p->bounce;
//		}
//		else if (p->y < 0) {
//			p->y = 0;
//			p->oldy = p->y + vy * p->bounce;
//		}
//	}
//}
//
//void UpdateSticks()
//{
//	for (int i = 0; i < sticks.size(); i++)
//	{
//		Stick2* s = sticks[i];
//		float dx = s->p1->x - s->p0->x,
//			dy = s->p1->y - s->p0->y,
//			distance = sqrt(dx * dx + dy * dy),
//			difference = s->length - distance,
//			percent = difference / distance / 2,
//			offsetX = dx * percent,
//			offsetY = dy * percent;
//
//		s->p0->x -= offsetX;
//		s->p0->y -= offsetY;
//		s->p1->x += offsetX;
//		s->p1->y += offsetY;
//	}
//}
//int main()
//{
//
//	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML wisndow");
//	Point2* p0 = new Point2(100, 100);
//	Point2* p1 = new Point2(200, 100);
//	Point2* p3 = new Point2(100, 200);
//	Point2* p2 = new Point2(200, 200);
//
//	points.push_back(p0);
//	points.push_back(p1);
//	points.push_back(p2);
//	points.push_back(p3);
//
//	Stick2* stick = new Stick2(p0, p1);
//	Stick2* stick2 = new Stick2(p1, p2);
//	Stick2* stick3 = new Stick2(p2, p3);
//	Stick2* stick4 = new Stick2(p3, p0);
//
//	sticks.push_back(stick);
//	sticks.push_back(stick2);
//	sticks.push_back(stick3);
//	sticks.push_back(stick4);
//
//	window.setFramerateLimit(30);
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
//
//		UpdatePoints();
//		
//		ConstrainPoints();
//		for (int i = 0; i < 5; i++)
//		{
//			UpdateSticks();
//		}
//
//		//stick.Update();
//
//		// i hate this
//		for (int i = 0; i < points.size(); i++)
//		{
//			Point2* p = points[i];
//			sf::CircleShape point;
//			point.setPosition(p->x, p->y);
//			point.setRadius(10);
//			window.draw(point);
//		}
//
//		 //i hate this pt. 2
//
//		for (int i = 0; i < sticks.size(); i++)
//		{
//			sf::VertexArray line(sf::LineStrip, 2);
//			line[0].position = sf::Vector2f(sticks[i]->p0->x + 10, sticks[i]->p0->y + 10);
//			line[1].position = sf::Vector2f(sticks[i]->p1->x + 10, sticks[i]->p1->y + 10);
//
//			window.draw(line);
//		}
//	
//
//
//
//		//window.draw(walls.data(), walls.size(), sf::Lines);
//
//		window.display();
//
//
//	}
//	return 0;
//}
