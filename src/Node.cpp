#include "Node.h"

Node::Node(Tiles* t, Node* n)
{
   this->tile = t;
   this->next = n;
}

Node::Node(Node& other) :
   tile(other.tile),
   next(other.next)
{}

Tiles* Node::getTile()
{
  return this->tile;
}

Node* Node::getNext()
{
  return next;
}

void Node::setNext(Node* a){
  next = a;
}

void Node::setTile(Colour colour){
  tile->setColour(colour);
}
