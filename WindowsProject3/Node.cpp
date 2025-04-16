#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

#include "Node.h"

using namespace std;


Node::Node()
{
    northNode = nullptr;
    southNode = nullptr;
    eastNode = nullptr;
    westNode = nullptr;
    isEntrance = false;
    isExit = false;
    isVisited = false;
}

Node::~Node()
{
    northNode = nullptr;
    southNode = nullptr;
    eastNode = nullptr;
    westNode = nullptr;
    isEntrance = false;
    isExit = false;
    isVisited = false;
}


// getters

Node* Node::getNorthNode()
{
    return northNode;
}

Node* Node::getSouthNode()
{
    return southNode;
}

Node* Node::getEastNode()
{
    return eastNode;
}

Node* Node::getWestNode()
{
    return westNode;
}

bool Node::checkIsEntrance()
{
    return isEntrance;
}

bool Node::checkIsExit()
{
    return isExit;
}

bool Node::checkIsVisited()
{
    return isVisited;
}



// setters

Node* Node::setNorthNode(Node* newNodePointer)
{
    northNode = newNodePointer;
}

Node* Node::setSouthNode(Node* newNodePointer)
{
    southNode = newNodePointer;
}

Node* Node::setEastNode(Node* newNodePointer)
{
    eastNode = newNodePointer;
}

Node* Node::setWestNode(Node* newNodePointer)
{
    westNode = newNodePointer;
}

bool Node::setAsEntrance(bool newValue)
{
    isEntrance = newValue;
}

bool Node::setAsExit(bool newValue)
{
    isExit = newValue;
}

bool Node::setVisitedValue(bool newValue)
{
    isVisited = newValue;
}