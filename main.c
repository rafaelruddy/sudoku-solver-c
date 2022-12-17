#include <stdio.h>

int puzzle[9][9] = {	
					{0, 0, 7, 9, 0, 3, 0, 6, 8},
					{1, 0, 5, 0, 0, 0, 0, 4, 2},
					{8, 6, 0, 2, 0, 0, 1, 9, 7},
					{0, 0, 0, 0, 0, 5, 0, 2, 0},
					{0, 0, 0, 7, 0, 6, 0, 0, 1},
					{0, 2, 0, 8, 0, 1, 4, 0, 0},
					{9, 0, 0, 0, 0, 2, 0, 3, 0},
					{0, 7, 4, 0, 0, 8, 0, 0, 9},
					{3, 1, 2, 4, 7, 9, 0, 0, 5}
				};


void printPuzzle()
{

	for (int i = 0; i < 10; i++) {
		if (i % 3 == 0)
			printf("+-------+-------+-------+\n");

		if (i == 9)
			return;

		for (int j = 0; j < 9; j++) {
			if (j % 3 == 0)
				printf("| ");

			puzzle[i][j] != 0 ? printf("%d ", puzzle[i][j]) : printf(". ");
		}

		printf("|\n");
	}
}


int isAvailable(int puzzle[][9], int row, int col, int num)
{
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3;

    for(int i=0; i<9; ++i) {
        if (puzzle[row][i] == num) return 0; //check if number exists in row
        if (puzzle[i][col] == num) return 0; //check if number exists in column
        if (puzzle[rowStart + (i%3)][colStart + (i/3)] == num) return 0; //check if number exists in box
    }
    return 1;
}

int solveSudoku(int puzzle[][9], int row, int col)
{
    int number;

    if(row<9 && col<9) {

        if(puzzle[row][col]) {
			
            if((col+1)<9) return solveSudoku(puzzle, row, col+1);
            if((row+1)<9) return solveSudoku(puzzle, row+1, 0);

            return 1;
        } else {
            for(number=1; number<=9; ++number) {
                if(isAvailable(puzzle, row, col, number)) {
                    puzzle[row][col] = number;

					if (solveSudoku(puzzle, row, col)) 
						return 1;
					else 
						puzzle[row][col] = 0;
                }
            }
        }
        return 0;
    }
}

int main() {

    if (solveSudoku(puzzle, 0, 0)) {
		printf("Solução:\n");
        printPuzzle();
	} else {
		printf("Tabuleiro não possui solução.");
	} 

    return 0;
}