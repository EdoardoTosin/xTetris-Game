<p align="center">
  <a href="https://github.com/EdoardoTosin/xTetris-Game">
    <img src="https://raw.githubusercontent.com/EdoardoTosin/xTetris-Game/main/doc/logo.png" alt="LOGO" height=100px></a>
</p>

## Table of contents
* [General info](#general-info)
* [Gameplay](#gameplay)
* [Setup](#setup)
* [Documentation](#documentation)
* [License](#license)

## General info
This is a variant of the famous video game Tetris.

## Gameplay
* Goal: Put your organizational skills and endurance to the test by clearing as many lines as possible.
* Clear lines: Maneuver the falling Tetriminos to fit them together within the Matrix. To clear a line, fill every square within a single row.
* Score points: Earn points by clearing lines. Clear multiple lines at once to increase your scoring opportunities.
* Ghost piece: Use the Ghost Piece to determine the best fit for the falling Tetrimino. This helpful guide appears directly below the falling Tetrimino and displays possible placements.
* Next queue: Preview the upcoming Tetrimino in the Next Queue to plan ahead and increase your scoring opportunities.
* Hold queue: Store a falling Tetrimino in the Hold Queue for later use.
* Game over: Stack the Tetriminos too high and the game is over!

Source: [tetris.123-games.org](https://tetris.123-games.org/tut.html)

## Setup
To run this project, compile it locally using `make` command and have fun.

### For Windows users:
* Install Mingw-w64 via the [SourceForge](https://sourceforge.net/projects/mingw-w64/) website
* Add the path to your Mingw-w64 bin folder to the Windows PATH environment variable
* Install [Chocolatey](https://chocolatey.org/install) package manager and then install make with the command
  ```choco install make```
* Download the project from [here](https://github.com/EdoardoTosin/miniLaska-Game/archive/main.zip) or via ``git clone``
* Run the following commands:

  ``` bash
  $ make
  $ .\xTetris
  ```

### For Linux users:
Run the following commands on terminal:
``` bash
$ git clone https://github.com/EdoardoTosin/xTetris-Game.git
$ cd xTetris-Game
$ ./build.sh
$ ./run.sh
```

## Documentation

Doxygen documentation of the project is available [here](https://edoardotosin.github.io/xTetris-Game/).

## License

Copyright (c) 2021 [Lorenzo Tosin](https://github.com/LorenzoTosin) & [Edoardo Tosin](https://github.com/EdoardoTosin)

This software is released under the terms of the GNU General Public License v3.0. See the [LICENSE](https://github.com/EdoardoTosin/xTetris-Game/tree/main/LICENSE) file for further information.
