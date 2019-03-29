#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	Color currentColor;
	ShapeEnum currentShape;
public:
	// Constructor
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		currentColor = startingColor;
		currentShape = startingShape;
	}

	Color getCurColor()
	{
		return currentColor;  
	}

	void setCurrentColor(Color colorPassed)
	{
		currentColor = colorPassed;
	}

	ShapeEnum getCurShape()
	{
		return currentShape; 
	}

	void setCurShape(ShapeEnum shapePassed)
	{
		currentShape = shapePassed;
	}

	void readTheFile(fstream& file) 
	{
		unsigned int savedColor;
		file.read(reinterpret_cast<char*>(&savedColor), sizeof(unsigned int));
		file.read(reinterpret_cast<char*>(&currentShape), sizeof(ShapeEnum));
		currentColor = Color(savedColor);
	}

	void writeToFile(fstream& file) 
	{
		unsigned int savedColor = currentColor.toInteger();
		file.write(reinterpret_cast<char*>(&savedColor), sizeof(unsigned int));
		file.write(reinterpret_cast<char*>(&currentShape), sizeof(ShapeEnum));
	}
};
