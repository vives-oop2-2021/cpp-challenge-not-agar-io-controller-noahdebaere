# C++ Challenge - Not-Agar.io Controller

Create a C++ application that can be used as a controller for the game [Not-Agar.io](https://github.com/BioBoost/not-agar.io).

The application should provide a terminal interface to control the game.

The following commands should at least be available:

* `help`: show some help for the user about the commands that are available
* `exit`: exit the game
* `register <playername>`: register a player in the game
* `players`: get a list of the playernames and their positions
* `move <blob> <direction> <distance>` move one of your blobs (red, green, blue, white) towards a direction (up, down, left, right) for a distance (unsigned integer).
* `shoot <your_blob> <playername> <their_blob>`: shoot a blob of another player with one of your blobs.

Make sure that the controller is build user-friendly and also takes error handling into account. No action should lead to an application crash.

## Object Oriented Programming

Since this is a challenge for the Object Oriented Programming 2 course, you should make sure that it complies with the rules and best-practices of object oriented programming.

Think **SOLID** and **DRY**.

## Provide a Readme

Make sure to provide a decent `README.md` (move this one to `assignment.md`) containing at least:

* a description of the project
* setup instructions
* information about the different in-game commands
* overview of the whole setup
* some screenshots
* dependencies
* todo's
* ...
