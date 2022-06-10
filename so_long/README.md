So_long was about writing a small 2D-Game using the school-intern mini-libx library.
The goal is to collect all collectables and move into the exit.

Usage:
  You can create your own maps. It must be a text file. There are five different tiles in the game: walls(1), floor(0),
  player(P), collectable(C) and exit(E).
  
  Every map must be rectangular, surrounded by walls, contain exactly one player and exit and at least one collectable.
  For example maps look inside the map folder.
  
  All maps must be placed inside the maps folder.
  
  To start the game call the program with the map name you want to play as the only argument.
  
  Use W, A, S, D to move and ESC to exit.

-------------------------------------------------------------------------

It works pretty simple. If a relevant keystroke is detected by the mlx loop it will jump into the function bound to that key which will first update the gamestate and then trigger an update of the visuals.
