#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "casino.h" // Casino Header File

// Jordan Guada
// COP3223-C
// Assignment 6 [11/14/2020]

void welcomeScreen()
{
	printf("+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + \n");
	printf("\n");
	printf("                                               KNIGHTS CASINO\n                                                            \n");
	printf("+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + \n");
}

int displayMenu()
{
	int select;

	do
	{
		printf("< Select your game by typing it's corresponding number! > \n");
		printf("+ + + + + + + + + + + + + + +\n");
		printf("1 - Slots\n");
		printf("2 - Scratch\n");
		printf("3 - Blackjack\n");
		printf("4 - Quit\n");
		scanf("%d", &select);

	} while (select < SLOTS || select > EXIT); // Updated the while loop to condition the new option.

	return select;

}

void clearScreen()
{
	printf("\n");
	printf("                                         <Press ENTER to continue>\n                                                            \n");
	// The screenmover is the ENTER button.
	char screenMover;
	scanf("%c", &screenMover);

	// Windows Clearscreen
	system("cls");

	// Unix Clear Screen
	//system("clear");

}

int playSlots(int cash)
{
	// Constant integers for payouts.
	const BET_AMOUNT = 5;
	const MATCH_TWO = 5;
	const MATCH_THREE = 50;

	//Loop Control
	int play = 1;

	// Declare our variables for symbols.
	char symOne, symTwo, symThree;

	//  Our game instructions.
	printf("#####[KNIGHTS CASINO]#####\n");
	printf("\n");
	printf("Let's play slots! Are you lucky enough to win?\n");
	printf("-------------------------------------\n");
	printf("Your cash balance is %d & the bet is %d.\n", cash, BET_AMOUNT);
	printf("\n");
	printf("Match two symbols to win $%d.\n", MATCH_TWO);
	printf("\n");
	printf("Match all three symbols to win $%d.\n", MATCH_THREE);
	printf("-------------------------------------\n");

	// If the player does not have enough cash to play the game we'll need to set the play variable to 0.
	if (cash <= BET_AMOUNT) {
		printf("You're out of cash, sorry!\n");
		// We now set play to 0.
		play = 0;
	}

	while (play != 0) {

		// I put the information for the actual game in the while loop, since we'll only start playing and feeling lucky if we have money.

		cash -= BET_AMOUNT;
		printf("\n");
		printf("           Spinning        \n");
		printf("-------------------------------------\n");
		printf("\n");
		symOne = randomSymbol();
		symTwo = randomSymbol();
		symThree = randomSymbol();
		printf("\n");
		printf("             %c | %c | %c                       \n ", symOne, symTwo, symThree);
		printf("\n");
		printf("-------------------------------------\n");

		if ((symOne == symTwo) && (symOne == symThree) && (symTwo == symThree))
		{
			cash += MATCH_THREE;
			printf("\n");
			printf("Three symbols matched!");
			printf("\n");
			printf("You've won $%d\n", MATCH_THREE);
			printf("\n");
			printf("Your cashout is: $%d\n", cash);
		}

		else if ((symOne == symTwo) || (symTwo == symThree) || (symThree == symOne))
		{
			cash += MATCH_TWO;
			printf("\n");
			printf("Two symbols matched!");
			printf("\n");
			printf("You've won $%d!\n", MATCH_TWO);
			printf("\n");
			printf("Your cashout is: $%d\n", cash);

		}
		else
		{
			cash += 0;
			printf("\n");
			printf("You've won nothing!\n");
			printf("\n");
			printf("Your cashout is: $%d\n", cash);
		}

		// If our cash is still more than $5, we need to prompt the user to play again.
		if (cash >= BET_AMOUNT) {
			printf("\n");
			printf("-------------------------------------\n");
			printf("Would you like to play again? [1 FOR YES // 0 FOR NO]\n");
			scanf("%d", &play);
		}
		else
		{
			break;
		}

	}

	// If you decide to leave the casino this will be shown.
	printf("-------------------------------------\n");
	printf("Thank you for playing at Knights Casino!\n");
	printf("\n");
	printf("Your cashout is: $%d. See you back again soon.\n", cash);

	return cash;
}

