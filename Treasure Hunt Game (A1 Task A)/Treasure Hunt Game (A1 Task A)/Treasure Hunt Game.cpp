// Treasure Hunt Game Task A Assingment - Samuel Harden

#include <iostream>
#include <ctime>

//These are the prototype functions used by the program the program
void fillGrid(char playerGrid[20][20], int columns, int rows);
void fillGridWithGuess(char playerGrid[20][20], int guessX, int guessY);
void fillGridWithTreasure(char playerGrid[20][20], int guessX, int guessY);
void userGridSize(int& columns, int& rows);
void printGrid(char playerGrid[20][20], int columns, int rows, int colCount, int rowCount);
void hideTreasure(int columns, int rows, int& treasureX, int& treasureY);

int main()
{
	// Varilables declared inside of main
	int columns = 0;
	int rows = 0;

	int rowCount = 1;
	int colCount = 1;

	int guessX = 0;
	int guessY = 0;

	int treasureX = 0;
	int treasureY = 0;

	int guessCount = 0;

	bool foundTreasure = false;

	//create a 2D array with a large enough chunk of memory, its unlikey user will want to play a 100x100 game
	// but just be be sure we have enough memory allocated
	char playerGrid[20][20] = {};

	//Set the RNG at the start of the function
	srand((unsigned int)time(NULL));

	//introduce the player to the program/game
	std::cout << std::endl;
	std::cout << "Treasure Hunt Game - By Samuel Harden" << std::endl;
	std::cout << std::endl;

	std::cout << "Recommended grid smaller than 9x9 - (20x20 Maximum allowed)" << std::endl;

	char quit = 'y';

	while (quit != 'n')
	{
		//First call UserGridSize and get the chosen grid size from the player
		userGridSize(columns, rows);

		//Second call to fillGrid to populate the grid with the chosen character ('*')
		fillGrid(playerGrid, columns, rows);

		// Function to hide the treasure in the grid
		hideTreasure(columns, rows, treasureX, treasureY);

		//now the grid size has been recieved from the player, populated with the correct character
		//& the treasure has been hidden,
		// the game is ready to begin with this final pre-game function call to print the grid
		printGrid(playerGrid, columns, rows, colCount, rowCount);

		//continuos while loop that only exits, using  'break;' when the player has found the treasure
		while (1)
		{

			//ask and receive a guess from the player
			std::cout << std::endl;

			std::cout << "Where do you think the treasue is located? Please enter an X coordinate"
				" between (1 and " << rows << ")" << " and a Y coordinate between (1 and "
				<< columns << "): ";

			std::cin >> guessY >> guessX;

			// First if statement to check if the user input is within the bounds of the game size
			if ((guessY > rows) || (guessX > columns))
			{
				std::cout << std::endl;

				std::cout << "Invalid guess, your guess is outsize the bounds of the game!" << std::endl;
				std::cout << std::endl;

				std::cout << "X (Across) cannot be more than " << rows << ". You entered "
				<< guessY << std::endl;

				std::cout << std::endl;

				std::cout << "Y (Down) cannot exceed more than " << columns << ". You entered "
				<< guessX << std::endl;

				std::cout << std::endl;

				std::cout << "Please try again adventurer!" << std::endl;
				std::cout << std::endl;

				printGrid(playerGrid, columns, rows, colCount, rowCount);
			}

			else if ((guessY < 1) || (guessX < 1))
			{
				std::cout << std::endl;

				std::cout << "Invalid guess, your guess is outsize the bounds of the game!" << std::endl;
				std::cout << std::endl;

				std::cout << "Minimum guess must be at least 1 1, guess cannot be smaller than 1!"
				<< std::endl;

				std::cout << std::endl;

				std::cout << "Please try again adventurer!" << std::endl;
				std::cout << std::endl;

				printGrid(playerGrid, columns, rows, colCount, rowCount);
			}

			else if ((guessX == treasureX) && (guessY == treasureY))
			{
				guessCount++;

				std::cout << std::endl;

				fillGridWithTreasure(playerGrid, guessX, guessY);

				printGrid(playerGrid, columns, rows, colCount, rowCount);

				std::cout << std::endl;

				std::cout << "Congratulations you found the treasure at grid " << treasureY
					<< " " << treasureX << std::endl;

				if (guessCount == 1)
				{
					std::cout << std::endl;
					std::cout << "Wow your either really lucky or a dam"
						" fine Treasure hunter!" << std::endl;
					guessCount = 0;
				}

				else
				{
					std::cout << std::endl;
					std::cout << "it has taken you " << guessCount << " guesses to find the treasure!"
					<< std::endl;

					guessCount = 0;
				}

				std::cout << std::endl;

				guessX = 0;
				guessY = 0;

				break;
			}

			else
			{
				std::cout << std::endl;

				std::cout << "Hard luck, no treasure here..." << std::endl;

				guessCount++;

				guessX = 0;
				guessY = 0;
			}
		}

		std::cout << "would you like to play another game?" << std::endl <<
			"'n' to quit, else any other key to play again!";

		std::cin >> quit;

		std::cout << std::endl;
	}

	return 0;
}

void printGrid(char playerGrid[20][20], int columns, int rows, int colCount, int rowCount)
{
	if ((columns < 10) && (rows < 10))
	{
		std::cout << "  ";
		for (colCount = 0; colCount < rows; colCount++)
		{
			std::cout << colCount + 1 << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;

		for (int i = 0; i < columns; i++)
		{
			std::cout << rowCount << ' '; rowCount++;
			for (int j = 0; j < rows; j++)
			{
				std::cout << playerGrid[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	else if ((columns > 9) || (rows > 9))
	{
		for (int i = 0; i < columns; i++)
		{
			std::cout << " ";
			for (int j = 0; j < rows; j++)
			{
				std::cout << playerGrid[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
}

//Straight forward function, now the program has the user input for grid size, the board can be filled,
// NOTE this function does not actually PRINT the board, just fills it with the Char '*'
void fillGrid(char playerGrid[20][20], int columns, int rows)
{

	// fill board
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			playerGrid[i][j] = '*';
		}
	}

}

void fillGridWithGuess(char playerGrid[20][20], int guessX, int guessY)
{
	playerGrid[guessX - 1][guessY - 1] = 'o';
}

void fillGridWithTreasure(char playerGrid[20][20], int guessX, int guessY)
{
	playerGrid[guessX - 1][guessY - 1] = '!';
}

//This function simply gets the inputs for the grid size from the user, and changes them in main
//because Of the & symbol, this function can return 2 values!
void userGridSize(int& columns, int& rows)
{
	bool check = false;

	while (check == false)
	{
		std::cout << std::endl;

		std::cout << "How many columns and rows would you like (X Y): ";

		std::cin >> rows >> columns;

		std::cout << std::endl;

		if (((columns < 21) && (columns > 0)) && ((rows < 21) && (rows > 0)))
		{
			check = true;
		}

		else
		{
			std::cout << "Invalid input, game Size cannot be less than 1 x 1 or exceed 20 X 20"
			<< std::endl;
		}
	}
}

void hideTreasure(int columns, int rows, int& treasureX, int& treasureY)
{
	treasureX = rand() % columns + 1;
	treasureY = rand() % rows + 1;

	std::cout << "The treasure has been hidden! Good luck Treasure Hunter" << std::endl;
	std::cout << std::endl;
}
