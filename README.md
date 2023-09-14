# Sudoku with c++

This project looks at creating an interactive game of c++ using the RayLib library!

This project was really intended as a learning project for the raylib library but please feel free to enjoy a game of sudoku.

## How the game works

The game uses a sudoku class to handle much of the innternal mechanics of the game, as well as generating new games.


The graphics generation are handled in main.cpp. 

A classic 9x9 grid is generated with a sudoku puzzle loaded up. To select a square simply click on it. To input a number simply press a number key (either on the keypad or along the top of your keyboard). Note how the selected square is coloured green. Note also that original squares cannot be selected and that their numbers are shaded darker than user inputted numbers.

![Sudoku Game board](https://github.com/jscanlo1/sudoku/blob/master/images/sudoku.png)  

## Principles of sudoku

the priciples of sudoku are simple! The game consists of a 9x9 square. The square contains 9 3x3 boxes. The player must fill in each unit box with a number from 1-9 such that:

 - Every number in a column is unique.
 - Every number in a row is unique.
 - Every number in a 3x3 box is unique.

## How it was implemented

This project uses the raylibs graphics library to visualise the game.

To generate games of sudoku, the code wokrs backwards by first generating a random complete and valid sudoku grid. The puzzle generator than begins to remove numbers at random and checks to see how many possible solutions there are (there should only be in). Once the floor is reached and no more numbers can be removed the puzzle is ready!

## Installation instructions

Developed on Windows 11 using the Mingw-64 G++ compiler.

To install RayLib library the easiest way is to use the native PacMan package manager in MSYS2.