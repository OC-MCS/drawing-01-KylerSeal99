#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed

class SettingsUI
{
private:
	const int RADIUS = 20;
	CircleShape redBtn;
	CircleShape greenBtn;
	CircleShape blueBtn;
	CircleShape circleBtn;
	RectangleShape sqrBtn;
	RectangleShape canvas;
	SettingsMgr *UIMgr;

public:
	SettingsUI(SettingsMgr *mgr)
	{
		UIMgr = mgr;
	}
	void handleMouseUp(Vector2f mouse)
	{
		if (redBtn.getGlobalBounds().contains(mouse))
		{
			UIMgr->setCurrentColor(Color::Red);
		}
		else if (greenBtn.getGlobalBounds().contains(mouse))
		{
			UIMgr->setCurrentColor(Color::Green);
		}
		else if (blueBtn.getGlobalBounds().contains(mouse))
		{
			UIMgr->setCurrentColor(Color::Blue);
		}

		if (circleBtn.getGlobalBounds().contains(mouse))
		{
			UIMgr->setCurShape(CIRCLE);
		}
		else if (sqrBtn.getGlobalBounds().contains(mouse))
		{
			UIMgr->setCurShape(SQUARE);
		}
			
	}

	void draw(RenderWindow& win)
	{
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		
		Text title("Drawing Color", font, 25);
		title.setPosition(30, 25);
		win.draw(title);

		// Red Button 

		Vector2f Rpos(100, 90);
		redBtn.setPosition(Rpos);
		redBtn.setRadius(RADIUS);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);
		win.draw(redBtn);

		// Green Button
		Vector2f Gpos(100, 150);
		greenBtn.setPosition(Gpos);
		greenBtn.setRadius(RADIUS);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);
		win.draw(greenBtn);

		// Blue Button
		Vector2f Bpos(100, 210);
		blueBtn.setPosition(Bpos);
		blueBtn.setRadius(RADIUS);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);
		win.draw(blueBtn);
		

		Text shapeSelection("Drawing Shape", font, 25);
		shapeSelection.setPosition(30, 275);
		win.draw(shapeSelection);
		
		// Circle Button
		Vector2f Cpos(100, 350);
		circleBtn.setPosition(Cpos);
		circleBtn.setRadius(RADIUS);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);
		win.draw(circleBtn);

		// Square Button
		Vector2f sqrPos(100, 410);
		sqrBtn.setPosition(sqrPos);
		sqrBtn.setOutlineColor(Color::White);
		sqrBtn.setOutlineThickness(2);
		sqrBtn.setSize(Vector2f(40, 40));
		win.draw(sqrBtn);
		
		// Fill button colors
		// Colors
		if (UIMgr->getCurColor() == Color::Red)
		{
			redBtn.setFillColor(Color::Red);
			blueBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
		}
		else if (UIMgr->getCurColor() == Color::Green)
		{
			greenBtn.setFillColor(Color::Green);
			blueBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Transparent);
		}
		else if (UIMgr->getCurColor() == Color::Blue)
		{
			blueBtn.setFillColor(Color::Blue);
			greenBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Transparent);
		}
		//Shapes
		if (UIMgr->getCurShape() == CIRCLE)
		{
			circleBtn.setFillColor(Color::White);
			sqrBtn.setFillColor(Color::Transparent);
		}
		else if (UIMgr->getCurShape() == SQUARE)
		{
			sqrBtn.setFillColor(Color::White);
			circleBtn.setFillColor(Color::Transparent);
		}
	}
	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}

};
