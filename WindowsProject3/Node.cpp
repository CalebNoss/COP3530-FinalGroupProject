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

int Node::getGScore() const {
  return gScore;
}

int Node::getHScore() const {
  return hScore;
}

int Node:: getFScore() const {
  return fScore;
}

int Node::getX() const {
  return x;
}

int Node::getY() const {
  return y;
}


// setters

Node* Node::setNorthNode(Node* newNodePointer)
{
    northNode = newNodePointer;
    return northNode;
}

Node* Node::setSouthNode(Node* newNodePointer)
{
    southNode = newNodePointer;
    return southNode;
}

Node* Node::setEastNode(Node* newNodePointer)
{
    eastNode = newNodePointer;
    return eastNode;
}

Node* Node::setWestNode(Node* newNodePointer)
{
    westNode = newNodePointer;
    return westNode;
}

bool Node::setAsEntrance(bool newValue)
{
    isEntrance = newValue;
    return isEntrance;
}

bool Node::setAsExit(bool newValue)
{
    isExit = newValue;
    return isExit;
}

bool Node::setVisitedValue(bool newValue)
{
    isVisited = newValue;
    return isVisited;
}

void Node::setGScore(int g) {
  gScore = g;
}

void Node::setHScore(int h) {
  hScore = h;
}

void Node::calcFScore() {
  fScore = gScore + hScore;
}

void Node::setPos(int newX, int newY) {
  x = newX;
  y = newY;
}

int Node::calcHeuristic(Node* goalNode) {
  return abs(x - goalNode->getX()) + abs(y - goalNode->getY());
}
