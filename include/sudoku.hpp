#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <array>

#define UNASSIGNED 0

class Sudoku{
    private:
        std::array<std::array<int, 9>, 9> startBoard;
        std::array<std::array<int, 9>, 9> answerBoard;

    public:
        Sudoku();
        void sudokuGen();
        std::array<std::array<int, 9>, 9> getStartBoard();
        std::array<std::array<int, 9>, 9> getAnswerBoard();
        
};

#endif