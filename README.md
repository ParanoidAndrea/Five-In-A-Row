# Five in a Row
  Author: Yanyan Zhou
  
  Environment: Visual Studio 2019
  
  Date: 2023/1/15
# Description 
The text describes a program that plays the Five In A Row game. It involves two players who alternate turns to place their markers ('O' for the first player and 'X' for the second player) on a 15x15 grid that starts with empty spaces. The players input the row and column of their move, but it will only be accepted if it falls within the grid's boundaries and the cell is unoccupied. The "hasWon" function determines if a player has won the game by counting the consecutive pieces in all four directions (horizontally, vertically, and diagonally). If the count reaches 5, the player wins, and the game concludes.
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

