# Sudoku Solver

## Description

This is a simple C program that allows you to input a Sudoku grid and attempts to solve it using a backtracking algorithm. Sudoku is a popular number puzzle game where the objective is to fill a 9x9 grid with digits so that each column, each row, and each of the nine 3x3 subgrids contain all of the digits from 1 to 9 without any repetition.

## How to Use

1. **Clone the repository:**
   - Open a terminal or command prompt on your local machine.
   - Use the following command to clone the repository to your preferred directory:
     ```
     git clone https://github.com/your-username/sudoku-solver.git
     ```
   - Replace `your-username` with your GitHub username.

2. **Compile the program:**
   - Ensure you have a C compiler installed on your system.
   - Navigate to the cloned repository's directory using the terminal or command prompt.
   - Compile the program using the following command:
     ```
     gcc -o sudoku_solver sudoku_solver.c
     ```
   - If the compilation is successful, an executable file named `sudoku_solver` will be generated in the same directory.

3. **Run the program:**
   - In the same terminal or command prompt, run the executable by entering the following command:
     ```
     ./sudoku_solver
     ```
   - The program will prompt you to enter the Sudoku grid.

4. **Enter the Sudoku grid:**
   - The program will ask you to enter the values for each cell in the 9x9 grid.
   - Use the numbers 1 to 9 to fill in the grid, where 0 represents an empty cell.

5. **Verify the grid:**
   - The program will verify if the entered Sudoku grid is valid before attempting to solve it.
   - If the grid is invalid (i.e., contains duplicate numbers in the same row, column, or subgrid), the program will inform you and terminate.

6. **Solve the Sudoku grid:**
   - If the grid is valid and you want to solve it, type 'y' or 'Y' when prompted.
   - The program will use a backtracking algorithm to attempt to find a solution for the Sudoku grid.
   - If a solution exists, it will be displayed on the screen.
   - If no solution is found, the program will inform you accordingly.

7. **Exit the program:**
   - After the Sudoku grid is solved or if you decide not to solve it, the program will terminate.

## Contributions

Contributions to this project are welcome! If you find any bugs, have suggestions for improvements, or want to add new features, please feel free to open an issue or submit a pull request.

## Note

- Ensure that you provide a valid Sudoku grid as input. The grid should have a unique solution, and the input should be well-formed (9 rows, 9 columns, and only digits from 0 to 9).

- If you encounter any issues or have any feedback, feel free to reach out.

Enjoy solving Sudoku!
