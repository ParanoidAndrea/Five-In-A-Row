# Five in a Row
  Author: Yanyan Zhou
  
  Environment: Visual Studio 2019
  
  Date: 2023/1/15
# Description 
The code implements a basic Five In A Row game using C++. The game is played on a 15x15 grid represented by a 2D char array board.

The game starts with the initialization of the board using the function initBoard which sets all cells to blank spaces. The players take turns making moves by entering the row and column of their desired move. The move is considered valid if the cell is within the bounds of the grid and is unoccupied. The function isValidMove checks if a move is valid.

After each move, the function hasWon is called to check if the player has won the game by counting the number of consecutive pieces in all four directions (horizontally, vertically, and diagonally). If the count reaches 5, the player has won and the game ends.

The game alternates between two players, player 1 ('O') and player 2 ('X'), until one player wins. The game displays the current state of the board after each move, and prompts the player to enter their move. The game ends with a message indicating which player has won.


# Directory Structure

    ├── ReadMe.md               // User Guide
    
    ├── Debug             
    
    │   ├── Five In A Row.exe   // run the program
    
    ├── Five In A Row.sln       // solution file 
    
    ├── Five In A Row.cpp       // source code
        
    ├── Five In A Row.vcxproj   //Visual Studio project files
            
    ├── Five In A Row.vcxproj.filters   
            
    ├── Five In A Row.vcxproj.user 
# Input and Output
Players will see the amended board after entering the row and column numbers. The other player then has their turn.

![image](https://user-images.githubusercontent.com/82789287/218136263-3e918d0b-c72d-4669-9555-d01732f4f84d.png)

If the number is invalid, the player will be required to enter it again.

![image](https://user-images.githubusercontent.com/82789287/218136999-f075a6b2-aff5-421e-88dd-8e8148f73642.png)

The game will end if a player meets the winning condition.

![image](https://user-images.githubusercontent.com/82789287/218137651-57d109d1-fca6-4346-902e-211366db77df.png)

