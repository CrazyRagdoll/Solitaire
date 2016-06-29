#pragma once

#include <iostream>

class Game
{
public:
	Game();
	~Game();

	void run();

private:

	void initSystems();		//initalise the systems!
	void initShaders();		//initalise all of the shaders
	void gameLoop();		//The game loop which runs the game
	void processInput();	//Process all of the player inputs
	void drawGame();		//draw the background
	void drawObjects();		//draw the cards and buttons

};

