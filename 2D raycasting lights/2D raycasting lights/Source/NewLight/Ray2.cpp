#include "Ray2.h"

Ray2::Ray2(sf::Vector2f position, float angle)
{
	this->position = position;
	this->angle = angle;

    ray = sf::VertexArray(sf::LinesStrip, 2);
	ray[0].position = position;
	ray[1].position = sf::Vector2f(100, 20/*position.x + cos(angle), position.y + sin(angle)*/);


}

bool Ray2::Cast(sf::VertexArray* wall)
{
    //Uses the folowing formula from wikipedia.
   //https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection

   //All values are saved as x1x2 etc.. to make it easier to follow the formula.
    float x1 = (*wall)[0].position.x;
    float y1 = (*wall)[0].position.y;

    float x2 = (*wall)[1].position.x;
    float y2 = (*wall)[1].position.y;

    float x3 = (ray)[0].position.x;
    float y3 = (ray)[0].position.y;

    float x4 = (ray)[1].position.x;
    float y4 = (ray)[1].position.y;

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
    if (t > 0 && t < 1 && u > 0)
    {
        intersection.x = x1 + t * (x2 - x1);
        intersection.y = y1 + t * (y2 - y1);

        return true;
    }
    else
    {
        return false;
    }
}
