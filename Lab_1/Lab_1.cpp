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

	// Purchasable upgrades.
	bool bGotWarm = false;
	int iWarmCost = 2;
	int iWarmRange = 5;

	bool bGotCold = false;
	int iColdCost = 2;
	int iColdRange = 15;

	bool bGotStartHint = false;
	int iStartHintCost = 2;

	int iAllowedGuesses = 5;
	int iWinPoints = 0;
	while (!bExitApp) {
		int iRandomNumber = (rand() % 100) + 1;
		int iRemainingGuesses = iAllowedGuesses;
		bool bFoundAnswer = false;
		std::cout << "A random number between 1 and 100 has been selected! Try to guess it!" << std::endl;

		if (bGotStartHint) {
			if (iRandomNumber > 66) { std::cout << "I picked a high one, this time!" << std::endl; }
			else if(iRandomNumber < 34) { std::cout << "I picked a low one, this time!" << std::endl; }
			else { std::cout << "This one's just somewhere in the middle..." << std::endl; }
		}

		for (; iRemainingGuesses > 0 && !bFoundAnswer && !bExitApp; iRemainingGuesses--) {
			std::string sGuessVariant = (iRemainingGuesses == 1) ? "guess" : "guesses";
			std::cout << std::endl << "You have " << iRemainingGuesses << " " << sGuessVariant << " remaining..." << std::endl;
			
			int iCurrentGuess;
			std::cin >> iCurrentGuess;

			if (iCurrentGuess == iRandomNumber) {
				std::cout << "The number was indeed " << iRandomNumber << "!" << std::endl;
				bFoundAnswer = true;
			}
			else if (iCurrentGuess < iRandomNumber) {
				if (bGotWarm && iRandomNumber - iCurrentGuess <= iWarmRange) { std::cout << "Ooh, nearly! Just a little too low!" << std::endl; }
				else if (bGotCold && iRandomNumber - iCurrentGuess > iColdRange) { std::cout << "Not even close! Waaay too low!" << std::endl; }
				else { std::cout << "Nope! Too low!" << std::endl; }
			}
			else if (iCurrentGuess > iRandomNumber) {
				if (bGotWarm && iCurrentGuess - iRandomNumber <= iWarmRange) { std::cout << "Ooh, nearly! Just a little too high!" << std::endl; }
				else if (bGotCold && iCurrentGuess - iRandomNumber > iColdRange) { std::cout << "Not even close! Waaay too high!" << std::endl; }
				else { std::cout << "Nope! Too high!" << std::endl; }
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
				iWinPoints++;
			}
			else {
				std::cout << "You failed to find the correct answer. Oh dear. It was " << iRandomNumber << ", by the way." << std::endl;
				std::cout << "We'll make it easier, next time..." << std::endl;
				iAllowedGuesses++;
			}

			std::string sWinPoints;
			if (iWinPoints == 0) { sWinPoints = "no win-points"; }
			else if (iWinPoints == 1) { sWinPoints = "1 win-point"; }
			else { sWinPoints = std::to_string(iWinPoints) + " win-points"; }
			std::cout << std::endl << "You have " << sWinPoints << " to spend on perks." << std::endl;
			bool bExitBuyLoop = false;
			while (!bExitBuyLoop) {
				if (bGotWarm && bGotCold && bGotStartHint) { std::cout << "You already own all available perks!" << std::endl; }
				if (!bGotWarm) { std::cout << "Enter 'nearby' to purchase the Warm perk for " << iWarmCost << " win-points." << std::endl; }
				if (!bGotCold) { std::cout << "Enter 'far' to purchase the Cold perk for " << iColdCost << " win-points." << std::endl; }
				if (!bGotStartHint) { std::cout << "Enter 'hint' to purchase the Starting Hint perk for " << iStartHintCost << " win-points." << std::endl; }
				std::cout << "Enter 'cont' to begin the next round." << std::endl;
				
				std::string inp;
				std::cin >> inp;
				
				if (inp == "nearby") {
					if (bGotWarm) { std::cout << "You already own that perk!" << std::endl; }
					else if (iWinPoints < iWarmCost) { std::cout << "You can't afford that perk!" << std::endl; }
					else {
						bGotWarm = true;
						iWinPoints -= iWarmCost;
						std::cout << "You have unlocked the Warm perk!" << std::endl;
					}
				}
				else if (inp == "far") {
					if (bGotCold) { std::cout << "You already own that perk!" << std::endl; }
					else if (iWinPoints < iColdCost) { std::cout << "You can't afford that perk!" << std::endl; }
					else {
						bGotCold = true;
						iWinPoints -= iColdCost;
						std::cout << "You have unlocked the Cold perk!" << std::endl;
					}
				}
				else if (inp == "hint") {
					if (bGotStartHint) { std::cout << "You already own that perk!" << std::endl; }
					else if (iWinPoints < iStartHintCost) { std::cout << "You can't afford that perk!" << std::endl; }
					else {
						bGotStartHint = true;
						iWinPoints -= iStartHintCost;
						std::cout << "You have unlocked the Starting Hint perk!" << std::endl;
					}
				}
				else if (inp == "cont") {
					bExitBuyLoop = true; std::cout << std::endl; }
				else { std::cout << "Sorry, I didn't understand that..." << std::endl; }
			}
		}
	}
	
	return 0;
}

