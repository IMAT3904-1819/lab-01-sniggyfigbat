// Lab_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cmath>


int main()
{
	srand(time(NULL));
	bool bExitApp = false;
	int iAllowedGuesses = 5;
	while (!bExitApp) {
		int iRandomNumber = (rand() % 100) + 1;
		int iRemainingGuesses = iAllowedGuesses;
		bool bFoundAnswer = false;
		std::cout << "A random number between 1 and 100 has been selected! Try to guess it!" << std::endl;
		for (; iRemainingGuesses > 0 && !bFoundAnswer && !bExitApp; iRemainingGuesses--) {
			std::string sGuessVariant = (iRemainingGuesses == 1) ? "guess" : "guesses";
			std::cout << "You have " << iRemainingGuesses << " " << sGuessVariant << " remaining..." << std::endl;
			
			int iCurrentGuess;
			std::cin >> iCurrentGuess;

			if (iCurrentGuess == iRandomNumber) {
				std::cout << "The number was indeed " << iRandomNumber << "!" << std::endl;
				bFoundAnswer = true;
			}
			else if (iCurrentGuess < iRandomNumber) {
				std::cout << "Nope! Too low!" << std::endl;
			}
			else if (iCurrentGuess > iRandomNumber) {
				std::cout << "Nope! Too high!" << std::endl;
			}
			else {
				std::cout << "Nope! Too incomprehensible!" << std::endl;
			}
		}

		if (!bExitApp) {
			if (bFoundAnswer) {
				int iGuessesMade = iAllowedGuesses - iRemainingGuesses;
				std::string sGuessVariant = (iGuessesMade == 1) ? "guess" : "guesses";
				std::cout << "You found the answer! And in only " << iGuessesMade << " " << sGuessVariant << "!" << std::endl;
				std::cout << "We'll make it harder, next time..." << std::endl;
				iAllowedGuesses--;
			}
			else {
				std::cout << "You failed to find the correct answer. Oh dear." << std::endl;
				std::cout << "We'll make it easier, next time..." << std::endl;
				iAllowedGuesses++;
			}

			std::cout << "Enter any old gibberish to continue to a new round." << std::endl;
			std::string temp;
			std::cin >> temp;
		}
	}
	
	return 0;
}