char randomSymbol()
{
	const int SYMBOLS = 6;
	// We need to make an array for our symbols.
	const char symbols[6] = { '$', '%', '&', '#', '@', '!' };
	char symbol;
	int num;

	num = rand() % 6;

	// Switch statement that takes in the random number that we created above and then return a symbol based on that random number from our array also above.

	switch (num)
	{
	case (0):
		return symbol = symbols[0];
		break;

	case (1):
		return symbol = symbols[1];
		break;

	case (2):
		return symbol = symbols[2];
		break;

	case (3):
		return symbol = symbols[3];
		break;

	case (4):
		return symbol = symbols[4];
		break;

	case (5):
		return symbol = symbols[5];
		break;

		return symbol;
	}
}

int playScratchOffs(cash)
{

	int type;
	int count;
	int c;


	OneDollar oneSO;
	TwoDollar twoSO;
	FiveDollar fiveSO;

	int zerovalue = 0;
	int play = 1; // 4a
	// I had to initalize 0 values in the oneSO, twoSO, and fiveSO or else I would get the error: C4700 uninitalized local variable 'oneSO" used.
	// This is because uninitialized variables can contain any value, and their use leads to undefined behavior so my compiler forced me to do this.
	oneSO.numbers[0] = zerovalue;
	twoSO.numbers[0] = zerovalue;
	fiveSO.numbers[0] = zerovalue;

	printf("Let's play scratch off tickets!\n");
	printf("\n");
	printf("Prizes can select from One Dollar, Two Dollar, and Five Dollar tickets\n");
	printf("\n");
	printf("Prizes are based on the ticket selected!\n");

	printf("\n"); // New Line for spacing reasons.

	while (play == 1)
	{
		printf("What type of scratch off would you like?\n");
		printf("[1] $1 Card | [2] $2 Card | [5] $5 Card\n");

		scanf("%d", &type);

		printf("How many scratch offs would you like of this kind?\n");

		scanf("%d", &count);

		printf("Grabbing your Scratch Offs...\n");

		for (c = 0; c < count; ++c)
		{

			switch (type)
			{
				// 1
			case ONE:
				if (cash >= type)
				{
					cash -= type;
					oneSO = createScratchOffOne(oneSO);
					displayScratchOffOne(oneSO);
					cash += cashOneDollar(oneSO);
				}
				else
				{
					printf("You're out of cash!\n");
					c = count;
				}

				break;

				// 2
			case TWO:
				if (cash >= type)
				{
					cash -= type;
					twoSO = createScratchOffTwo(twoSO);
					displayScratchOffTwo(twoSO);
					cash += cashTwoDollar(twoSO);
				}
				else
				{
					printf("You're out of cash!\n");
					c = count;
				}

				break;

				// 3
			case FIVE:
				if (cash >= type)
				{
					cash -= type;
					fiveSO = createScratchOffFive(fiveSO);
					displayScratchOffFive(fiveSO);
					cash += cashFiveDollar(fiveSO);
				}
				else
				{
					printf("You're out of cash!\n");
					c = count;
				}

				break;

			}
		}

		printf("Your cashout is: $%d!\n", cash);
		printf("Would you like to play another Scratch-Off?\n");
		printf("[0] - NO | [1] YES :: ");
		scanf("%d", &play);


	}

	return cash;
}


