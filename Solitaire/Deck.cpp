#include "Deck.h"
#include <iostream>
#include <algorithm>


Deck::Deck(int id, string name)
{
	_deckId = id;
	_deckName = name;

	//Set the type of deck to up or down.
	if (name == "debug")
	{
		_deckType = DeckType::UP;
		_deckName = "Debug";
	}
	else if (name == "up") 
	{
		_deckType = DeckType::UP;
		_deckName = "Up";
	}
	else if (name == "end")
	{
		_deckType = DeckType::UP;
		_deckName = "End";
	}
	else 
	{
		_deckType = DeckType::DOWN;
		_deckName = "Down";
	}
}

Deck::~Deck()
{
}

void Deck::addCard(int a, int b)		//Add a specific card to a deck.
{
	_card.generateCard(a, b);
	_deck.emplace_back(_card);
}

void Deck::generateDeck() //Generate the deck from suits and cards
{
	cout << "Generating Deck..." << endl;
	for (int i = 1; i <= 4; i++)		//loop through the suits
	{
		for (int j = 1; j <= 13; j++)	//loop through the values
		{
			_card.generateCard(i, j);
			_deck.emplace_back(_card);
		}
	}
}

void Deck::randomiseDeck() //Randomise the deck
{
	cout << "Randomising Deck..." << endl;

	//52 cards in the deck x 4 so I thought 208 would be a good amount of shuffling.
	for (int i = 0; i < 208; i++)
	{
		//Swap the position of two random cards
		int randy = rand() % 52;
		int randyJr = rand() % 52;
		if (randyJr == randy && randyJr <= 0) { randyJr++; }	//Just incase they random
		if (randyJr == randy && randyJr >= 51) { randyJr--; }	//the same number
		std::swap(_deck[randy], _deck[randyJr]);
	}

}

//Debugging tool to display each card in the deck
void Deck::displayDeck()
{
	cout << "Displaying " << _deckName << " Deck " << _deckId << "..." << endl;
	for (int i = 0; i < _deck.size(); i++)
	{
		std::cout << "Card " << i+1 << ": The " << _deck[i].getCardValueName() << " of " << _deck[i].getCardSuitName() << "s." << std::endl;
	}
	if (_deck.size() == 0) cout << "Deck Empty." << endl;
}

//Move "num" amount of cards from the selected "deck" to the target _deck
void Deck::moveCardsFromDeck(Deck &deck, int num)
{
	vector<Deck> _tmpDeck;
	_tmpDeck.emplace_back(0, "debug");
	for (int i = 0; i < num; i++)
	{
		_card = deck._deck.back();
		_tmpDeck[0]._deck.emplace_back(_card);
		deck._deck.pop_back();
		_deck.emplace_back(_tmpDeck[0]._deck.back());
		_tmpDeck[0]._deck.pop_back();
	}
	_tmpDeck.clear();
}

void Deck::displayLastXCards(int x)		//Display the last X amount of cards in the deck
{
	cout << _deck.size() << endl;
	if (_deck.size() <= 0)
	{
		cout << "Deck Empty." << endl;
	}
	else if (_deck.size() <= x)
	{
		cout << "Displaying last " << _deck.size() << " cards in " << _deckName << " Deck " << _deckId << "..." << endl;
		for (int i = 0; i < _deck.size(); i++)
		{
			std::cout << "Card " << i+1 << ": The "
				<< _deck[i].getCardValueName() << " of "
				<< _deck[i].getCardSuitName() << "s." << std::endl;
		}
	}
	else if (_deck.size() >= x)
	{
		cout << "Displaying last " << x << " cards in " << _deckName << " Deck " << _deckId << "..." << endl;
		for (int i = 0; i < x; i++)
		{
			std::cout << "Card " << _deck.size() - x + i + 1 << ": The "
				<< _deck[_deck.size() - x + i].getCardValueName() << " of "
				<< _deck[_deck.size() - x + i].getCardSuitName() << "s." << std::endl;
		}
	}
}