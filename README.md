# Game of Life

https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life

## How to run it?
```
git clone https://github.com/marcingesek79/game-of-life.git
cd game-of-life
cmake -S . -B build
make -C build
./build/game-of-life
```
You can modify the board in the main.cpp by providing another .txt file.
The format of the .txt file is specified in already existing files.

### Boards
- [Gosper's glider gun](https://en.wikipedia.org/wiki/Gun_(cellular_automaton)) (gosperGliderGun.txt)
- [Pulsar](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#/media/File:Game_of_life_pulsar.gif) (pulsar.txt)
