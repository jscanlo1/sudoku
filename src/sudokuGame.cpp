#include <sudokuGame.hpp>

SudokuGame::SudokuGame(){
    this->myGame = new Sudoku();

    for(std::size_t i = 0; i < this->activeBoard.size(); i++){
        for(std::size_t j = 0; j < this->activeBoard[0].size(); j++){
            this->activeBoard[i][j] = 0;
        }
    }
}

void SudokuGame::newGame() {
    delete this->myGame;
    this->myGame = new Sudoku();
    this->myGame->sudokuGen();
    this->copyBoardToActive(this->myGame->getStartBoard());

    
};

void SudokuGame::revealAnswer() {
     this->compareBoardToActive(this->myGame->getAnswerBoard());
};


bool SudokuGame::checkGame() {
    return this->compareBoardToActive(this->myGame->getAnswerBoard());
};

void SudokuGame::copyBoardToActive(std::array<std::array<int, 9>, 9> originBoard){
    for(int i = 0; i < 9; i++) {
        for( int j = 0; j < 9; j++) {
            this->activeBoard[i][j] = originBoard[i][j];
        }
    }
};

bool SudokuGame::compareBoardToActive(std::array<std::array<int, 9>, 9> originBoard){
    for(int i = 0; i < 9; i++) {
        for( int j = 0; j < 9; j++) {
            if(originBoard[i][j] != this->activeBoard[i][j]){
                return false;
            }
        }
    }
    return true;
};

void SudokuGame::updateBoard(std::array<std::array<int, 9>, 9> newBoard) {
    this->copyBoardToActive(newBoard);
}

std::array<std::array<int, 9>, 9> SudokuGame::getActiveBoard() {
    return this->activeBoard;
}