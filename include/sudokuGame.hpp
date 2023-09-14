#ifndef SUDOKU_GAME_H_
#define SUDOKU_GAME_H_

#include <sudoku.hpp>


class SudokuGame {
    private:
        Sudoku * myGame;
        std::array<std::array<int, 9>, 9> activeBoard;

        void copyBoardToActive(std::array<std::array<int, 9>, 9> originBoard);
        bool compareBoardToActive(std::array<std::array<int, 9>, 9> originBoard);

    public:
        SudokuGame();
        void newGame();
        void updateBoard(std::array<std::array<int, 9>, 9> newBoard);
        std::array<std::array<int, 9>, 9> getActiveBoard();
        void revealAnswer();
        bool checkGame();
};

#endif