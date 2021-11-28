#pragma once
#include "SFML/Graphics.hpp"
class Point
{
private:

	float posX;
	float posY;

	float prevX;
	float prevY;

	float bounce;
	float gravity;
	float friction;

	bool isLocked;
	bool isSelected;

public:
	Point(float posX, float posY, bool isLocked = false);
	~Point();

	void Update();
	void Constrain(float size);

	void Move(float moveX, float moveY);
	void MoveTo(float dstX, float dstY);

	sf::Vector2f GetPosition();

	//TODO: make this get or set
	void Lock();
	void UnLock();

	void Select();
	void DeSelect();

	bool IsLocked();
	bool IsSelected();


	
	

};

