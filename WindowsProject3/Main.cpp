#define SFML_STATIC
#include "Maze.h"
#include "Node.h"
// #include <SFML/Graphics.hpp>

int main()
{
    // sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "SFML works!");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);
    //
    // while (window.isOpen())
    // {
    //     while (const std::optional event = window.pollEvent())
    //     {
    //         if (event->is<sf::Event::Closed>())
    //             window.close();
    //     }
    //
    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }

    //ex path found
    // Maze m;
    // m.setWidth(5);
    // m.setHeight(5);
    // m.setWallCount(0);
    //
    // //Allocate nodes & let generateNewMaze() mark a random entrance/exit
    // m.generateNewMaze();
    //
    // //Assign (x,y) for the Manhattan heuristic
    // for (int y = 0; y < m.getHeight(); ++y) {
    //     for (int x = 0; x < m.getWidth(); ++x) {
    //         m.getNodeAt(y, x)->setPos(x, y);
    //     }
    // }
    //
    // //Wire up all the four‑way neighbors
    // m.generateNewWalls();
    //
    // //Override to a deterministic start/end
    // m.setEntranceNode(m.getNodeAt(0, 0));
    // m.setExitNode(     m.getNodeAt(4, 4));
    //
    // cout << "Running A* from (0,0) to (4,4)…\n";
    // m.aStarSearchMethod();
    //
    // return 0;

    //ex blocked
    // Maze m;
    // m.setWidth(5);
    // m.setHeight(5);
    // m.setWallCount(0);
    // m.generateNewMaze();
    //
    //
    // for (int y = 0; y < m.getHeight(); ++y)
    //     for (int x = 0; x < m.getWidth(); ++x)
    //         m.getNodeAt(y, x)->setPos(x, y);
    //
    //
    // m.generateNewWalls();
    //
    // //Force start=(0,0) and goal=(4,4)
    // m.setEntranceNode(m.getNodeAt(0, 0));
    // m.setExitNode(     m.getNodeAt(4, 4));
    //
    // //Carve a full barrier between row 1 and row 2
    // for (int x = 0; x < m.getWidth(); ++x) {
    //     m.getNodeAt(1, x)->setSouthNode(nullptr);
    //     m.getNodeAt(2, x)->setNorthNode(nullptr);
    // }
    //
    // cout << "Running A* on a blocked grid…\n";
    // m.aStarSearchMethod();
    //
    // //Check if exit was ever visited
    // if (!m.getExitNode()->checkIsVisited()) {
    //     cout << "A* failed to find a path!" << endl;
    // }
    //
    // return 0;

    const int width  = 20;
    const int height = 25;

    Maze m;
    m.setWidth(width);
    m.setHeight(height);
    m.setWallCount(0);


    m.generateNewMaze();


    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            m.getNodeAt(y, x)->setPos(x, y);
        }
    }


    m.generateNewWalls();

    m.setEntranceNode(m.getNodeAt(0,    0   ));
    m.setExitNode(     m.getNodeAt(height-1, width-1));

    // prints “A* path has found the exit!” on success
    m.aStarSearchMethod();

    if (m.getExitNode()->checkIsVisited()) {
        cout << "A* completed: path found!" << std::endl;
    } else {
        cout << "A* completed: no path found." << std::endl;
    }

    return 0;

}