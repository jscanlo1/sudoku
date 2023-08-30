#include <sudoku.hpp>

Sudoku::Sudoku()
{
    // Initialize the start grid
    for(std::size_t i = 0; i < this->startBoard.size(); i++){
        for(std::size_t j = 0; j < this->startBoard[0].size(); j++){
            this->startBoard[i][j] = UNASSIGNED;
        }
    }

    // Initialize the answer grid
    for(std::size_t i = 0; i < this->answerBoard.size(); i++){
        for(std::size_t j = 0; j < this->answerBoard[0].size(); j++){
            this->answerBoard[i][j] = UNASSIGNED;
        }
    }

}


void Sudoku::sudokuGen()
{
  // To start just load a known sudoku game
  // Taken from NYT Sudoku EASY 30/08/2023
  std::array<int, 81> game = {  6,0,1,5,8,4,0,0,0 ,5,3,7,0,0,1,0,0,6, 0,0,0,0,0,0,9,1,5, 
                                4,0,8,0,1,0,5,0,0, 0,1,0,0,5,2,0,7,4, 7,5,0,4,6,0,0,0,1,
                                0,4,5,1,0,0,0,0,0, 0,6,9,0,0,0,0,3,7, 1,0,0,3,0,6,0,5,0};

  std::array<int, 81> gameAnswer =  {   6,9,1,5,8,4,7,2,3 ,5,3,7,9,2,1,8,4,6, 2,8,4,6,3,7,9,1,5, 
                                        5,2,8,7,1,3,5,6,9, 9,1,6,8,5,2,3,7,4, 7,5,3,4,6,9,2,8,1,
                                        3,4,5,1,7,8,6,9,2, 8,6,9,2,4,5,1,3,7, 1,7,2,3,9,6,4,5,8};

  for(std::size_t i = 0; i < game.size(); i++){
    int row = i / 9;
    int col = i % 9;

    this->startBoard[row][col] = game[i];
    this->answerBoard[row][col] = gameAnswer[i];
  }
}

std::array<std::array<int, 9>, 9> Sudoku::getStartBoard(){
    return this->startBoard;
}

std::array<std::array<int, 9>, 9> Sudoku::getAnswerBoard(){
    return this->answerBoard;
}



/*
std::cout << "GAME BOARD \n";
    std::cout << "_ _ _ _ _ _ _ _ _\n";
    for(int i = 0; i < 9 ; i++ ) {
        std::cout <<'|';
        for(int j = 0; j < 9; j++) {
            std::cout << startBoard[i][j] << '|';
        }
        std::cout << std::endl;
        std::cout << "_ _ _ _ _ _ _ _ _\n";
    }
  std::cout << "_ _ _ _ _ _ _ _ _\n";
  */