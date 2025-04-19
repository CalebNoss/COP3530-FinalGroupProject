#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Node
{
private:
    Node* northNode;
    Node* southNode;
    Node* eastNode;
    Node* westNode;
    bool isEntrance;
    bool isExit;
    bool isVisited;

    // A* Private Members

    int gScore;
    int hScore;
    int fScore;
    int x;
    int y;


public:
    // constructors / destructor
    Node();

    ~Node();


    // getters

    Node* getNorthNode();

    Node* getSouthNode();

    Node* getEastNode();

    Node* getWestNode();

    bool checkIsEntrance();

    bool checkIsExit();

    bool checkIsVisited();

    // getters for A*

    int getGScore() const;
    int getHScore() const;
    int getFScore() const;
    int getX() const;
    int getY() const;

    // setters

    Node* setNorthNode(Node* newNodePointer);

    Node* setSouthNode(Node* newNodePointer);

    Node* setEastNode(Node* newNodePointer);

    Node* setWestNode(Node* newNodePointer);

    bool setAsEntrance(bool newValue);

    bool setAsExit(bool newValue);

    bool setVisitedValue(bool newValue);

    // setters A*

    void setGScore(int g);
    void setHScore(int h);
    void calcFScore();
    void setPos(int newX, int newY);

    int calcHeuristic(Node* goalNode);

};