OneDollar createScratchOffOne(OneDollar oneSO)
{
	const int SYMS = 2;
	const int NUMS = 5;
	const int BASE = 20;

	const char SYMBOLS[6] = { '$', '%', '&', '#', '@', '!' };

	int usedSyms[6] = { 0, 0, 0, 0, 0,  0 };
	int used = 0;

	int sym;
	int n;

	oneSO.winNumber = (rand() % BASE) + 1;

	for (n = 0; n < NUMS; ++n)
	{
		oneSO.numbers[n] = (rand() % BASE) + 1;
	}

	for (n = 0; n < NUMS; ++n)
	{
		oneSO.prizes[n] = (float)((rand() % 100) + 5);
	}

	for (n = 0; n < SYMS; ++n)
	{
		used = 0; // 0 is false, 1 is true.
		while (used == 0)
		{
			sym = rand() % (sizeof(SYMBOLS) / sizeof(SYMBOLS[0]));

			if (usedSyms[sym] == 0)
			{
				usedSyms[sym] = 1;
				used = 1;
				break;
			}
		}

		switch (sym)
		{
		case 0:
			oneSO.bonus[n] = SYMBOLS[0];
			break;
		case 1:
			oneSO.bonus[n] = SYMBOLS[1];
			break;
		case 2:
			oneSO.bonus[n] = SYMBOLS[2];
			break;
		case 3:
			oneSO.bonus[n] = SYMBOLS[3];
			break;
		case 4:
			oneSO.bonus[n] = SYMBOLS[4];
			break;
		case 5:
			oneSO.bonus[n] = SYMBOLS[5];
			break;

		}

	}

	return oneSO;
}

void displayScratchOffOne(OneDollar oneSO)
{
	// Our constant values for the function in regards to looping and ceilings.
	const int SYMS = 2;
	const int NUMS = 5;

	// Loop Variable
	int i;

	printf("+%42s+\n", "--------------------------------------------------");
	printf("| WINNING NUMBER %10s %d", " ", oneSO.winNumber);

	if (oneSO.winNumber < 10)
	{
		printf("%23s\n", "|");
	}
	else
	{
		printf("%22s\n", "|");
	}

	printf("|%50s|\n", " ");

	printf("| YOUR NUMBERS %37s\n", "|");
	printf("|%10s", " ");

	//
	for (i = 0; i < NUMS; ++i)
	{
		printf("%d   ", oneSO.numbers[i]);

		// When I hits the last number in the counter, it'll print what we need for the console.
		if (i == 4)
		{
			printf("\t %11s", "|");
		}
	}

	printf("\n");

	printf("| PRIZES %43s\n", "|");
	printf("| %10s", " ");

	for (i = 0; i < NUMS; ++i)
	{
		printf("%.2lf %1s", oneSO.prizes[i], " ");

	}

	printf("\t %3s\n", "|");
	printf("| %50s\n", "|");

	printf("| SYMBOLS %42s\n", "|");
	printf("| %10s", " ");

	for (i = 0; i < SYMS; ++i)
	{
		printf("%c %3s", oneSO.bonus[i], " ");
	}

	printf("\t %27s \n", "|");
	printf("| %50s\n", "|");

	printf("+%42s+\n", "--------------------------------------------------");

}

TwoDollar createScratchOffTwo(TwoDollar twoSO)
{
	const int SYMS = 2;
	const int NUMS = 10;
	const int BASE = 30;

	const char SYMBOLS[6] = { '$', '%', '&', '#', '@', '!' };
	//2a
	int usedSyms[6] = { 0, 0, 0, 0, 0, 0 };
	//2b
	int usedNums[2] = { 0, 0 };
	//2c
	int num;
	//2d
	int used;

	int sym;
	int n;

	// For loop to generate the 2 winning numbers in the range 1-30.
	for (n = 0; n < SYMS; ++n)
	{
		used = 0; // 0 is false, 1 is true.
		while (used == 0)
		{
			num = (rand() % BASE + 1);


			//Algo to check numbers and make sure numbers are not the same.
			if (usedNums[n] == 0)
			{
				usedNums[n] = 1;

				if (n == 1)
				{

					twoSO.winNumbers[n] = (rand() % BASE + 1);

					while (twoSO.winNumbers[n] == twoSO.winNumbers[0])
					{
						twoSO.winNumbers[n] = (rand() % BASE + 1);
						break;
					}
				}
				else
				{
					twoSO.winNumbers[n] = num;
				}

				used = 1;
			}


			break;
		}
		//twoSO.winNumbers[n] = (rand() % BASE + 1);
	}

	// For loop to generate the players numbers. We need 10.
	for (n = 0; n < NUMS; ++n)
	{
		twoSO.numbers[n] = (rand() % BASE + 1);
	}

	// For loop to generate the prizes. We need 10.
	for (n = 0; n < NUMS; ++n)
	{
		twoSO.prizes[n] = (float)(rand() % 150 + 5);
	}


	for (n = 0; n < SYMS; ++n)
	{
		used = 0; // 0 is false, 1 is true.
		while (used == 0)
		{
			sym = rand() % (sizeof(SYMBOLS) / sizeof(SYMBOLS[0]));

			if (usedSyms[sym] == 0)
			{
				usedSyms[sym] = 1;
				used = 1;
				break;
			}
		}

		switch (sym)
		{
		case 0:
			twoSO.bonus[n] = SYMBOLS[0];
			break;
		case 1:
			twoSO.bonus[n] = SYMBOLS[1];
			break;
		case 2:
			twoSO.bonus[n] = SYMBOLS[2];
			break;
		case 3:
			twoSO.bonus[n] = SYMBOLS[3];
			break;
		case 4:
			twoSO.bonus[n] = SYMBOLS[4];
			break;
		case 5:
			twoSO.bonus[n] = SYMBOLS[5];
			break;

		}
	}

	return twoSO;
}

