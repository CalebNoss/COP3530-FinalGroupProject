#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <queue>

#include "Maze.h"

using namespace std;


// constructors / destructor
Maze::Maze() 
{
    entranceNode = nullptr;
    exitNode = nullptr;
    height = 0;
    width = 0;
    wallCount = 0;
    vector<vector<Node*>> maze2dVector;
};

Maze::~Maze()
{
    if (entranceNode != nullptr)
    {
        delete entranceNode;
    }
    if (exitNode != nullptr)
    {
        delete exitNode;
    }
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; y < width; x++)
        {
            delete maze2dVector[y][x];
        }
    }
};


// getters

Node* Maze::getEntranceNode()
{
    return entranceNode;
};

Node* Maze::getExitNode()
{
    return exitNode;
};

int Maze::getWidth()
{
    return width;
};

int Maze::getHeight()
{
    return height;
};

int Maze::getWallCount()
{
    return wallCount;
};


// setters

void Maze::setEntranceNode(Node* newNode)
{
    entranceNode = newNode;
};

void Maze::setExitNode(Node* newNode)
{
    exitNode = newNode;
};

void Maze::setWidth(int newWidth)
{
    width = newWidth;
};

void Maze::setHeight(int newHeight)
{
    height = newHeight;
};

void Maze::setWallCount(int newWallCount)
{
    wallCount = newWallCount;
};


// functions

void Maze::generateNewMaze()
{
    // delete old maze, if it exists
    if (maze2dVector.empty() == false)
    {
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; y < width; x++)
            {
                delete maze2dVector[y][x];
            }
        }
    }

    // resize array, then make the nodes in it
    maze2dVector.resize(height);
    for (int y = 0; y < height; y++)
    {
        maze2dVector[y].resize(width);
        for (int x = 0; y < width; x++)
        {
            maze2dVector[y][x] = new Node();
        }
    }

    // set seed for random location of entrance & exit
    srand(time(0));
    // randomly set a node on the left wall to be the entrance
    int randomEntrance = rand() % height;
    maze2dVector[randomEntrance][0]->setAsEntrance(true);

    // randomly set a node on the right wall to be the exit
    int randomExit = rand() % height;
    maze2dVector[randomExit][width - 1]->setAsExit(true);

};

void Maze::generateNewWalls()
{
    // reset all pointers
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; y < width; x++)
        {
            Node* currentNode = maze2dVector[y][x];
            
            if (y > 0)
            {
                currentNode->setNorthNode(maze2dVector[y - 1][x]);
            }
            if (y < height - 1)
            {
                currentNode->setSouthNode(maze2dVector[y + 1][x]);
            }
            if (x > 0)
            {
                currentNode->setWestNode(maze2dVector[y][x - 1]);
            }
            if (y < width - 1)
            {
                currentNode->setEastNode(maze2dVector[y][x + 1]);
            }
        }
    }

    // until it makes the desired number of walls
    int successCount = 0;
    while (successCount < wallCount)
    {
        // generates random x and y coordinates for node
        int xCoordinate = rand() % height;
        int yCoordinate = rand() % width;
        Node* currentNode = maze2dVector[yCoordinate][xCoordinate];

        // generates num 0-3, 0=North, 1=South, 2=East, 3=West
        int cardinalDirection = rand() % 4;
        if (cardinalDirection == 0)
        { 
            if (currentNode->getNorthNode() != nullptr)
            {
                // sets pointed to node to not point back, then deletes pointer to it, effectively making a wall
                currentNode->getNorthNode()->setSouthNode(nullptr);
                currentNode->setNorthNode(nullptr);
                successCount++;
            }
        }
        else if (cardinalDirection == 1)
        {
            if (currentNode->getSouthNode() != nullptr)
            {
                // sets pointed to node to not point back, then deletes pointer to it, effectively making a wall
                currentNode->getSouthNode()->setNorthNode(nullptr);
                currentNode->setSouthNode(nullptr);
                successCount++;
            }
        }
        else if (cardinalDirection == 2)
        {
            if (currentNode->getEastNode() != nullptr)
            {
                // sets pointed to node to not point back, then deletes pointer to it, effectively making a wall
                currentNode->getEastNode()->setWestNode(nullptr);
                currentNode->setEastNode(nullptr);
                successCount++;
            }
        }
        else if (cardinalDirection == 3)
        {
            if (currentNode->getWestNode() != nullptr)
            {
                // sets pointed to node to not point back, then deletes pointer to it, effectively making a wall
                currentNode->getWestNode()->setEastNode(nullptr);
                currentNode->setWestNode(nullptr);
                successCount++;
            }
        }
    }
};

void Maze::breadthFirstSearchMethod()
{
    // sets up queue and enters entrance as first node
    queue<Node*> nodeQueue;
    nodeQueue.push(entranceNode);
    entranceNode->setVisitedValue(true);

    while (!nodeQueue.empty())
    {
        // for each node, if it is the exit end the loop, otherwise push every adjascent node that isn't visited into the queue
        Node* currentNode = nodeQueue.front();
        currentNode->setVisitedValue(true);
        if (currentNode->checkIsExit() == true)
        {
            break;
        }
        if (currentNode->getNorthNode() != nullptr && currentNode->getNorthNode()->checkIsVisited() == false)
        {
            nodeQueue.push(currentNode->getNorthNode());
        }
        if (currentNode->getSouthNode() != nullptr && currentNode->getSouthNode()->checkIsVisited() == false)
        {
            nodeQueue.push(currentNode->getSouthNode());
        }
        if (currentNode->getEastNode() != nullptr && currentNode->getEastNode()->checkIsVisited() == false)
        {
            nodeQueue.push(currentNode->getEastNode());
        }
        if (currentNode->getWestNode() != nullptr && currentNode->getWestNode()->checkIsVisited() == false)
        {
            nodeQueue.push(currentNode->getWestNode());
        }

        nodeQueue.pop();
    }
};

