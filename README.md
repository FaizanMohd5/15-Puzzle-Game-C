# 15 Puzzle Game in C
This is a 15 puzzle game implementation in C. The game is played on a 4x4 board, where tiles numbered from 1 to 15 are shuffled and the player needs to slide the tiles to rearrange them in order from 1 to 15.

# Installation
This project was developed and tested using Code::Blocks IDE. To run the game on your machine, please make sure that you have Code::Blocks installed. You can download Code::Blocks from their official website: https://www.codeblocks.org/

Once you have Code::Blocks installed, you can clone this repository using the following command:

  git clone https://github.com/your-username/15-puzzle-game-c.git
  
After cloning the repository, open the project in Code::Blocks and build and run the 15-puzzle-game.c file.

# Usage
When you run the game, you will be presented with the game board and a prompt to enter your move. To move a tile, use the arrow keys on your keyboard to select the tile you want to move, and then press the enter key to confirm the move.

You can only move tiles that are adjacent to the empty space on the board. The objective of the game is to arrange the tiles in order from 1 to 15, with the empty space in the bottom-right corner.

The game starts with a randomized board configuration. To achieve this, the time.h library is used to generate a new seed for the random number generator each time the game is played. This ensures that the board configuration is different each time you play the game.

The game ends when you successfully arrange the tiles in order from 1 to 15. Good luck!

# Note
This project was developed using Code::Blocks IDE and may not work on other IDEs or compilers. If you encounter any issues running the game, please try running it on Code::Blocks.

