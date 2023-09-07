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

    this->numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};

}


void Sudoku::sudokuGen()
{
  // To start just load a known sudoku game
  // Taken from NYT Sudoku EASY 30/08/2023
  /*
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
  */

    fillGrid(this->answerBoard);
    this->startBoard = this->answerBoard;
}

std::array<std::array<int, 9>, 9> Sudoku::getStartBoard(){
    return this->startBoard;
}

std::array<std::array<int, 9>, 9> Sudoku::getAnswerBoard(){
    return this->answerBoard;
}

/**
 * @brief Function to generate a full answer and problem board
 * 
 * @return true 
 * @return false 
 */
void Sudoku::fillGrid(std::array<std::array<int, 9>, 9> & grid) {
    std::cout << "filling grid" << std::endl;
    fillBox(grid, 0);
    fillBox(grid, 1);
    fillBox(grid, 2);

    solveGrid(grid);
}

void Sudoku::fillBox(std::array<std::array<int, 9>, 9> & grid, int n) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(this->numbers.begin(), this->numbers.end(), g);

    for(int i = 0; i < 9; i++) {
        grid[i / 3 + 3*n][i % 3 + 3*n] = this->numbers[i];
    }   
}

bool Sudoku::fullGrid(std::array<std::array<int, 9>, 9> & grid) {
    for(int i = 0; i < 81; i++ ) {
        if(grid[i/9][i%9] == 0 ) {
            return false;
        }
    }
    return true;
}

bool Sudoku::validRow(int x, int row, const std::array<std::array<int, 9>, 9> grid) {
    for(int i = 0; i < 9; i++) {
        if(grid[row][i] == x) {
            return false;
        }
    }
    return true;
}

bool Sudoku::validColumn(int x, int col, std::array<std::array<int, 9>, 9> grid) {
    for(int i = 0; i < 9; i++) {
        if(grid[i][col] == x) {
            return false;
        }
    }
    return true;
}

bool Sudoku::validSquare(int x, int row, int col, std::array<std::array<int, 9>, 9>& grid) {
    std::array<int,3> square_rows;
    std::array<int,3> square_cols;

    //Find the coords of the other squares in its box;
    if ( col < 3) {
        square_cols = {0, 1, 2};
    } else if (col < 6) {
        square_cols = {3, 4, 5};
    } else {
        square_cols = {6, 7, 8};
    }

    if ( row < 3) {
        square_rows = {0, 1, 2};
    } else if (row < 6) {
        square_rows = {3, 4, 5};
    } else {
        square_rows = {6, 7, 8};
    }

    // Cycle through these coords to see if it exists
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(grid[square_rows[i]][square_cols[j]] == x) {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief 
 * 
 * @param grid 
 * @return true 
 * @return false 
 */
bool Sudoku::solveGrid(std::array<std::array<int, 9>, 9> & grid) {
    if(fullGrid(grid)){
        return true;
    }
    std::array<int,9> guessNumbers = {1,2,3,4,5,6,7,8,9};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(guessNumbers.begin(), guessNumbers.end(), g);



    int row, col;

    getNextUnassigned(row, col, grid);
    std::cout <<"ROW: " << row << std::endl;

    for(const auto num : guessNumbers) {
        if(validRow(num,row,grid) && validColumn(num, col, grid) && validSquare(num, row, col, grid)) {
             grid[row][col] = num;
             if(solveGrid(grid)) {
                 return true;
             }
             grid[row][col] = UNASSIGNED;
         }
    }
    
    return false;
}

void Sudoku::getNextUnassigned(int& row, int& col, std::array<std::array<int, 9>, 9> & grid) {
    for(int i = 0; i < 81; i++) {
        if(grid[i /9][i % 9] == 0) {
            row = i/9;
            col = i%9;
            break;
        }
    }
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

