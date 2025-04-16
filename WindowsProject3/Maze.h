#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

#include "Node.h"

using namespace std;


class Maze
{
private:
    Node* entranceNode;
    Node* exitNode;
    int height;
    int width;
    int wallCount;
    vector<vector<Node*>> maze2dVector;

public:
    // constructors / destructor
    Maze();

    ~Maze();


    // getters

    Node* getEntranceNode();

    Node* getExitNode();

    int getWidth();

    int getHeight();

    int getWallCount();


    // setters

    void setEntranceNode(Node* newNode);

    void setExitNode(Node* newNode);

    void setWidth(int newWidth);

    void setHeight(int newHeight);

    void setWallCount(int newWallCount);


    // functions

    void generateNewMaze();

    void generateNewWalls();

    void breadthFirstSearchMethod();

};