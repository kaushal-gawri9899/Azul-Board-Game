
#ifndef ASSIGN2_NODE_H
#define ASSIGN2_NODE_H

#include "Tiles.h"

class Node {
public:

   Node(Tiles* t, Node* n);
   Node(Node& other);

   Tiles* getTile();
   Node* getNext();
   void setTile(Colour colour);
   void setNext(Node* a);

/* i made these private??, and are these arrays? */
private:
   Tiles*    tile;
   Node*    next;
};

typedef Node* NodePtr;
#endif // ASSIGN2_NODE_H
