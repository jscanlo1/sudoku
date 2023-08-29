#include <string>


class sudoku {
    private:
        int grid[9][9];
        int answerGrid[9][9];

    public:
        void sudoku();
        void generateSudoku();
        void solveSudoku();
        void checkAnswer();

};
