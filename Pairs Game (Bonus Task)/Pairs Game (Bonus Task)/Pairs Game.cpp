// Pairs Game BONUS TASK (Assingment) - Samuel Harden

#include <iostream>
#include <ctime>

	//These are the prototype functions used by the program the program
	void fillGrid(char playerGrid[5][5], char starGrid[5][5], int columns, int rows);
	void fillGridWithGuess(char playerGrid[5][5], char starGrid[5][5], int symbol1Y, int symbol1X, int symbol2Y, int symbol2X);
	void userGridSize(int& columns, int& rows);
	void printGrid(char playerGrid[5][5], int columns, int rows, int colCount, int rowCount);
	void printStarGrid(char starGrid[5][5], int columns, int rows, int colCount, int rowCount);
	void fillGridWithPairs(char playerGrid[5][5], char gridChar[10], int columns, int rows, int posX, int posY);

	int main()
	{
		// Varilables declared inside of main
		int columns = 0;
		int rows = 0;

		int rowCount = 1;
		int colCount = 1;

		int symbol1X = 0;
		int symbol1Y = 0;
		int symbol2X = 0;
		int symbol2Y = 0;

		int posX = 0;
		int posY = 0;

		int gamePairCount = 0;
		int guessCount = 0;

		//create arrays to be used
		char gridChar[10] = {'%', '&', '+', '$', '#', '?', '!', '@', '>', '='};
		char playerGrid[5][5] = {};
		char starGrid[5][5] = {};

		//Set the RNG at the start of the function
		srand((unsigned int)time(NULL));

		//introduce the player to the program/game
		std::cout << std::endl;
		std::cout << "Pair Matching Game - By Samuel Harden" << std::endl;
		std::cout << std::endl;

		std::cout << "Welcome to 'Pairs'. A simple game where you must match symbols in the grid, " << std::endl
			<< "the game ends when all pairs have been sucessfully matched. Good Luck!" << std::endl;

		std::cout << std::endl;

		std::cout << "Recommended grid size larger than 2 x 2 - 2 Pairs" << std::endl <<
		"(5 x 4 or 4 x 5 Maximum allowed - 10 Pairs)" << std::endl;

		char quit = 'y';

		while (quit != 'n')
		{
			//First call UserGridSize and get the chosen grid size from the player
			userGridSize(columns, rows);

			//Second call to fillGrid to populate the grid with the chosen character ('*')
			fillGrid(playerGrid, starGrid, columns, rows);

			//populates the grid with the pairs of symbols
			fillGridWithPairs(playerGrid, gridChar, columns, rows, posX, posY);

			//THIS FUNCTION CALL ONLY NEEDED FOR TESTING
			//printGrid(playerGrid, columns, rows, colCount, rowCount);

			//print the grid with the '*' symbol as a visual aid to the user
			printStarGrid(starGrid, columns, rows, colCount, rowCount);

			//continuos while loop that only exits, using 'break;' when the player has found the treasure
			while (1)
			{

				//ask and receive a guess from the player
				std::cout << std::endl;

				std::cout << "Please choose a position to check (X Y): ";

				std::cin >> symbol1Y >> symbol1X;

				//ask and receive a guess from the player
				std::cout << std::endl;

				std::cout << "Please choose a position to check? (X Y): ";

				std::cin >> symbol2Y >> symbol2X;

				// First if statement to check if the user input is within the bounds of the game size
				if ((symbol1Y > rows) || (symbol1X > columns))
				{
					std::cout << std::endl;

					std::cout << "Invalid guess, your first guess is outsize the bounds of the game!" << std::endl;
					std::cout << std::endl;

					std::cout << "X (Across) cannot be more than " << rows << ". You entered " << symbol1Y 
						<< std::endl;
					std::cout << std::endl;

					std::cout << "Y (Down) cannot exceed more than " << columns << ". You entered " << symbol1X 
						<< std::endl;
					std::cout << std::endl;

					std::cout << "Please try again!" << std::endl;
					std::cout << std::endl;

					printStarGrid(starGrid, columns, rows, colCount, rowCount);
				}

				// second if statement is also to check if the user input is within the bounds of the game size
				else if ((symbol2Y > rows) || (symbol2X > columns))
				{
					std::cout << std::endl;

					std::cout << "Invalid guess, your second guess is outsize the bounds of the game!" 
						<< std::endl;
					std::cout << std::endl;

					std::cout << "X (Across) cannot be more than " << rows << ". You entered " << symbol2Y 
						<< std::endl;
					std::cout << std::endl;

					std::cout << "Y (Down) cannot exceed more than " << columns << ". You entered " << symbol2X
						<< std::endl;
					std::cout << std::endl;

					std::cout << "Please try again!" << std::endl;
					std::cout << std::endl;

					printStarGrid(starGrid, columns, rows, colCount, rowCount);
				}

				// this check is simply to check if the guess is valid
				else if ((symbol1Y < 1) || (symbol1X < 1))
				{
					std::cout << std::endl;

					std::cout << "Invalid guess, your guess is outsize the bounds of the game!" << std::endl;
					std::cout << std::endl;

					std::cout << "Minimum guess must be at least 1 1, guess cannot be smaller than 1!" << std::endl;
					std::cout << std::endl;

					std::cout << "Please try again!" << std::endl;
					std::cout << std::endl;

					printStarGrid(starGrid, columns, rows, colCount, rowCount);
				}

				//this check is simply to check if the guess is valid
				else if ((symbol2Y < 1) || (symbol2X < 1))
				{
					std::cout << std::endl;

					std::cout << "Invalid guess, your guess is outsize the bounds of the game!" << std::endl;
					std::cout << std::endl;

					std::cout << "Minimum guess must be at least 1 1, guess cannot be smaller than 1!" << std::endl;
					std::cout << std::endl;

					std::cout << "Please try again!" << std::endl;
					std::cout << std::endl;

					printStarGrid(starGrid, columns, rows, colCount, rowCount);
				}

				//this is where all checks are clear and the user has input a match
				else if (playerGrid[symbol1X - 1][symbol1Y - 1] == playerGrid[symbol2X - 1][symbol2Y - 1])
				{
					guessCount++;
					gamePairCount++;

					std::cout << std::endl;

					fillGridWithGuess(playerGrid, starGrid, symbol1Y, symbol1X, symbol2Y, symbol2X);

					printStarGrid(starGrid, columns, rows, colCount, rowCount);

					std::cout << std::endl;

					std::cout << "Well done, you found a pair" << std::endl;

						if (gamePairCount == ((columns * rows) / 2))
						{
							std::cout << std::endl;

							std::cout << "Congratulations you have Won The Game!" << std::endl;
							std::cout << std::endl;

							std::cout << "it has taken you " << guessCount << " Guesses to complete" << std::endl;
							std::cout << std::endl;

							break;
						}

				}

				//this is where the user doesnt have a match, and prints out hints as to what was in the
				//positions where they guessed
				else
				{
					std::cout << std::endl;

					std::cout << "Hard luck, no pair here." << std::endl;

					std::cout << std::endl;

					std::cout << "The symbol at coordinates " << symbol1Y << " " << symbol1X << " is a " << playerGrid[symbol1X-1][symbol1Y-1] << std::endl;

					std::cout << std::endl;

					std::cout << "The symbol at coordinates " << symbol2Y << " " << symbol2X << " is a " << playerGrid[symbol2X - 1][symbol2Y - 1] << std::endl;

					//std::cout << std::endl;

					guessCount++;

					//std::cout << std::endl;

					//seems more logical to print the grid just as a visual aid but
					// the assignment brief states not too, and only show the symbols that are at the coords chosen
					//printStarGrid(starGrid, columns, rows, colCount, rowCount);
				}
			}

			guessCount = 0;
			gamePairCount= 0;

			std::cout << "would you like to play another game?" << std::endl <<
				"'n' to quit, else any other key to play again!";

			std::cin >> quit;

			std::cout << std::endl;
		}

		return 0;
	}

	//essentially just a test function to see if the grid has been filled with the pairs correctly
	void printGrid(char playerGrid[5][5], int columns, int rows, int colCount, int rowCount)
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
			std::cout << std::endl;
	}

	//this function prints a grid populated with '*' as an aid to the user when they make their guesses
	void printStarGrid(char starGrid[5][5], int columns, int rows, int colCount, int rowCount)
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
				std::cout << starGrid[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	//Straight forward function, now the program has the user input for grid size, the board can be filled,
	// NOTE this function does not actually PRINT the board, just fills it with the Char '*'
	void fillGrid(char playerGrid[5][5], char starGrid [5][5], int columns, int rows)
	{

		// pre fill board with '*' so that when the grid is checked for a free position,
		//if it has a '*' symbol, it knows it can use that position
		for (int i = 0; i < columns; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				playerGrid[i][j] = '*';
				starGrid[i][j] = '*';
			}
		}
	}

	//this function populates the grid with pairs, and is not actually seen by the user
	void fillGridWithPairs(char playerGrid[5][5],char gridChar[10], int columns, int rows, int posX, int posY)
	{
		int pairCount = (columns * rows) / 2;

		bool loop = false;


		//outer loop runs until all pairs have been set
		for (int i = 0; i < pairCount; i++)
		{
			//inner for loop sets the individual pairs so runs twice
			for (int j = 0; j < 2; j++)
			{
				loop = false;
				
				//the while loop is so it can find a unused position in the array
				while (loop == false)
				{
					posX = rand() % columns;
					posY = rand() % rows;

					//this is the check to see if the position is free or not
					if (playerGrid[posX][posY] == '*')
					{
						playerGrid[posX][posY] = gridChar[i];
						//this cout is used for testing, to see if the loop was filling the array correctly
						//std::cout << playerGrid[posX][posY];
						loop = true;
					}
					else
					{
						//do nothing
					}
				}
			}
		}
		std::cout << std::endl;

		//prints out a message to let the user know the grid has been filled sucessfully
		std::cout << "all pairs hidden sucessfully" << std::endl;

		std::cout << std::endl;
}

	//this fuction gets called when the user has correctly matched a pair and updates the grid with correct guesses
	void fillGridWithGuess(char playerGrid[5][5], char starGrid[5][5], int symbol1Y, int symbol1X, int symbol2Y, int symbol2X)
	{
		starGrid[symbol1X-1][symbol1Y-1] = playerGrid[symbol1X-1][symbol1Y-1];
		starGrid[symbol2X-1][symbol2Y-1] = playerGrid[symbol2X-1][symbol2Y-1];
	}

	//This function simply gets the inputs for the grid size from the user, and changes them in main
	//because Of the & symbol, this function can return 2 values!
	void userGridSize(int& columns, int& rows)
	{
		//local variable only used to repeat the local while loop
		bool check = false;

		while (check == false)
		{
			std::cout << std::endl;

			std::cout << "How many columns and rows would you like (X Y): ";

			std::cin >> rows >> columns;

			std::cout << std::endl;

			//checks to see if the grid size is valid first
			if (((columns < 6) && (columns > 0)) && ((rows < 6) && (rows > 0)))
			{
				//if the size requierments are valid,
				// a secondary check is required to see if we have enough positions in the grid to fill with pairs
				// if there is a remainder then all pairs cannot be matched, loop continues...
				if ((rows * columns) % 2 == 0)
				{
					//while loop can be exited when it knows we have enough positions
					check = true;
				}
				else
				{
					std::cout << "Grid size is not valid, number of positions in the grid must be even" << std::endl;
				}
			}
			else
			{
				std::cout << "Invalid input, game Size cannot be less than 2 x 2 or exceed 4 x 4" << std::endl;
			}
		}
	}
