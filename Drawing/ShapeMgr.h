#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector<DrawingShape*> shapeDrawn;
public:
	ShapeMgr()
	{
		
	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == ShapeEnum::CIRCLE)
		{
			Circle *newCircle;
			newCircle = new Circle(color, pos);
			shapeDrawn.push_back(newCircle);
		}
		else
		{
			shapeDrawn.push_back(new Square(color, pos));
		}
	}

	const vector<DrawingShape*>& getShapes()
	{
		return shapeDrawn;
	}

	void readTheFile(fstream& file) 
	{
		SaveShape shapein;
		while (file.read(reinterpret_cast<char*>(&shapein), sizeof(shapein)))
		{
			addShape(Vector2f(shapein.x, shapein.y), shapein.shapeDrawn, Color(shapein.color));
		}
	}

	void writeToFile(fstream& file) 
	{
		for (int i = 0; i < shapeDrawn.size(); i++) 
		{
			file.write(reinterpret_cast<char*>(&shapeDrawn[i]->getRecordInfo()), sizeof(SaveShape));
		}
	}
};