void displayScratchOffTwo(TwoDollar twoSO)
{
	const int SYMS = 2;
	const int NUMS = 10;
	const int BREAK = 4;

	int i;

	printf("+%42s+\n", "--------------------------------------------------");
	printf("| WINNING NUMBERS %7s", " ");
	for (i = 0; i < SYMS; ++i)
	{
		printf("%d    ", twoSO.winNumbers[i]);
	}

	if (twoSO.winNumbers[0] < 10)
	{
		printf("%15s\n", "|");
	}
	else
	{
		printf("%16s\n", "|");
	}

	printf("|%50s|\n", " ");

	printf("| YOUR NUMBERS %37s\n", "|");
	printf("|%7s", " ");

	for (i = 0; i < NUMS; ++i)
	{
		printf("%d  ", twoSO.numbers[i]);
	}

	printf("\t %2s|", " ");

	printf("\n");

	printf("| PRIZES %43s\n", "|");
	printf("| %7s", " ");

	for (i = 0; i < NUMS; ++i)
	{
		if (i == 5)
		{
			printf("\n| %7s", " ");
		}

		printf("%.2lf %1s", twoSO.prizes[i], " ");

	}

	printf("\t %3s\n", "|");
	printf("| %50s\n", "|");

	printf("| SYMBOLS %42s\n", "|");
	printf("| %10s", " ");

	for (i = 0; i < SYMS; ++i)
	{
		printf("%c %3s", twoSO.bonus[i], " ");
	}

	printf("\t %27s \n", "|");
	printf("| %50s\n", "|");

	printf("+%42s+\n", "--------------------------------------------------");



}

