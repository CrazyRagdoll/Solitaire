#include "Game.h"

Game::Game() 
{
	cout << "Welcome to my Solitaire Game!" << endl;
	//TODO: Add a save system, then add checks to see if a game is already in progress
	_gameState = GameState::MAIN_MENU; //But for now just set the game state to main menu
	//initalise the menu
	_menu.init();
}


Game::~Game()
{
}

void Game::run() //Seld explanitory
{
	cout << "Running the game..." << endl;
	initSystems();
	initShaders();

	//Checks which state the game is in and move to the appropriate process!
	checkGameState();
}

void Game::stop() //Shut down the program gracefully!
{
	cout << "Shutting down program gracefuly, hope you had fun!" << endl;
}

void Game::initSystems() //initalise the systems!
{
	cout << "Initalising systems..." << endl;
}

void Game::initShaders() //initalise all of the shaders
{
	cout << "Initalising shaders..." << endl;
}

void Game::menuLoop() //The menu loop which displays menu options 
{
	cout << "Starting Main Menu loop...\n" << endl;
	
	//Starting the menu loop
	while (_gameState == GameState::MAIN_MENU)
	{

		//Value used to read user input
		char _coolBeans;

		cout << "Hello and Welcome to my make shift Main Menu!\n";
		cout << "To continue please enter an appropriate value!\n";
		cout << "1: Start Game!" << endl;
		cout << "2: Contiune Game! (Not implemented)" << endl;
		cout << "3: Edit Settings! (Not implemented)" << endl;
		cout << "4: View Player Stats! (Not implemented)" << endl;
		cout << "5: View Credits! (haha)" << endl;
		cout << "6: Quit Game!" << endl;

		//Read in what the user types
		cin >> _coolBeans;
		//Pointer to the memory location of that user's input
		const char * _coolerBeans = &_coolBeans;

		//Point to the value stored in the memory location previously saved (ascii values of integers 1 = 49, 2 = 50, etc...)
		switch (*_coolerBeans)
		{
		case 49:
			_gameState = GameState::PLAY;
			break;
		case 50:
			//_gameState = GameState::PLAY;
			break;
		case 51:
			_menu.openSettings();
			break;
		case 52:
			_menu.openStatistics();
			break;
		case 53:
			_menu.openCredits();
			break;
		case 54:
			_gameState = GameState::EXIT;
			break;
		default:
			cout << "Fuck you, enter a correct value" << endl; //Bit rude...
			break;
		}

	}

	//Check the state of the game
	checkGameState();
}

void Game::gameLoop() //The game loop which runs the game
{
	cout << "Starting Game loop..." << endl;

	//Create a Vector of all of the Decks!
	createDeckList();

	//Starting the play loop
	while (_gameState == GameState::PLAY)
	{

	}

	//Check the state of the game
	checkGameState();
}

void Game::pauseLoop() //When the game is paused it displays the menu options
{
	cout << "Starting Pause loop..." << endl;

	//Starting the pause loop
	while (_gameState == GameState::PAUSED)
	{

	}

	//Check the state of the game
	checkGameState();
}

void Game::gameOverLoop() //When the game ends (GG) display stats etc...
{
	cout << "Starting Game Over loop..." << endl;

	//Starting the game over loop
	while (_gameState == GameState::GAME_OVER)
	{

	}

	//Check the state of the game
	checkGameState();
}

void Game::processInput() //Process all of the player inputs
{

}

void Game::checkGameState()	//Check the state of the game and change process accordingly
{
	cout << "Checking Game State: ";

	//A simple switch statement to deterimine which game loop to run.
	switch (_gameState)
	{
	case GameState::MAIN_MENU:
		cout << "MAIN_MENU..." << endl;
		menuLoop();
		break;
	case GameState::PLAY:
		cout << "PLAY..." << endl;
		gameLoop();
		break;
	case GameState::PAUSED:
		cout << "PAUSED..." << endl;
		pauseLoop();
		break;
	case GameState::GAME_OVER:
		cout << "GAME_OVER..." << endl;
		gameOverLoop();
		break;
	case GameState::EXIT:
		cout << "EXIT..." << endl;
		stop();
		break;
	default:
		cout << endl;
		cout << "Error: No correct gamestate, defaulted to main menu loop" << endl;
		menuLoop();
		break;
	}
}

void Game::drawBackground() //draw the background
{

}

void Game::drawMainMenu() //draw the main menu buttons
{

}

void Game::drawObjects() //draw the cards and buttons
{

}

void Game::createDeckList() //Creates a vector of decks to access them easily.
{
	//Create the vector full of "up" and "down" decks
	for (int i = 0; i < 8; i++)
	{
		_downDecks.emplace_back(i, "down");				// the first "down" deck is the main deck.
		if (i != 0) { _upDecks.emplace_back(i, "up"); } //this is the one that will be used to create
	}													//a list of cards.
	for (int i = 0; i < 4; i++)
	{
		_endDecks.emplace_back(i, "down");
	}

	//Update the main deck.
	_downDecks[0].generateDeck();

	//Randomise the main deck
	//_downDecks[0].randomiseDeck();

	//Display its cards
	_downDecks[0].displayDeck(0);

	//Update all of the "down" decks (1-8)
	for (int i = 1; i < 8; i++)
	{
		_downDecks[i].addFromDeck(_downDecks[0], i - 1);
		_downDecks[i].displayDeck(i);
		for (int j = 1; j < i; j++) { _downDecks[0]._deck.pop_back(); }
	}

	_downDecks[0].displayDeck(0);
}