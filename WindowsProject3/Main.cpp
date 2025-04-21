#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

#include "Maze.h"


using namespace std;

int main()
{

    Maze tempMaze = Maze();
    tempMaze.setHeight(200);
    tempMaze.setWidth(200);
    tempMaze.setWallCount(1000);
    tempMaze.generateNewMaze();
    tempMaze.generateNewWalls();
    tempMaze.aStarSearchMethod();

    Maze tempMaze1 = Maze();
    tempMaze1.setHeight(200);
    tempMaze1.setWidth(200);
    tempMaze1.setWallCount(0);
    tempMaze1.generateNewMaze();
    tempMaze1.generateNewWalls();
    tempMaze1.breadthFirstSearchMethod();

    sf::RenderWindow mainWindow(sf::VideoMode({ 800, 800 }), "Main menu");
    tgui::Gui mainGui(mainWindow);
    mainGui.loadWidgetsFromFile("Maingui.txt", true);

    while (mainWindow.isOpen())
    {
        while (auto event = mainWindow.pollEvent())
        {
            mainGui.handleEvent(*event);

            if (event->is<sf::Event::Closed>())
                mainWindow.close();
        }

        mainWindow.clear();
        mainGui.draw();
        mainWindow.display();
    }
}
