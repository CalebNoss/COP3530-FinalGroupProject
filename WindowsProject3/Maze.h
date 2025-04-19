#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <cassert>

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

    Node* getNodeAt(int row, int col) const {
        assert(row >= 0 && row < height);
        assert(col >= 0 && col < width);
        return maze2dVector[row][col];
    }


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

    //A* search method

    void aStarSearchMethod();

    // D* Lite search method

    void dStarLiteSearchMethod();


};