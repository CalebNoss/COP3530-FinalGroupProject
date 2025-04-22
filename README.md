# Maze Pathfinder Visualizer

A C++/SFML/TGUI application that lets you generate random mazes and watch Breadth‑First Search and A* find the shortest path.

## Features:
- Random maze generation with adjustable width, height, and wall density
- Visual, step-by-step animation of BFS, A*, and greedy Best-First Search
- Final shortest path highlighted
- Fast rendering via SFML RenderTexture caching
- Configurable entirely via GUI sliders and checkboxes

## Requirements:
- C++14-compatible compiler
- SFML 3.0.0
- TGUI (latest release)

## Installation:
Clone the repo and build:
MacOS:
install dependencies using Homebrew
```bash
brew install cmake sfml tgui
git clone https://github.com/yourusername/COP3530-FinalGroupProject.git
cd COP3530-FinalGroupProject
cmake -S . -B build
cmake --build build
./build/COP3530_FinalGroupProject
```

Windows:
REM Windows (run in a Developer Command Prompt)

```
git clone https://github.com/yourusername/COP3530-FinalGroupProject.git
cd COP3530-FinalGroupProject
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" -A x64 ^
  -DSFML_DIR="C:/Libraries/SFML/lib/cmake/SFML" ^
  -DTGUI_DIR="C:/Libraries/TGUI/lib/cmake/TGUI"
cmake --build . --config Release
.\Release\COP3530_FinalGroupProject.exe
```
