#pragma once

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

int Node::getFScore() const {
    return fScore;
}

int Node::getX() const {
    return x;
}

int Node::getY() const {
    return y;
}




// setters

void Node::setNorthNode(Node* newNodePointer)
{
    northNode = newNodePointer;
}

void Node::setSouthNode(Node* newNodePointer)
{
    southNode = newNodePointer;
}

void Node::setEastNode(Node* newNodePointer)
{
    eastNode = newNodePointer;
}

void Node::setWestNode(Node* newNodePointer)
{
    westNode = newNodePointer;
}

void Node::setAsEntrance(bool newValue)
{
    isEntrance = newValue;
}

void Node::setAsExit(bool newValue)
{
    isExit = newValue;
}

void Node::setVisitedValue(bool newValue)
{
    isVisited = newValue;
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