FiveDollar createScratchOffFive(FiveDollar fiveSO)
{
	const int SYMS = 4;
	const int NUMS = 12;
	const int BASE = 50;

	const char SYMBOLS[8] = { '$', '%', '&', '#', '@', '!', '^', '*' };
	int usedSyms[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int usedNums[4] = { 0, 0 };

	int num;
	int used = 0;

	int sym;
	int n;

	// For loop to generate the 4 winning numbers in the range 1-50.
	for (n = 0; n < SYMS; ++n)
	{
		used = 0;

		while (used == 0)
		{
			usedNums[n] = 1;
			num = rand() % BASE + 1;

			if (n == 1)
			{
				fiveSO.winNumbers[n] = (rand() % BASE + 1);

				while (fiveSO.winNumbers[n] == fiveSO.winNumbers[0])
				{
					fiveSO.winNumbers[n] = (rand() % BASE + 1);
					break;
				}
			}
			else if (n == 2)
			{
				fiveSO.winNumbers[n] = (rand() % BASE + 1);

				while (fiveSO.winNumbers[n] == fiveSO.winNumbers[0] || (fiveSO.winNumbers[n] == fiveSO.winNumbers[1]))
				{
					fiveSO.winNumbers[n] = (rand() % BASE + 1);
					break;
				}
			}
			else if (n == 3)
			{
				fiveSO.winNumbers[n] = (rand() % BASE + 1);

				while ((fiveSO.winNumbers[n] == fiveSO.winNumbers[0]) || (fiveSO.winNumbers[n] == fiveSO.winNumbers[1]) || (fiveSO.winNumbers[n] == fiveSO.winNumbers[2]))
				{
					fiveSO.winNumbers[n] = (rand() % BASE + 1);
					break;
				}
			}
			else
			{
				fiveSO.winNumbers[n] = num;
			}

			used = 1;
		}

	}

	// For loop to generate the players numbers. We need 12.
	for (n = 0; n < NUMS; ++n)
	{
		fiveSO.numbers[n] = rand() % BASE + 1;
	}

	// For loop to generate the prizes. We need 12.
	for (n = 0; n < NUMS; ++n)
	{
		fiveSO.prizes[n] = (float)(rand() % 250 + 5);
	}


	for (n = 0; n < SYMS; ++n)
	{
		used = 0; // 0 is false, 1 is true.
		while (used == 0)
		{
			sym = rand() % (sizeof(SYMBOLS) / sizeof(SYMBOLS[0]));

			if (usedSyms[sym] == 0)
			{
				usedSyms[sym] = 1;
				used = 1;
				break;
			}
		}

		switch (sym)
		{
		case 0:
			fiveSO.bonus[n] = SYMBOLS[0];
			break;
		case 1:
			fiveSO.bonus[n] = SYMBOLS[1];
			break;
		case 2:
			fiveSO.bonus[n] = SYMBOLS[2];
			break;
		case 3:
			fiveSO.bonus[n] = SYMBOLS[3];
			break;
		case 4:
			fiveSO.bonus[n] = SYMBOLS[4];
			break;
		case 5:
			fiveSO.bonus[n] = SYMBOLS[5];
			break;
		case 6:
			fiveSO.bonus[n] = SYMBOLS[6];
			break;
		case 7:
			fiveSO.bonus[n] = SYMBOLS[7];
			break;
		}
	}

	return fiveSO;

}

void displayScratchOffFive(FiveDollar fiveSO)
{
	const int SYMS = 4;
	const int NUMS = 12;
	const int BREAK = 4;

	int i;

	printf("+%42s+\n", "--------------------------------------------------");
	printf("| WINNING NUMBERS %7s", " ");
	for (i = 0; i < SYMS; ++i)
	{
		printf("%d    ", fiveSO.winNumbers[i]);
	}

	if (fiveSO.winNumbers[1] < 10)
	{
		printf("%4s\n", "|");

	}
	else
	{
		printf("%2s\n", "|");
	}


	printf("|%50s|\n", " ");

	printf("| YOUR NUMBERS %37s\n", "|");
	printf("|%4s", " ");


	for (i = 0; i < NUMS; ++i)
	{
		printf("%d  ", fiveSO.numbers[i]);
	}



	printf("\n");

	printf("| PRIZES %43s\n", "|");
	printf("| %7s", " ");

	for (i = 0; i < NUMS; ++i)
	{
		if (i == 5 || i == 10)
		{
			printf("\n| %7s", " ");
		}

		printf("%.2lf %1s", fiveSO.prizes[i], " ");

	}

	printf("\t %19s\n", "|");
	printf("| %50s\n", "|");

	printf("| SYMBOLS %42s\n", "|");
	printf("| %10s", " ");

	for (i = 0; i < SYMS; ++i)
	{
		printf("%c %3s", fiveSO.bonus[i], " ");
	}

	printf("\t %11s \n", "|");
	printf("| %50s\n", "|");

	printf("+%42s+\n", "--------------------------------------------------");


}

// This function belongs to the game of BlackJack and returns cash.
int playBlackJack(cash)
{
	// Our local variable functions.
	const int BET = 10;
	const int MIN_HIT = 16;
	const int HIT = 1;
	const int STAND = 0;

	int play = 1;
	int choice = 0;
	int bust = 0;
	int player = 0;
	int dealer = 0;

	// Deck and dealt have their 2D arrays when we need to access them later on.
	char deck[SUITS][FACES];
	char dealt[SUITS][FACES];

	// Statements printed before the game's functionality is started.
	printf("Let's play Black Jack!\n");
	printf("\n");
	printf("Your cash balance is $%d.\n", cash);
	printf("The bet is $%d.\n", BET);
	printf("** Dealer must HIT if their score is %d or less! **\n", MIN_HIT);
	printf("** Dealer must STAND if their score is %d or higher! **\n", (MIN_HIT + 1));
	printf("If the player wins the hand, you win $%d!\n", BET * 2);
	printf("If the dealer wins the hand, the $%d bet is lost!\n", BET);
	printf("If it is a PUSH, the player keeps their $%d bet!\n", BET);
	printf("\n");

	clearScreen();

	// If the user doesn't have enough cash.
	if (cash < BET)
	{
		printf("Not enough cash!\n");
		return cash;
	}

	initializeUsed(dealt);

	printf("Shuffling...\n");

	initializeDeck(deck);

	printDeck(deck);

	clearScreen();

	printf("Dealing...\n");

	// This while loop executes while PLAY is active.
	while (play != 0)
	{
		printf("Player Balance: $%d\n", cash);

		if (cash >= BET)
		{
			printf("Time to play the game of Blackjack!\n");
		}
		else
		{
			play = 0;
			continue;
		}

		cash -= BET;

		player = 0;
		dealer = 0;
		bust = 0;

		player += deal(deck, dealt);
		player += deal(deck, dealt);
		printf("Your score is %d\n", player);

		dealer += deal(deck, dealt);
		dealer += deal(deck, dealt);

		printf("PRESS 0 TO STAND | PRESS 1 TO HIT\n");
		scanf("%d", &choice);

		// This while loop executes when the choice is equal to HIT and player is less than BUST.
		while (choice == HIT && player < BUST)
		{
			player += deal(deck, dealt);
			printf("Your score is %d.\n", player);

			// If the player's score is greater than BUST we need to set bust to 1 and let the user know that they busted.
			// If the player's score is not greater than BUST, then we give the user the option to stand or hit.
			if (player > BUST)
			{
				bust = 1;
				printf("Player busted!\n");
				break;
			}
			else
			{
				printf("PRESS 0 TO STAND | PRESS 1 TO HIT\n");
				scanf("%d", &choice);

			}
		}
		// If bust was set to 1 from the player being busted, then we must ask the user if they'll like to play another hand.
		// Else we will check for the dealer's conditions and return a loop variable.
		if (bust == 1)
		{
			printf("Play another hand? [0 NO | 1 YES]\n");
			scanf("%d", &play);
			clearScreen();
			continue;
		}
		else
		{
			if (dealer <= MIN_HIT)
			{
				choice = HIT;
			}
			else
			{
				choice = STAND;
			}
		}

		// While the dealer is less than the minimum hit, we will add to the dealer.
		while (dealer <= MIN_HIT)
		{
			dealer += deal(deck, dealt);

			if (dealer <= MIN_HIT)
			{
				choice = HIT;
			}
			else
			{
				choice = STAND;
			}
		}

		// Print the dealers score and append the results to cash while asking the user if they'd like another round.
		printf("Dealers score is %d.\n", dealer);
		cash += results(player, dealer);
		printf("Play another hand? [0 NO | 1 YES]\n");

		scanf("%d", &play);
		clearScreen();

	}

	// Statements printed after the game's functionality is ended.
	printf("-------------------------------------\n");
	printf("Thank you for playing at Knights Casino!\n");
	printf("\n");
	printf("Your cashout is: $%d. See you back again soon.\n", cash);


	return cash;
}

// This function will take in the used parameter setting suites and faces to their respective values. Inside of the nested loops all values in the array of used are set to 0.
void initializeUsed(char used[SUITS][FACES])
{
	int i, j;

	for (i = 0; i < SUITS; ++i)
	{
		for (j = 0; j < FACES; ++j)
		{
			used[i][j] = 0;
		}
	}

}

// Assigns all the all of the suites their values.
void initializeDeck(char deck[SUITS][FACES])
{
	int i, j;

	const char face[FACES] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };

	for (i = 0; i < SUITS; ++i)
	{
		for (j = 0; j < FACES; ++j)
		{
			deck[i][j] = face[j];
		}
	}
}

