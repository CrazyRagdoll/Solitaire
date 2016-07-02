#pragma once

#include "Menu.h"
#include "Deck.h"

//A set of strongly defined states which will determine the state of the game
enum class GameState {MAIN_MENU, PLAY, PAUSED, GAME_OVER, EXIT};

class Game
{
public:
	Game();
	~Game();

	void run();				//Start the program vigerously!
	void stop();			//Shut down the program gracefully!

	GameState _gameState;	//Boom, Strongly defined Enums!

private:

	void initSystems();		//initalise the systems!
	void initShaders();		//initalise all of the shaders

	void menuLoop();		//The menu loop which displays menu options 
	void gameLoop();		//The game loop which runs the game
	void pauseLoop();		//When the game is paused it displays the menu options
	void gameOverLoop();	//When the game ends (GG) display stats etc...

	void processInput();	//Process all of the player inputs
	void checkGameState();	//Check the state of the game and change process accordingly

	void drawBackground();	//draw the background
	void drawMainMenu();	//draw the main menu buttons
	void drawObjects();		//draw the cards and buttons

	Menu _menu;
	Deck _deck, _deck2, _deck3, _deck4, _deck5, _deck6, _deck7;
	vector<Deck> _decks;

	//Game Functions
	void createDeckList();	//Creates a vector of decks to access them easily.

};

