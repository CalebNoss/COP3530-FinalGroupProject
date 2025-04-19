#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <queue>
#include <set>
#include <limits>

#include "Maze.h"
#include "Node.h"

using namespace std;

// constructors / destructor
Maze::Maze() 
{
    entranceNode = nullptr;
    exitNode = nullptr;
    height = 0;
    width = 0;
    wallCount = 0;
    //vector<vector<Node*>> maze2dVector;
};

Maze::~Maze()
{
    // if (entranceNode != nullptr)
    // {
    //     delete entranceNode;
    // }
    // if (exitNode != nullptr)
    // {
    //     delete exitNode;
    // }
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            delete maze2dVector[y][x];
        }
    }

    maze2dVector.clear();

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
            for (int x = 0; x < width; x++)
            {
                delete maze2dVector[y][x];
            }
        }
    }

    // resize array, then make the nodes in it

    maze2dVector.clear();

    maze2dVector.resize(height);
    for (int y = 0; y < height; y++)
    {
        maze2dVector[y].resize(width);
        for (int x = 0; x < width; x++)
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
        for (int x = 0; x < width; x++)
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
            if (x < width - 1)
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
        int yCoordinate = rand() % height;
        int xCoordinate = rand() % width;
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

//A* search method for the graph
void Maze::aStarSearchMethod()
{
    //comparator for the prio queue
    auto compare = [](Node* currNode, Node* currNode1) {
        //node with the smaller fScore should come out first
        return currNode->getFScore() > currNode1->getFScore();
    };

    //open set implemented as a min-heap based on the fScore
    priority_queue<Node*, vector<Node*>, decltype(compare)> openSet(compare);
    //map to reconstruct the path, for each node that it passes through, store its predeccessor
    map<Node*, Node*> from;

    //loop through every node in the grid
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        Node* node = maze2dVector[y][x];
          //set g to infinity
        node->setGScore(INT_MAX);
          //set h to 0
        node->setHScore(0);
          //f = g + h
        node->calcFScore();
          //mark as unvisited
        node->setVisitedValue(false);
      }
    }

    //cost from start to start = 0
    entranceNode->setGScore(0);
    //heuristic estimate to goal
    entranceNode->setHScore(entranceNode->calcHeuristic(exitNode));
    //f = g + h
    entranceNode->calcFScore();

    //add the starting node to the open set
    openSet.push(entranceNode);

    //Main A* loop to keep exploring until there is nothing left
    while (!openSet.empty()) {
        //grab node with lowest fScore
      Node* currNode = openSet.top();
      openSet.pop();

        //mark as visited
      currNode->setVisitedValue(true);

        //check if we reached the goal node (end)
      if (currNode == exitNode) {
        cout << "A* path has found the exit!" << endl;
        return;
      }


        //examine each neighbor
      vector<Node*> neighbors = {currNode->getNorthNode(), currNode->getSouthNode(), currNode->getEastNode(), currNode->getWestNode()};

        //iterate through each neighbor
      for (Node* neighbor : neighbors) {
        if (neighbor == nullptr) {
          continue;
        }
          // the temp g score is curr gScore + cost(curr->neighbor) == 1
        int tempGScore = currNode->getGScore() + 1;

          //if this path to neighbor is better than any previous one
        if (tempGScore < neighbor->getFScore()) {
            //record the best predecessor
          from[neighbor] = currNode;
            //update gScore
          neighbor->setGScore(tempGScore);
            //update hScore
          neighbor->setHScore(neighbor->calcHeuristic(exitNode));
            //update fScore
          neighbor->calcFScore();

            //if we haven't visited this neighbor, add it to the open set
          if (!neighbor->checkIsVisited()) {
            openSet.push(neighbor);
          }
        }
      }
    }

    cout << "A* failed to find a path" << endl;

};
