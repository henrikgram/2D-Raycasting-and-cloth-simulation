#include "Light.h"

Light::Light(sf::Vector2f position, sf::VertexArray& walls, Point* parent)
{
	this->position = position;
	rays.reserve(walls.getVertexCount() * 3);
	angleOffset = 0.0001f;

	instersections = new std::vector<Ray>;
	this->parent = parent;
	isChild = true;
}

Light::Light(sf::Vector2f position,sf::VertexArray& walls, sf::Vector2f offset, Point* parent)
{

	this->position = position;
	rays.reserve(walls.getVertexCount() * 3);
	angleOffset = 0.0001f;
	this->offSetPosition = offset;

	this->parent = parent;
	isChild = true;
	instersections = new std::vector<Ray>;

}

void Light::UpdatePosition(sf::Vector2f position, sf::VertexArray& walls)
{
	if (!isChild)
	{
		this->position = position + offSetPosition;
	}
	else
	{
		this->position = parent->GetPosition() + offSetPosition;;
	}


}

void Light::CastRays(sf::VertexArray& walls)
{
	instersections->clear();
	rays.clear();

	//TODO: this might not be optimal
	CreateRays(walls);


	for (int i = 0; i < rays.size(); i++)
	{
		sf::Vector2f closestIntersection(9999,9999);

		for (int j = 0; j < walls.getVertexCount(); j+=2)
		{
			if (rays[i].Cast(walls[j].position, walls[j+1].position))
			{
				float dstIntersection = Distance(position, rays[i].GetIntersection());
				rays[i].SetHasIntersected(true);

				if (dstIntersection < Distance(position, closestIntersection))
				{
					closestIntersection = rays[i].GetIntersection();
				}
			}
		}

		if (rays[i].GetHasIntersected())
		{
			rays[i].SetIntersection(closestIntersection);
			instersections->push_back(rays[i]);
		}
	}
}

void Light::CreateRays(sf::VertexArray& walls)
{
	rays.reserve(walls.getVertexCount() * 3);

	for (int i = 0; i < walls.getVertexCount(); i++)
	{
		float angle = atan2(walls[i].position.y - position.y, walls[i].position.x - position.x);

		rays.push_back(Ray(position, angle - angleOffset));
		rays.push_back(Ray(position, angle));
		rays.push_back(Ray(position, angle + angleOffset));
	}
}

sf::Vector2f Light::GetPosition()
{
	return position;
}

std::vector<Ray>* Light::GetIntersections()
{
	std::sort(instersections->begin(), instersections->end());

	return instersections;

}

double Light::Distance(sf::Vector2f pointA, sf::Vector2f pointB)
{
	float dstX = pointB.x - pointA.x;
	float dsty = pointB.y - pointA.y;

	//Get the distance of the points.
	//float distance = 
	float test = dstX * dstX + dsty * dsty;
	//TODO: check overflow
	double distance = sqrt(test);

	return (float)distance;
}


