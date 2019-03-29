#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed
struct SaveShape
{
	ShapeEnum shapeDrawn;
	float x, y;
	unsigned int color;
};

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
public:
	virtual void draw(RenderWindow& win) = 0;
	virtual SaveShape getRecordInfo() = 0;
};

// add Circle, Square classes below. These are derived from DrawingShape

class Circle : public DrawingShape
{
private:
	CircleShape circle;
	Vector2f pos;
	const int RADIUS = 10;
public:
	Circle(Color color, Vector2f pos)
	{
		circle.setPosition(pos);
		circle.setRadius(RADIUS);
		circle.setOutlineThickness(2);
		circle.setOutlineColor(color);
		circle.setFillColor(color);
	}
	void draw(RenderWindow& win)
	{
		win.draw(circle);
	}
	SaveShape getRecordInfo()
	{
		return { CIRCLE, circle.getPosition().x, circle.getPosition().y, circle.getFillColor().toInteger() };
	}
};


class Square : public DrawingShape
{
private:
	RectangleShape square;
public:
	Square(Color color, Vector2f pos)
	{
		square.setPosition(pos);
		square.setOutlineColor(color);
		square.setOutlineThickness(2);
		square.setSize(Vector2f(20,20));
		square.setFillColor(color);
	}

	void draw(RenderWindow& win)
	{
		win.draw(square);
	}

	SaveShape getRecordInfo()
	{
		return { SQUARE, square.getPosition().x, square.getPosition().y, square.getFillColor().toInteger() };
	}
};




