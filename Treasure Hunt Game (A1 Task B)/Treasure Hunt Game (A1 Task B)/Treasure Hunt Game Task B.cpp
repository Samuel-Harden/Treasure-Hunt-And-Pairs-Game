// Treasure Hunt Game Task A & B Assingment - Samuel Harden

#include <iostream>
#include <ctime>

//These are the prototype functions that will be used later
void fillGrid(char playerGrid[20][20], int columns, int rows);
void fillGridWithGuess(char playerGrid[20][20], int guessX, int guessY);
void fillGridWithTreasure(char playerGrid[20][20], int guessX, int guessY);
void userGridSize(int& columns, int& rows);
void printGrid(char playerGrid[20][20], int columns, int rows, int colCount, int rowCount);
void hideTreasure(int columns, int rows, int& treasureX, int& treasureY);

int main()
{
	// Variables declared inside of main
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

	//create a 2D array with a large enough chunk of memory, its unlikey user will want to play a 20x20 game
	// but just be be sure we have enough memory allocated
	char playerGrid[20][20] = {};

	//Set the RNG at the start of the program
	srand((unsigned int)time(NULL));

	//introduce the player to the program/game
	std::cout << std::endl;
	std::cout << "Treasure Hunt Game - By Samuel Harden" << std::endl;
	std::cout << std::endl;

	std::cout << "Recommended grid smaller than 9x9 - (20x20 Maximum allowed)" << std::endl;


	//start od the main while loop, user can choose to exit or play again when a game has been completed
	char quit = 'y';

	while (quit != 'n')
	{
		//First call UserGridSize and get the chosen grid size from the player
		userGridSize(columns, rows);

		//Second call to fillGrid to populate the grid with the chosen character ('*')
		fillGrid(playerGrid, columns, rows);

		//Function to hide the treasure in the grid, stored as coordinates (treasureX + treasureY)
		hideTreasure(columns, rows, treasureX, treasureY);

		//now the grid size has been recieved from the player, populated with the correct character 
		//& the treasure has been hidden,
		// the game is ready to begin with this final pre-game function call to print the grid
		printGrid(playerGrid, columns, rows, colCount, rowCount);

		//continuos inner while loop that only exits, using 'break;' when the player has found the treasure
		while (1)
		{
			//ask user where they think the treasure is hidden
			std::cout << std::endl;

			std::cout << "Where do you think the treasue is located? Please enter an X coordinate"
				" between (1 and " << rows << ")" << " and a Y coordinate between (1 and "
				<< columns << "): ";

			std::cin >> guessY >> guessX;

			// First if statement to check if the user input is outside the upper bounds of the grid size
			if ((guessY > rows) || (guessX > columns))
			{
				std::cout << std::endl;

				std::cout << "Invalid guess, your guess is outsize the bounds of the game!" << std::endl;
				std::cout << std::endl;

				std::cout << "X (Across) cannot be more than " << rows << ". You entered " << guessY << std::endl;
				std::cout << std::endl;

				std::cout << "Y (Down) cannot exceed more than " << columns << ". You entered " << guessX << std::endl;
				std::cout << std::endl;

				std::cout << "Please try again adventurer!" << std::endl;
				std::cout << std::endl;

				printGrid(playerGrid, columns, rows, colCount, rowCount);
			}

			//second if statement to check if the user input has met the minimum size (1 1)
			else if ((guessY < 1) || (guessX < 1))
			{
				std::cout << std::endl;

				std::cout << "Invalid guess, your guess is outsize the bounds of the game!" << std::endl;
				std::cout << std::endl;

				std::cout << "Minimum guess must be at least 1 1, guess cannot be smaller than 1!" << std::endl;
				std::cout << std::endl;

				std::cout << "Please try again adventurer!" << std::endl;
				std::cout << std::endl;

				printGrid(playerGrid, columns, rows, colCount, rowCount);
			}

			//Now the players guess has been validated, its checked to see if its the same as the treasure location
			else if ((guessX == treasureX) && (guessY == treasureY))
			{
				guessCount++;

				std::cout << std::endl;

				//function call to populate grid with the '!' character
				fillGridWithTreasure(playerGrid, guessX, guessY);

				//prints the grid with the updated '!' character
				printGrid(playerGrid, columns, rows, colCount, rowCount);

				std::cout << std::endl;

				std::cout << "Congratulations you found the treasure at grid " << treasureY
				<< " " << treasureX << std::endl;

					//this if statement is for when the user guessed the location of
					// the treasure first time, and prints a special message
					if (guessCount == 1)
						{
							std::cout << std::endl;

							std::cout << "Wow your either really lucky or a dam"
							" fine Treasure hunter!" << std::endl;

							//guess count is then reset to 0, because if they choose to play again, the counter may be at 1,2,
							//3,4 ect at the start of the next game
							guessCount = 0;
						}

					//if they didnt guess it first time, it will print the following
					else
						{
							std::cout << std::endl;

							std::cout << "it has taken you " << guessCount << " guesses to find the treasure!"
							<< std::endl;

							//guess count is then reset to 0, because if they choose to play again, the counter may be at 1,2,
							//3,4 ect at the start of the next game
							guessCount = 0;
						}

				std::cout << std::endl;

				//user inputs are also reset to help avoid any other bugs/problems
				guessX = 0;
				guessY = 0;

				//this is where the while loop is broke, after the user has completed a game
				break;
			}

			//if the user has not matched their guess to where the treasure location, it reads in this else statement
			else
			{
				std::cout << std::endl;

				//prints a message stating they have not found the treasure
				std::cout << "Hard luck, no treasure here..." << std::endl;

				guessCount++;

				std::cout << std::endl;

				//grid is the updated with the 'o' character, symbolising to the user that they
				// have guessed at this location, but didnt find anything
				fillGridWithGuess(playerGrid, guessX, guessY);

				//now the grid has been updated, it can be re-printed to aid the user with their next guess
				printGrid(playerGrid, columns, rows, colCount, rowCount);

				//again reseting the user input variables just to be safe
				guessX = 0;
				guessY = 0;
			}
		}

		//now the inner while loop has been exited, the user gets to choose whether to play agin or not
		std::cout << "would you like to play another game?" << std::endl <<
			"'n' to quit, else any other key to play again!";

		std::cin >> quit;

		std::cout << std::endl;
	}
	//outer while loop is exited here if the user inputs an 'n' character and the program exits

	return 0;
}