// This function printDeck will print the clubs, diamonds, hearts, and spades in the array.
void printDeck(char deck[SUITS][FACES])
{
	int i, j;

	for (i = 0; i < SUITS; ++i)
	{
		for (j = 0; j < FACES; ++j)
		{
			switch (i)
			{

			case (CLUBS):
				printf("%c of Clubs\n", deck[i][j]);
				break;

			case (DIAMONDS):
				printf("%c of Diamonds\n", deck[i][j]);
				break;

			case (HEARTS):
				printf("%c of Hearts\n", deck[i][j]);
				break;

			case (SPADES):
				printf("%c of Spades\n", deck[i][j]);
				break;
			}
		}
	}
}

// Deal will deal the player cards when its called.
int deal(char deck[SUITS][FACES], char dealt[SUITS][FACES])
{
	const int maxCards = 52;

	// 0 is false and 1 is true.
	int used = 0;

	int score = 0;
	int suit = 0;
	int face = 0;

	if (cards == maxCards)
	{
		cards = 0; // a.
		initializeUsed(dealt);
	}

	while (used == 0)
	{
		suit = (int)rand() % SUITS;
		face = (int)rand() % FACES;

		if (dealt[suit][face] == 0)
		{
			used = 1;
			dealt[suit][face] = 1;
			cards++;
		}

		switch (face)
		{
		case 0:
			score = face + 2;
			break;

		case 1:
			score = face + 2;
			break;

		case 2:
			score = face + 2;
			break;

		case 3:
			score = face + 2;
			break;

		case 4:
			score = face + 2;
			break;

		case 5:
			score = face + 2;
			break;

		case 6:
			score = face + 2;
			break;

		case 7:
			score = face + 2;
			break;

		case 8:
			score = 10;
			break;

		case 9:
			score = 10;
			break;

		case 10:
			score = 10;
			break;

		case 11:
			score = 10;
			break;

		case 12:
			score = 11;
			break;

		}

		return score;
	}


}

