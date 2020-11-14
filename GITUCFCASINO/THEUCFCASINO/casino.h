#ifndef CASINO_HEADERS
#define CASINO_HEADERS

// 2:
#define BONUS 20

#define SLOTS 1
#define SCRATCH 2
#define BLACKJACK 3


#define FACES 13
#define SUITS 4
#define CLUBS 0
#define DIAMONDS 1
#define HEARTS 2
#define SPADES 3
#define BUST 21


#define ONE 1
#define TWO 2
#define FIVE 5

typedef struct OneDollar
{
	char bonus[2];
	float prizes[5];
	int winNumber;
	int numbers[5];

} OneDollar;


typedef struct TwoDollar
{
	char bonus[2];
	float prizes[10];
	int winNumbers[2];
	int numbers[10];

} TwoDollar;


typedef struct FiveDollar
{
	char bonus[4];
	float prizes[12];
	int winNumbers[4];
	int numbers[12];

} FiveDollar;

// Function Prototypes
void welcomeScreen();
int displayMenu();
void clearScreen();
int playSlots(int);
int playScratchOffs();
int playBlackJack(int);
char randomSymbol();
void initializeUsed();
void printDeck();
void initializeDeck();
int deal();
int results();
int cashOneDollar(struct OneDollar oneSO);
int cashTwoDollar(struct TwoDollar twoSO);
int cashFiveDollar(struct FiveDollar fiveSO);
char getBonus(int);


struct OneDollar createScratchOffOne(struct OneDollar oneSO);
void displayScratchOffOne(struct OneDollar oneSO);
struct TwoDollar createScratchOffTwo(struct TwoDollar twoSO);
void displayScratchOffTwo(struct TwoDollar twoSO);
struct FiveDollar createScratchOffFive(struct FiveDollar fiveSO);
void displayScratchOffFive(struct FiveDollar fiveSO);

//3
// Cards need to be initalized to 0 in Visual Studio, but it's good to always assign it to 0 and not a random memory address!
int cards = 0;

// 4
#define EXIT 4


#endif // CASINO_HEADERS

