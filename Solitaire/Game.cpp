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

	int _hello;

	//Starting the play loop
	while (_gameState == GameState::PLAY)
	{

		cin >> _hello;

		if (_hello == 0) {
			drawFromDeck();
		}
		else if (_hello == 1) {
			_downDecks[0]._deck.pop_back();

		}

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
		_upDecks.emplace_back(i, "up");					//this is the one that will be used to create
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
	_downDecks[0].displayDeck();

	//Update all of the Decks
	for (int i = 1; i < 8; i++)
	{
		for (int j = 1; j < 8; j++)
		{
			if (i == j)
			{
				_upDecks[i].addFromDeck(_downDecks[0], 1);
				_downDecks[0]._deck.pop_back();
			}
			if (i > j)
			{
				_downDecks[i].addFromDeck(_downDecks[0], 1);
				_downDecks[0]._deck.pop_back();
			}
		}
	}

	//Display all of the decks.
	for (int i = 0; i < _downDecks.size(); i++)
	{
		_downDecks[i].displayDeck();
	}
	for (int i = 0; i < _upDecks.size(); i++)
	{
		_upDecks[i].displayDeck();
	}

	_downDecks[0].displayDeck();
	_upDecks[0].displayDeck();
}

void Game::drawFromDeck()	//Draws the top 3 cards from the main deck pile
{
	int padding = 3;			//Need to pad the deck so you dont overdraw
	int flipSize = 0;

	//If there are no cards in the main deck you need to refill it for the next moves.
	cout << "Main deck size: " << _downDecks[0]._deck.size() << endl;
	cout << "Flip deck size: " << _upDecks[0]._deck.size() << endl;
	if (_downDecks[0]._deck.size() == 0)
	{
		flipSize = _upDecks[0]._deck.size();
		cout << "Refilling Deck... " << _upDecks[0]._deck.size() << " cards..." << endl;
		for (int i = 0; i < flipSize; i++)
		{
			_downDecks[0]._deck.emplace_back(_upDecks[0]._deck.back());
			_upDecks[0]._deck.pop_back();
		}
	}

	//Calculate the padding
	if (_downDecks[0]._deck.size() < 3)
	{
		cout << "Adding padding..." << endl;
		padding = _downDecks[0]._deck.size();
	}

	//draw the cards from the main deck and put them in the fipped cards deck.
	for (int i = 0; i < padding; i++) {
		_upDecks[0]._deck.emplace_back(_downDecks[0]._deck.back());
		_downDecks[0]._deck.pop_back();
	}

	//Display the last 3 cards in the deck.
	_upDecks[0].displayLastXCards(3);
	
	//Display the contents of the filpped deck.
	_upDecks[0].displayDeck();
}