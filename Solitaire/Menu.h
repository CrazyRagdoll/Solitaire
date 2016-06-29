#pragma once
class Menu
{
public:
	Menu(); //Constructor 
	~Menu(); //Deconstructor

private:

	void openMenu();
	void closeMenu();

	void init();			//Initalize the Menu (load & draw stuff etc...)

	void newGame();			//Creates a new game
	void continueGame();	//Continues from the previous game
	void openSettings();	//Opens the settings menu
	void openStatistics();	//Opens the player's statistics 
	void openCredits();		//Yeah...

};

