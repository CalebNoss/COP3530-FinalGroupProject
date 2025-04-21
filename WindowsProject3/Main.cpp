#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

#include "Maze.h"


using namespace std;

int main()
{
    sf::RenderWindow mainWindow(sf::VideoMode({ 800, 800 }), "Main menu");
    tgui::Gui mainGui(mainWindow);
    mainGui.loadWidgetsFromFile("Maingui.txt", true);

    // make instruction for algorithm button to actually run the algorithms
    auto renderButton = mainGui.get<tgui::Button>("Render Button");

    renderButton->onPress([&]() {
        // get heght width & wall count, make error message if wall count is too high
        float widthVar = mainGui.get<tgui::EditBoxSlider>("Width Slider")->getValue();
        float heightVar = mainGui.get<tgui::EditBoxSlider>("Height Slider")->getValue();
        float wallCount = mainGui.get<tgui::EditBoxSlider>("Wall Count Slider")->getValue();

        // if wall count more than number of possible walls
        int maxWallVar = ((2 * widthVar * heightVar) - widthVar - heightVar);
        if (wallCount > maxWallVar)
        {
            // make error message and quit function
            sf::RenderWindow errorWindow(sf::VideoMode({ 200, 100 }), "Error");
            tgui::Gui errorGui(errorWindow);
            errorGui.loadWidgetsFromFile("errorGui.txt", true);
            while (errorWindow.isOpen())
            {
                while (auto event = errorWindow.pollEvent())
                {
                    if (event->is<sf::Event::Closed>())
                    {
                        errorWindow.close();
                        return;
                    }
                }

                errorWindow.clear();
                errorGui.draw();
                errorWindow.display();
            }
        }

        // make maze with the parameters
        Maze tempMaze = Maze();
        tempMaze.setWidth(widthVar);
        tempMaze.setHeight(heightVar);
        tempMaze.setWallCount(wallCount);
        tempMaze.generateNewMaze();
        tempMaze.generateNewWalls();


        // for each checkbox, if checked, run function
        if (mainGui.get<tgui::CheckBox>("Brute Force")->isChecked())
        {
            tempMaze.breadthFirstSearchMethod();
        }
        if (mainGui.get<tgui::CheckBox>("A* Algo")->isChecked())
        {
            tempMaze.aStarSearchMethod();
        }
        
        });

    while (mainWindow.isOpen())
    {
        while (auto event = mainWindow.pollEvent())
        {
            mainGui.handleEvent(*event);

            if (event->is<sf::Event::Closed>())
            {
                mainWindow.close();
            }
        }

        mainWindow.clear();
        mainGui.draw();
        mainWindow.display();
    }
}
