#include <stdio.h>
#include <stdbool.h>
#include <ncurses.h>

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

// Function to print the Sudoku grid using ncurses
void printGrid(int grid[9][9], WINDOW *win) {
    wclear(win);
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                wprintw(win, ". ");
            } else {
                wprintw(win, "%d ", grid[row][col]);
            }
        }
        wprintw(win, "\n");
    }
    wrefresh(win);
}

// Function to prompt the user to enter the Sudoku grid using ncurses
void enterGrid(int grid[9][9], WINDOW *win) {
    wprintw(win, "Enter the Sudoku grid (use 0 for empty cells):\n");
    wrefresh(win);
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            wprintw(win, "Enter value for position (%d, %d): ", row + 1, col + 1);
            wrefresh(win);
            int value;
            scanw("%d", &value);
            grid[row][col] = value;
        }
    }
}

int main() {
    // Sudoku grid
    int grid[9][9];

    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Create a window for the grid
    WINDOW *gridWin = newwin(11, 21, 1, 1);
    box(gridWin, 0, 0);
    wrefresh(gridWin);

    // Prompt the user to enter the Sudoku grid
    enterGrid(grid, gridWin);

    // Verify the grid before solving
    if (!verifyGrid(grid)) {
        wprintw(gridWin, "\nInvalid Sudoku grid.\n");
        wrefresh(gridWin);
        getch();  // Wait for user input before exiting
        endwin();
        return 0;
    }

    // Ask the user to confirm the grid
    wprintw(gridWin, "\nDo you want to solve this Sudoku grid? (y/n): ");
    wrefresh(gridWin);
    int confirmation = getch();

    if (confirmation == 'y' || confirmation == 'Y') {
        if (solveSudoku(grid)) {
            wprintw(gridWin, "\nSolution:\n");
            wrefresh(gridWin);
            printGrid(grid, gridWin);
        } else {
            wprintw(gridWin, "\nNo solution exists.\n");
            wrefresh(gridWin);
        }
    } else {
        wprintw(gridWin, "\nSudoku grid not solved.\n");
        wrefresh(gridWin);
    }

    getch();  // Wait for user input before exiting

    // Clean up ncurses
    delwin(gridWin);
    endwin();

    return 0;
}