// This fucntion reels in the results from the player.
int results(player, dealer)
{
	const int WIN = 20;
	const int PUSH = 10;
	const int LOSE = 0;

	// If statements that reel different results.
	if (dealer > BUST)
	{
		printf("Dealer BUSTED!\n");
		return PUSH;
	}
	else if (player == dealer)
	{
		printf("It was a PUSH!\n");
		return PUSH;
	}
	else if (player > dealer)
	{
		printf("The player WON!\n");
		return WIN;
	}
	else
	{
		printf("Dealer WON!\n");
		return LOSE;
	}
}


int cashOneDollar(struct OneDollar OneSO)
{
	const int SYMS = 2; // For 
	const int NUMS = 5; // For numbers of players numbers and prizes.

	float cash = 0;
	int n;

	// Set equal to function getbonus passing ONE as an arugment.
	char bonus = getBonus(ONE);

	printf("Bonus Symbol - %c\n", bonus);

	for (n = 0; n < NUMS; ++n)
	{
		if (OneSO.numbers[n] == OneSO.winNumber)
		{
			cash += OneSO.prizes[n];
		}
	}

	for (n = 0; n < SYMS; ++n)
	{
		if (OneSO.bonus[n] == bonus)
		{
			cash += BONUS;
		}
	}

	printf("Your $1 Scratch Off won you $%.2f!\n", cash);


	return (int)cash;
}

int cashTwoDollar(struct TwoDollar twoSO)
{

	const int WINS = 2;// Number of winning number
	const int SYMS = 2; // Number of bonus symbols
	const int NUMS = 5; // Player number and prizes

	float cash = 0;
	int w, n;

	char bonus = getBonus(TWO);

	printf("Bonus Symbol - %c\n", bonus);

	for (w = 0; w < WINS; ++w)
	{
		for (n = 0; n < 10; ++n)
		{
			if (twoSO.winNumbers[w] == twoSO.numbers[n])
			{
				cash += twoSO.prizes[n];
			}
		}
	}

	for (w = 0; w < SYMS; w++)
	{
		if (bonus == twoSO.bonus[w])
		{
			cash += BONUS;
		}
	}

	printf("Your $2 Scratch Off won you $%.2f!\n", cash);



	return (int)cash;
}

