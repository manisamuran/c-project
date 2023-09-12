# c-project snake game
Table of Contents
Prerequisites
Compilation
Game Controls
Game Rules
How to Play
Game Logic
Code Structure

Prerequisites
Before you can run the Snake Game, make sure you have the following prerequisites installed on your system:

GCC: You need a C compiler to build the game. Ensure that GCC is installed on your system.

ncurses Library: This game uses the ncurses library for creating a text-based user interface. You should have the ncurses library installed. You can install it using your system's package manager or via other means specific to your operating system.
Compilation
To compile the Snake Game, open a terminal and navigate to the directory containing the source code file (e.g., snake_game.c). Then, use the following command to compile the program:
This command will generate an executable file named snake_game. You can change the output filename if desired.

Game Controls
W: Move the snake upward.
S: Move the snake downward.
A: Move the snake left.
D: Move the snake right.

Game Rules
The snake starts in the middle of the game board.
Fruits (represented by '@') will randomly appear on the game board.
The snake (represented by '0') can eat the fruits to grow longer and earn points.
The game ends if the snake hits the wall or collides with its own tail.
Your score is displayed on the screen.
The goal is to achieve the highest score possible.

How to Play
1: Run the compiled game by executing the following command:
2: The game will start, and you will see a snake ('0') and a fruit ('@') on the screen.
3: Use the W, S, A, and D keys to control the snake's direction and try to eat as many fruits as possible without crashing into the walls or your own tail.
4: The game will display your score on the screen.
5:  Keep playing until the game ends. You can restart the game by running it again.

Game Logic->
The game's logic is implemented in the source code (snake_game.c). Here is a brief overview of the key logic components:
1: The snake's position, length, and direction are tracked, along with the position of the fruit and the game's status.
2: The input() function listens for user input and updates the snake's direction accordingly.
3: The makeLogic() function updates the snake's position, checks for collisions, and handles the logic for eating fruits and growing the snake.
4: The draw() function is responsible for rendering the game board, snake, fruit, and score on the screen using the ncurses library.
5: The game continues until a collision occurs, at which point the game ends, and the final score is displayed.

Code Structure->
The source code is divided into several functions, each responsible for a specific aspect of the game. Here's a brief description of the code structure:
1: main(): Initializes the game, enters the game loop, and manages the overall flow of the game.
2: setup(): Initializes the game state, including the snake's starting position, fruit's position, score, and other variables.
3: input(): Listens for user input and updates the snake's direction accordingly.
4: makeLogic(): Updates the game logic, including snake movement, collision detection, and fruit consumption.
5: draw(): Renders the game board, snake, fruit, and score on the screen.
6: getch1(): Custom input function that handles non-blocking input using ncurses.
