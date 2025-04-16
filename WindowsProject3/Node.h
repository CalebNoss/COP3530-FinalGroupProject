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



    // setters

    Node* setNorthNode(Node* newNodePointer);

    Node* setSouthNode(Node* newNodePointer);

    Node* setEastNode(Node* newNodePointer);

    Node* setWestNode(Node* newNodePointer);

    bool setAsEntrance(bool newValue);

    bool setAsExit(bool newValue);

    bool setVisitedValue(bool newValue);
};