int cashFiveDollar(struct FiveDollar fiveSO)
{
	const int WINS = 4; // Value of winning numbers.
	const int SYMS = 4; // Value of the number of bonus symbols.
	const int NUMS = 12; // Value of the player numbers and prizes.

	float cash = 0;
	int w, n;

	char bonus = getBonus(FIVE);


	printf("Bonus Symbol - %c\n", bonus);

	for (w = 0; w < WINS; ++w)
	{
		for (n = 0; n < NUMS; ++n)
		{
			if (fiveSO.winNumbers[w] == fiveSO.numbers[n])
			{
				cash += fiveSO.prizes[n];

			}
		}
	}

	for (w = 0; w < SYMS; ++w)
	{
		if (bonus == fiveSO.bonus[w])
		{
			cash += BONUS;
		}
	}

	printf("Your $5 Scratch Off won you $%.2f!\n", cash);


	return (int)cash;
}

char getBonus(int type)
{
	// Declare the constants for the number of random symbols for OneDollar, TwoDollar, and FiveDollar scratch off.
	const int ONE_TWO = 6;
	const int FIVE_RAND = 8;

	const char SYMBOLS[8] = { '$', '%', '&', '#', '@', '!', '^', '*' };

	char bonus;
	int sym = 0;

	if (type == ONE || type == TWO)
	{
		sym = rand() % ONE_TWO; // Set variable sym equal to random num generation based six symbols.

		switch (sym)
		{
		case 0:
			bonus = SYMBOLS[0];
			break;
		case 1:
			bonus = SYMBOLS[1];
			break;
		case 2:
			bonus = SYMBOLS[2];
			break;
		case 3:
			bonus = SYMBOLS[3];
			break;
		case 4:
			bonus = SYMBOLS[4];
			break;
		case 5:
			bonus = SYMBOLS[5];
			break;
		}
	}
	else if (type == FIVE)
	{
		sym = rand() % FIVE_RAND; // Set variable sym equal to random num generation based eight symbols.

		switch (sym)
		{
		case 0:
			bonus = SYMBOLS[0];
			break;
		case 1:
			bonus = SYMBOLS[1];
			break;
		case 2:
			bonus = SYMBOLS[2];
			break;
		case 3:
			bonus = SYMBOLS[3];
			break;
		case 4:
			bonus = SYMBOLS[4];
			break;
		case 5:
			bonus = SYMBOLS[5];
			break;
		case 6:
			bonus = SYMBOLS[6];
			break;
		case 7:
			bonus = SYMBOLS[7];
			break;

		}
	}

	return bonus;

}



int main()
{
	// Seeded the random function by calling it below using timeNULL.
	srand(time(NULL));

	// Local Variable Play
	int play = 1;

	// Declared the variable cash with the value of 1000.
	int cash = 1000;
	int gameSelector;
	welcomeScreen();

	do
	{
		clearScreen();
		gameSelector = displayMenu();

		switch (gameSelector) {
		case (SLOTS):
			cash = playSlots(cash);
			break;

		case (SCRATCH):
			cash = playScratchOffs(cash);
			break;

		case (BLACKJACK):
			cash = playBlackJack(cash);
			break;

		case (EXIT):
			gameSelector = 0;
			printf("\n");
			printf("Thanks for playing at Knights Casino!\n");
			printf("Your cash balance is $%d.\n", cash);
			printf("See you again soon!\n");
			return 0;
		}

		// Statements printed after the game's functionality is ended.
		printf("\n");
		printf("########################################\n");
		printf("YOUR KNIGHTS CASINO SUMMARY\n");
		printf("Your current cash is: $%d.\n", cash);
		printf("\n");
		printf("Would you like to play another game?\n");
		printf("[1 YES | 0 NO] : ");


		scanf("%d", &play);


	} while (play == 1);

	return 0;
}
