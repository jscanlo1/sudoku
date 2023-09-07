#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <array>
#include <algorithm>
#include <random>
#include <iterator>
#include <iostream>

#define UNASSIGNED 0


class Sudoku{
    private:
        std::array<int,9> numbers;

        std::array<std::array<int, 9>, 9> startBoard;
        std::array<std::array<int, 9>, 9> answerBoard;
        

        void fillGrid(std::array<std::array<int, 9>, 9> & grid);
        void fillBox(std::array<std::array<int, 9>, 9> & grid, int i);
        bool fullGrid(std::array<std::array<int, 9>, 9> & grid);
        bool solveGrid(std::array<std::array<int, 9>, 9> & grid);
        bool validRow(int x, int row, const std::array<std::array<int, 9>, 9> grid);
        bool validColumn(int x, int col, std::array<std::array<int, 9>, 9> grid);
        bool validSquare(int num, int row, int col, std::array<std::array<int, 9>, 9>& grid);
        void getNextUnassigned(int& row, int& col, std::array<std::array<int, 9>, 9> & grid);
        void generatePuzzle(std::array<std::array<int, 9>, 9>& grid);
        void countSolutions(std::array<std::array<int, 9>, 9>& grid, int& count);

    public:
        Sudoku();
        void sudokuGen();
        std::array<std::array<int, 9>, 9> getStartBoard();
        std::array<std::array<int, 9>, 9> getAnswerBoard();
        
};

#endif