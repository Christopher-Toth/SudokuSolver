#include <stdio.h>
#include <stdbool.h>

// Function to check if the given value is safe at the given position in the Sudoku grid
bool isSafe(int grid[9][9], int row, int col, int num) {
    // Check if the same number exists in the row or column
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    // Check if the same number exists in the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    // If the number is safe to place
    return true;
}

// Function to solve the Sudoku grid
bool solveSudoku(int grid[9][9]) {
    int row, col;

    // Find the first unassigned position in the grid
    int found = 0;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    // If no unassigned position is found, the Sudoku is solved
    if (!found) {
        return true;
    }

    // Try placing numbers from 1 to 9 in the current position
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            // Place the number in the current position
            grid[row][col] = num;

            // Recursively solve the Sudoku
            if (solveSudoku(grid)) {
                return true;
            }

            // If the number doesn't lead to a solution, backtrack and try the next number
            grid[row][col] = 0;
        }
    }

    // If no number can be placed in the current position, backtrack
    return false;
}

// Function to print the Sudoku grid
void printGrid(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to prompt the user to enter the Sudoku grid
void enterGrid(int grid[9][9]) {
    printf("Enter the Sudoku grid (use 0 for empty cells):\n");
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("Enter value for position (%d, %d): ", row + 1, col + 1);
            scanf("%d", &grid[row][col]);
        }
    }
}

// Function to verify if the Sudoku grid is valid
bool verifyGrid(int grid[9][9]) {
    // Check rows and columns for duplicate numbers
    for (int i = 0; i < 9; i++) {
        int rowFlags[10] = { 0 };
        int colFlags[10] = { 0 };
        for (int j = 0; j < 9; j++) {
            int rowValue = grid[i][j];
            int colValue = grid[j][i];
            if (rowValue != 0) {
                if (rowFlags[rowValue] == 1) {
                    return false;
                } else {
                    rowFlags[rowValue] = 1;
                }
            }
            if (colValue != 0) {
                if (colFlags[colValue] == 1) {
                    return false;
                } else {
                    colFlags[colValue] = 1;
                }
            }
        }
    }

    // Check 3x3 subgrids for duplicate numbers
    for (int block = 0; block < 9; block++) {
        int startRow = (block / 3) * 3;
        int startCol = (block % 3) * 3;
        int subgridFlags[10] = { 0 };
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                int value = grid[i][j];
                if (value != 0) {
                    if (subgridFlags[value] == 1) {
                        return false;
                    } else {
                        subgridFlags[value] = 1;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    // Sudoku grid
    int grid[9][9];

    // Prompt the user to enter the Sudoku grid
    enterGrid(grid);

    printf("\nEntered Sudoku:\n");
    printGrid(grid);

    // Verify the grid before solving
    if (!verifyGrid(grid)) {
        printf("\nInvalid Sudoku grid.\n");
        return 0;
    }

    // Ask the user to confirm the grid
    char confirmation;
    printf("\nDo you want to solve this Sudoku grid? (y/n): ");
    scanf(" %c", &confirmation);

    if (confirmation == 'y' || confirmation == 'Y') {
        if (solveSudoku(grid)) {
            printf("\nSolution:\n");
            printGrid(grid);
        } else {
            printf("\nNo solution exists.\n");
        }
    } else {
        printf("\nSudoku grid not solved.\n");
    }

    return 0;
}