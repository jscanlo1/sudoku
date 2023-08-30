#include <iostream>
#include <string>
#include <raylib.h>
#include <sudoku.hpp>


const int W = 100;
const int H = 100;

bool isBoxSelected(int startX, int startY, int clickX, int clickY);
void draw_board(const std::array<std::array<int, 9>, 9> &grid, const std::array<std::array<bool, 9>, 9> &orignalNumbers, int clickX, int clickY);
int getPressedNumber();
void updateNumber(std::array<std::array<int, 9>, 9> &grid, int clickX, int clickY);

int main( void )
{
    const int screenWidth = 1000;
    const int screenHeight = 1200;
    int clickX = 0; 
    int clickY = 0;

    Sudoku * myGame = new Sudoku();
    myGame->sudokuGen();

    std::array<std::array<int, 9>, 9> startBoard = myGame->getStartBoard();
    std::array<std::array<bool, 9>, 9> originalNumber;

    for(std::size_t i = 0; i < startBoard.size(); i++) {
        for(std::size_t j = 0; j < startBoard[0].size(); j++) {
            originalNumber[i][j] = startBoard[i][j] != 0;
        }
    }
    
    
  
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update selected box and update number if one has been pressed
        //----------------------------------------------------------------------------------
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            clickX = GetMouseX();
            clickY = GetMouseY();
        } 

        updateNumber(startBoard, clickX, clickY);
        //----------------------------------------------------------------------------------


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("SUDOKU", 380, 10, 60, DARKGRAY);
            draw_board(startBoard, originalNumber, clickX, clickY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}



void draw_board(const std::array<std::array<int, 9>, 9> &grid, const std::array<std::array<bool, 9>, 9> &orignalNumbers, int clickX, int clickY) {

    for(size_t i = 0; i < grid.size(); i++) {
        for(size_t j = 0; j < grid[0].size(); j++) {
            auto rec = Rectangle{
                50 + (float)W * j,
                250 + (float)H * i,
                W,
                H
            };

            std::string numberString;
            if(grid[i][j] == 0) {
                numberString = " ";
            } else {
                numberString = std::to_string(grid[i][j]);
            }

            int fontSize = 60;

            int numberXPos = 50 + (W * j) + (W / 2) - (MeasureText(numberString.c_str(), fontSize) / 2);
            int numberYPos = 250 + (H * i) +(H / 2) - (fontSize / 2);


            if (isBoxSelected(50 + (W * j), 250 + (H * i), clickX, clickY) && !orignalNumbers[i][j]) {
                DrawRectangleRec(rec, GREEN);
            }
            if (orignalNumbers[i][j]) {
                DrawText(numberString.c_str(), numberXPos, numberYPos, fontSize, BLACK);
            } else {
                DrawText(numberString.c_str(), numberXPos, numberYPos, fontSize, GRAY);
            }
            
            DrawRectangleLinesEx(rec, 2, BLUE);
        } 
    }

}

void updateNumber(std::array<std::array<int, 9>, 9> &grid, int clickX, int clickY){
    for(size_t i = 0; i < grid.size(); i++) {
        for(size_t j = 0; j < grid[0].size(); j++) {
            if (isBoxSelected(50 + (W * j), 250 + (H * i), clickX, clickY)) {
                int pressedNumber = getPressedNumber();
                if(pressedNumber > 0) {
                    grid[i][j] = pressedNumber;
                }
            }
        }
    }
}

int getPressedNumber() {
    if(IsKeyPressed(KEY_KP_1) || IsKeyPressed(KEY_ONE)){
        return 1;
    }
    if(IsKeyPressed(KEY_KP_2) || IsKeyPressed(KEY_TWO)){
        return 2;
    }
    if(IsKeyPressed(KEY_KP_3) || IsKeyPressed(KEY_THREE)){
        return 3;
    }
    if(IsKeyPressed(KEY_KP_4) || IsKeyPressed(KEY_FOUR)){
        return 4;
    }
    if(IsKeyPressed(KEY_KP_5) || IsKeyPressed(KEY_FIVE)){
        return 5;
    }
    if(IsKeyPressed(KEY_KP_6) || IsKeyPressed(KEY_SIX)){
        return 6;
    }
    if(IsKeyPressed(KEY_KP_7) || IsKeyPressed(KEY_SEVEN)){
        return 7;
    }
    if(IsKeyPressed(KEY_KP_8) || IsKeyPressed(KEY_EIGHT)){
        return 8;
    }
    if(IsKeyPressed(KEY_KP_9) || IsKeyPressed(KEY_NINE)){
        return 9;
    }
    return -1;
}


bool isBoxSelected(int startX, int startY, int clickX, int clickY) {
    if (clickX >= startX && clickX < startX + W && clickY >= startY && clickY < startY + H) {
        return true;

    }
    
    return false;
}