//function to 'Print' the grid
void printGrid(char playerGrid[20][20], int columns, int rows, int colCount, int rowCount)
{
	//the if statement is so that if the game is under 9x9, a visual aid can be printed
	// numbering the columns and rows
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

	//if the game size is larger than 9, then the visual aid is not printed,
	// as it become un-aligned after 9, as 10 is two digits
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

//Straight forward function, now the program has the user input for grid size, the grid can be filled,
// NOTE this function does not actually PRINT the board, just fills it with the Char '*'
void fillGrid(char playerGrid[20][20], int columns, int rows)
{
	// populates the grid
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			playerGrid[i][j] = '*';
		}
	}
}

//This function is called if the user didn't match their guess with the treasure, and updates the position
// with the 'o' character
void fillGridWithGuess(char playerGrid[20][20], int guessX, int guessY)
{
	playerGrid[guessX-1][guessY-1] = 'o';
}

//This function is called if the user DOES match their guess with th treasure location, and update the position
// with the '!' character
void fillGridWithTreasure(char playerGrid[20][20], int guessX, int guessY)
{
	//the '-1' is used as an array starts at 0, but to the user we start counting from 1
	playerGrid[guessX - 1][guessY - 1] = '!';
}

//This function simply gets the inputs for the grid size from the user
void userGridSize(int& columns, int& rows)
{
	bool check = false;

	//the use of a while loop is because I have validated the inputs within the function,
	// until the program has valiadated the user inputs
	while(check == false)
	{
		std::cout << std::endl;

		std::cout << "How many columns and rows would you like (X Y): ";

		std::cin >> rows >> columns;

		std::cout << std::endl;

			if (((columns < 21) && (columns > 0)) && ((rows < 21) && (rows > 0)))
			{
				//after the check has been given the all clear, the while loop can be exited and the function
				// can exit sucessfully
				check = true;
			}

			else
			{
				//if the validation is not sucessful, a prompt is printed informing the user
				// they have entered an invalid input
				std::cout << "Invalid input, game Size cannot be less than 1 x 1 or exceed 20 X 20" << std::endl;
			}
	}
}

//this function is called to hide the treasure, and selects a random X + Y position
void hideTreasure(int columns, int rows, int& treasureX, int& treasureY)
{
	treasureX = rand() % columns + 1;
	treasureY = rand() % rows + 1;

	//Message is printed to tell the user the treasure has been hidden sucessfully
	std::cout << "The treasure has been hidden! Good luck Treasure Hunter" << std::endl;

	std::cout << std::endl;
}
