/**
*  Course: CMPS 2143 - OOP
*
*  Purpose: Homework 04
*		Using frameRate and frameCount, these two are designed to
*		slow down the rate at which the window is refreshed. The refresh is
*		evident when one of the rectangles in the grid turns red.
*
*  @author Collin Bachman
*  @version 1.1 10/5/2018
*  @github repo: https://github.com/CollBach94
*/


#include <SFML/Graphics.hpp>


using namespace sf;

struct golCell {
	bool isAlive;
	int neighborCount;
	RectangleShape Rect;
	int Width;
	int Height;

	golCell() {
		Width = 10;
		Height = 10;
		Rect.setSize(sf::Vector2f(Width, Height));
		Rect.setFillColor(Color::Green);
		Rect.setOutlineColor(Color::Black);
		Rect.setOutlineThickness(1);
	}

	void setCellPos(int x, int y) {
		Rect.setPosition(x*Width, y*Height);
	}

};

struct gameOfLife {
	int Width;
	int Height;
	int frameCount;			//Counts the current frame.
	int frameRate;			//When the screen should refresh
	RenderWindow Window;
	golCell** World;
	gameOfLife(int width, int height) {
		Width = width;
		Height = height;
		Window.create(VideoMode(Width, Height), "Game of Life");

		World = new golCell*[height];

		for (int i = 0; i<height; i++) {
			World[i] = new golCell[width];
			for (int j = 0; j<width; j++) {
				World[i][j].setCellPos(i, j);
			}
		}
	}

	void drawWorld() {
		Window.clear();
		for (int i = 0; i<Height; i++) {
			for (int j = 0; j<Width; j++) {
				Window.draw(World[i][j].Rect);
			}
		}
		Window.display();
	}
};

int main() {
	//these two values will be used to modify elements in the 2d Array
	//for purposes of Homework 4 only.
	int TestR = 0;		//Current Row Index
	int TestC = 0;		//Current Column Index
						
	gameOfLife Gol(200, 200);
	Gol.frameCount = 0;
	Gol.frameRate = 400000;	//Setting the requirements for how often 
							// the screen will refresh. 

	//NOTE: I had to set the frameRate really high in order to see any effect
	//on my computer. Change frameRate before running just in case.
							
	while (Gol.Window.isOpen())
	{
		Event event;
		while (Gol.Window.pollEvent(event))
		{
				if (event.type == Event::Closed) {
					Gol.Window.close();
				}
			}
		//Comparing frameCount to frameRate.
		//Update when these conditions are met.
		if (Gol.frameCount % Gol.frameRate == 0) {
			//For this homework only, change a cells color when prompted
			Gol.World[TestR++][TestC].Rect.setFillColor(Color::Red);
			Gol.drawWorld();
			//
			//Checks to see if the row count exceeds the width
			if (TestR >= 20) {
				TestR = 0;
				TestC++;
				//Checks to see if the column count exceeds the height
				if (TestC >= 20) {
					//The program will close once all squares are red.
					Gol.Window.close();
				}
			}
		}
		Gol.frameCount++;
	}
	return 0;
}
