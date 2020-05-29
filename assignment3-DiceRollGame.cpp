#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int dieRoll();
int humanTurn(int);
int computerTurn(int);

int main()
{
	int humanTotalScore = 0;
	int computerTotalScore = 0;

	// loop until someone scores at least 100
	do
	{
		humanTotalScore = humanTotalScore + humanTurn(humanTotalScore);
		// add the score from a new turn to the running total
		cout << "Your total score so far is " << humanTotalScore << "." << endl;

		if(humanTotalScore >= 100)
		{
			cout << "You win!";
			break;
		}

		computerTotalScore = computerTotalScore + computerTurn(computerTotalScore);
		// add the score from current turn to total
		cout << "The computer's total score so far is " << computerTotalScore << "." << endl;

		if(computerTotalScore >= 100)
		{
			cout << "Computer wins!";
			break;
		}
	}

	// keeps running while both players have a total score under 100
	while(humanTotalScore < 100 && computerTotalScore < 100);
	return 0;
	}

	// simulate rolling of die

	int dieRoll()
	{
		return(rand() % 6) + 1;
		// gives range of 0-5 with plus 1 to avoid 0 returns 1-6
	}

	int humanTurn(int humanTotalScore)
	{
		int thisTurnScore = 0;
		int score = 0;
		char rollOrHold;
		char rollDice;

		cout << "It's your turn!" << endl;

		// loop as long as user chooses Roll Again or a 1 ends the turn
		do
		{

			score = dieRoll(); //roll the die

			if(score == 1)
			{
				cout << "You rolled a 1. End of turn." << endl; // rolling 1 ends the user's turn
				break;
			}

			thisTurnScore = thisTurnScore + score; // total current score for user

			cout << "You rolled a " << score << "." << endl;
			cout << "Your score this round is: " << thisTurnScore << "." << endl;
			cout << "Press 'h' to hold or 'r' to roll again. " << endl;
			cin >> rollOrHold;
		}

		while(rollOrHold == 'r' || rollOrHold == 'R');

		if(rollOrHold == 'h' || rollOrHold == 'H')
			return thisTurnScore; // finish turn and return total current user score if hold is selected

		return 0;
	}

	int computerTurn(int computerTotalScore)
	{
		int thisTurnScore = 0;
		int score = 0;
		// loop to keep going as long as the CPU score for this turn is less than 20

		cout << "It's the computer's turn!" << endl;

		do
		{
			score = dieRoll(); // roll the die

			if(score == 1) // roll of 1 ends turn
			{
				cout << "The computer rolled a 1. End of turn." << endl;
				break;
			}

			thisTurnScore = thisTurnScore + score; // total current score for this turn for the computer
			cout << "The computer rolled a " << score << ". Score so far this turn is " << thisTurnScore << "." << endl;
		}

		while(thisTurnScore < 20);
		// finish turn and return total current score if the computer scored >= 20

		if(thisTurnScore >= 20) // The computer holds if score is >=20
		{
			cout << "CPU holds." << endl;
			return thisTurnScore;
		}

		return 0;
	}