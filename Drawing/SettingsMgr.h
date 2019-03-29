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
	Color currentColor; // Stores the current selected color
	ShapeEnum currentShape; // Stores the current selected Shape
public:
	// Constructor
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		currentColor = startingColor;
		currentShape = startingShape;
	}

	// Returns the current color
	Color getCurColor()
	{
		return currentColor;  
	}

	//Sets the current Color
	void setCurrentColor(Color colorPassed)
	{
		currentColor = colorPassed;
	}

	// Returns the current shape
	ShapeEnum getCurShape()
	{
		return currentShape; 
	}

	// Set the current shape
	void setCurShape(ShapeEnum shapePassed)
	{
		currentShape = shapePassed;
	}

	// Reads the binary file to recall saved data
	void readTheFile(fstream& file) 
	{
		unsigned int savedColor;
		file.read(reinterpret_cast<char*>(&savedColor), sizeof(unsigned int));
		file.read(reinterpret_cast<char*>(&currentShape), sizeof(ShapeEnum));
		currentColor = Color(savedColor);
	}

	// Saves the new data to the file
	void writeToFile(fstream& file) 
	{
		unsigned int savedColor = currentColor.toInteger();
		file.write(reinterpret_cast<char*>(&savedColor), sizeof(unsigned int));
		file.write(reinterpret_cast<char*>(&currentShape), sizeof(ShapeEnum));
	}
};
