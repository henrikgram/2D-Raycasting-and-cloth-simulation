#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "LightSource.h"
#include "Ray.h"

class PointLight : public LightSource
{
public:

	PointLight(Vector2f position, int stepSize = 5);

	/// <summary>
	/// Returns lines from the positon of the light to the intersecting points.
	/// Used for debug
	/// </summary>
	/// <returns></returns>
	vector<VertexArray> GetRayLines() override;

	/// <summary>
	/// Constructs a lightcone out of triangles based on the intersectinng points, from the look function. 
	/// </summary>
	/// <returns></returns>
	vector<VertexArray> GetLightCone() override;

	/// <summary>
	/// Moves the lightsource to a position
	/// </summary>
	/// <param name="position"></param>
	void Move(Vector2f position) override;

};

