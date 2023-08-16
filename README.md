# game-of-life

Conway's Game of Life implementation written in C++. Project was originally written in December 2022.
In August 2023 I've decided to refactor it due to having improved my knowledge about C++ and writing clean code.
The old files are located in old_version/ dir.

"The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life

## How to run it?

```
git clone https://github.com/marcingesek79/game-of-life.git
cd game-of-life
mkdir build
cd build
cmake ..
cmake --build .
./game-of-life
```

You can modify the board in the main.cpp by providing another .txt file similar to already existing ones.

### Boards
- [Gosper's glider gun](https://en.wikipedia.org/wiki/Gun_(cellular_automaton)) (gosperGliderGun.txt)

https://imgur.com/a/UR0D16Q.png

- [Pulsar](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#/media/File:Game_of_life_pulsar.gif) (pulsar.txt)

https://imgur.com/a/NiUOxXv.png
