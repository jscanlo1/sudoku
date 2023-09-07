# Sudoku with c++

This project looks at creating an interactive game of c++ using the RayLib library!

This project was really intended as a learning project for the raylib library but please feel free to enjoy a game of sudoku.

## How the game works

The game uses a sudoku class to handle much of the innternal mechanics of the game, as well as generating new games.


The graphics generation are handled in main.cpp. 

A classic 9x9 grid is generated with a sudoku puzzle loaded up. To select a square simply click on it. To input a number simply press a number key (either on the keypad or along the top of your keyboard). Note how the selected square is coloured green. Note also that original squares cannot be selected and that their numbers are shaded darker than user inputted numbers.

![Sudoku Game board](https://github.com/jscanlo1/sudoku/blob/master/images/sudoku.png)  

## Principles of sudoku


## Installation instructions

Developed on Windows 11 using the Mingw-64 G++ compiler.

To install RayLib library the easiest way is to use the native PacMan package manager in MSYS2.