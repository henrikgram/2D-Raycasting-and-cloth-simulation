#pragma once
class Point
{
private:
	float prevX;
	float prevY;

	float bounce;
	float gravity;
	float friction;

	

public:
	Point(float posX, float posY, bool isLocked = false);
	~Point();

	void Update();
	void Constrain(float size);
	//TODO: make this get or set

	float posX;
	float posY;

	bool isLocked;
	bool isSelected = false;

};

