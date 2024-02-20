# ECE309_FINALPROJECT_TEAM8
Github Link: https://github.ncsu.edu/jtuck/ECE309_FINALPROJECT_TEAM8

Team: Dchoe2@ncsu.edu Ssweitke@ncsu.edu Jturki@ncsu.edu Pnguyen4@ncsu.edu
Main code inside: FinalProject.cpp

Description of the Game: Our team decided to create Sequence, a board game in which two teams compete to get the first connected series of five cards up, down, across, or diagonally on the board twice. The game starts by creating an object from the class deck, which is inherited by the shuffle & display function and used to display 52 randomly generated cards of varying suits and ranks. The user is then asked the number of players as well as their names. A vector is used to hold a pointer to the player class, with each player being vector indexed. The player class will generate five random cards to form a hand and be assigned to a team. Because our Deck class is a vector database, each time a player plays one of his cards from his hand, one of them is popped. For our user interface feature, we use the mainboard class to display a 10x10 array of randomly generated cards. Following that, our game will prompt the user to select their card from their hand and place it on the board. When a series of 5 connected cards is formed on the board, the game is over.

Changes Made: We modified the game's rules by changing the directions with the Jacks. The Jacks are unique cards that can be placed anywhere or removed and replaced with your own.

Compile/Run Directions:
-We code and test run the project using CLion with langue standard C++11:
- When the program running it will ask you to choose wherever you want Console Player or Computer Player. Input 1 for human and 2 for computer player, please hit enter after the input.
- Next it will ask you for Number of player of names of them this will be the same for both Console and Computer Player. Please aware that the input should follow each other and be separated by a space like below and hit enter.
4 James John Joss Loss.
- The number of player should be even number since we have two team. 
- For Console Player , after the program print out the deck after shuffle, board, and each player deck. It will begin to play start from the first player. It will ask user to choose the card on their deck from 1 to 5, please enter a number in that range and hit enter.
- After that, the program will output the location of the card that you choose:
You have chosen: KS
You can choose to place it at  Row = 1; Column = 6
You can choose to place it at  Row = 9; Column = 6
Please enter the spot you want separate by a space. Like 4 5 for Row = 4, Column =5
- Then you will input the location you want like the example above.
- The game will run until somebody in 2 team win or the deck is all draw.
- For Computer Player, you will still need to input name for them. But after that the game will run itself. Since the dummy bot will be dummy, most of the time the game will end in Draw. Change some one will win in Computer run is 10%. 

Features: The cool features we implemented in the code were to display the user the deck with random cards and to display the position where they can place their card by outputting the row and column number. We assigned each team a respected filled character to distinguish which team has which spot. We introduced an auto - play feature where the AI chooses a random card and play against each other, as well as add a CPU opponent option.

Status Report: If something doesn’t work, explain why.

Overall Design: Includes R1-R3 and C1-C5 Decriptions

R1:
- For the game, we created a card, deck, gameboard, and player class. Each class represents the components required to display, play, and store our decks. The 52 different cards are represented by the four suits: clover, spade, diamond, and heart. The deck class shuffles the deck and prints out the hand for each player, as well as keeping track of what is left after each play in a vector database. The user interface of the gameboard displays the 10x10 array of the different generated cards, as well as the functionality of showing where each card is placed and checking if the win condition is met. The player class represents the user and the computer (inherited), and it includes the ability to store a name for each player as well as assign them a deck and a team. In addition, have the player's action to play a card from their hand.

R2:
- We developed two player characters: the user and the computer. The user player class inherits the computer class with a few modifications because the computer is automated while the user player class is controlled by the user. The automation was designed to use the rand function with a modulo to choose and place their options at random. The user class will allow the user to select which card to use and where to place it on the board.

R3:
- We developed a console and printed a gameboard that shows a 10x10 array of randomly generated cards to the user interface, as well as each player's hand each turn. Following that, the user is given prompts to read and the ability to place their card from their hand into the appropriate spot on the board. Furthermore, you will see your opponents' played action, and the board will display each team's respected spot as well as a win screen when a team meets the win condition.

C1: 
- The sensitivity parameter, such as string name, will be placed inside the private or protected for all of our classes. Because the class public field will only contain function calls, we will be unable to access sensitive data from outside of that class. This adheres to the code's encapsulation requirement.
- The abstract type Base Class Player has two children: ConsolePlayer and Computer Player. The inheritance and abstraction requirements are met.
- The Print() and Begin Deck functions will be the same for both types of Player due to the nature of the code. As a result, only the Place Card function will be completely virtual.

C2:
- Because no special function is required, all classes adhere to the Rule of Zero.

C3:
- As previously stated, the Place Card function of the Player class makes use of virtual methods because we need to implement ConsolePlayer and ComputerPlayer differently.

C4:
- In this code, we use vectors to hold the majority of our data. The first is found within the Deck class: vector Card*>. This vector contains a reference to the Cards class for the entire deck. The vector data type appears again in the Player class, where it now holds the same type of pointer point to Cards class, but this time for each player.
- The main reason we chose vector to run this job is that it supports random shuffle, which allows us to shuffle all 52 cards in the deck.
- Vector can also quickly replace a used card on the Player's hand with a new card from the deck. Because it's an array in the first place.
- The GameBoard is also built with a two-dimensional vector that holds the row and column location of each Card. When the game is played, the vector's index data is replaced with the team symbol. Vector is extremely effective in this situation.

Contributions: 

- Class Cards: Phan Nguyen (Code and test)
- Class Deck: Josh Turki (Code and test)
- Class GameBoard:
  - printBoard(): Stone Weitkemper (Code and test)
  - place_card(Cards *card, string team): Team,
  - place_card_computer(Cards *card, string team): Team
  - CheckWin(string team); Team
  - endGame(string team); Team
- Class Player: Daniel Choe (Code and test)
- Class ConsolePlayer: Phan Nguyen (Code and test)
- Class ComputerPlayer: Team
- Main : Team
