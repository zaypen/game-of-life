# Game of Life

A demo implementation of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) using C++

![Game of Life](game-of-life.gif)

## Features

- 📐 Custom size support
- ⏯ Pausing / Editing
- 🔎 Moving / Zooming
- 🚀 Speed Adjustment 

## Requirements

- CMake

## Development

### Dependencies

- [SFML](https://www.sfml-dev.org/)([Github](https://github.com/SFML/SFML))

#### Debian/Ubuntu

```bash
sudo apt-get install libsfml-dev
```

#### Fedora

```bash
sudo yum install sfml
```

#### macOS

```bash
sudo port install sfml # MacPorts, or
brew install sfml # homebrew
```

#### Other systems, including Windows
Download the SDK from the download page, unpack it and copy the files to your preferred location.
And export/set environment variable `SFML_ROOT` to the location.

### Build

```bash
cd <PATH_TO_THIS_REPO>
mkdir build
cd build
cmake ..
make
```
Then executable `game_of_life` could be found int `<PATH_TO_THIS_REPO>/build`

### Run
```bash
./game_of_life # Run with default world size 40x30
./game_of_life -w 200 -h 160 # Run with world of 200x160 
```

## Manual
Key/Mouse | Operation
--------- | ---------
SPACE | Pause/Resume
F | Toggle cell alive/dead on cursor (while paused)
F5 | Fill the world randomly
W | Zoom in
S | Zoom out
A | Speed down
D | Speed up
Mouse wheel (horizontal) | Change speed
Mouse wheel (vertical) | Scale the world
Mouse left drag | Move the world

## License

See the [LICENSE](LICENSE.md) file for license rights and limitations (MIT).
