
  #include "LinkedList.h"
  #include <fstream> 
  #include "Factory.h"
  LinkedList::LinkedList() : head(nullptr),
                            current(nullptr),
                            tail(nullptr)

  {
    numOfNodes = 0;
  }

  LinkedList::~LinkedList()
  {
  }

  void LinkedList::addNode(Tiles *tile)
  {
    NodePtr node = new Node(tile, nullptr);
    /* checks if the list is already empty
      * then go through the list, using next to
      * point to the next node
      * else, if empty, make the head the node
      */
    if (head != nullptr)
    {
      tail->setNext(node);
      tail = node;
      numOfNodes++;
    }
    else if (head == nullptr)
    {
      head = node;
      tail = node;
      numOfNodes++;
    }
    else if (head == tail)
    {
      tail->setNext(node);
      tail = node;
      head->setNext(tail);
      numOfNodes++;
    }
  } //end of addNode


  /* find node for the random int to pull out */
  Node *LinkedList::findNode(int index)
  {
    Node *temp = head;

    for (int count = 1; count <= index; count++)
    {

      temp = temp->getNext();
    }
    return temp;
  }

  void LinkedList::addAt(int i, Node *node)
  {
    if (i > 0 && i < numOfNodes)
    { /* find the node  
      and then set the pointers according 
      */
      Node *ka = findNode(i);
      findNode(i - 1)->setNext(node);
      findNode(i - 1)->getNext()->setNext(ka);
      numOfNodes++;
    }
    else if (i == 0 && head != nullptr)
    { /*additional cases where we might 
      be at the head
      */
      node->setNext(head);
      head = node;
      numOfNodes++;
    }
    else if (i == (numOfNodes))
    {
      tail->setNext(node);
      tail->getNext()->setNext(nullptr);
      tail = tail->getNext();
      numOfNodes++;
    }
  }

  void LinkedList::addBack(Tiles *data)
  {
    Node *newNode = new Node(data, nullptr);
    tail->setNext(newNode);
    tail = tail->getNext();
    numOfNodes++;
  }

  void LinkedList::addFront(Tiles *data)
  {
    Node *newNode = new Node(data, nullptr);
    newNode->setNext(head);
    head = newNode;
    numOfNodes++;
  }
  /* delete selected tile pointer */
  void LinkedList::deleteNode(int i)
  {
    if (i == 0)
    {
      head = head->getNext();
      numOfNodes--;
    }
    else if (i == numOfNodes - 1)
    {
      deleteBack();
    }
    else
    {
      findNode(i - 1)->setNext(findNode(i + 1));
      numOfNodes--;
    }
  }

  void LinkedList::deleteBack()
  {
    tail = findNode(numOfNodes - 2);
    tail->setNext(nullptr);
    numOfNodes--;

  }

  void LinkedList::deleteFront()
  {

    head = head->getNext();
    numOfNodes--;
  }

  int LinkedList::returnSize()
  {
    if(head == nullptr) {
        return 0;
    }
    //std::cout<<"Last But not least";
    if(numOfNodes ==0){
      return 0;
    }
    return numOfNodes;
  }

  /* prints everything in the linked list */
  void LinkedList::printLine()
  {
    
    current = head;

    if(current != nullptr){
        current->getTile()->printTile();

        while (current != nullptr && current->getNext() != nullptr)
        {
          current = current->getNext();
          std::cout << " ";
          current->getTile()->printTile();
        }
    }

    std::cout << std::endl;
    
  }

  std::string LinkedList::returnAsString()
  {
    std::string linkedListAsString = "";
    current = head;

    if(current != nullptr){
        linkedListAsString += current->getTile()->getColour();

        while (current != nullptr && current->getNext() != nullptr)
        {
          current = current->getNext();
          linkedListAsString += " ";
          linkedListAsString += current->getTile()->getColour();
        }
    }
    
    linkedListAsString += "\n";
    return linkedListAsString;    
  }

  Tiles *LinkedList::getElement(LinkedList *list, int index, Tiles *tile)
  {

    // Tiles *tile = new Tiles("R");
    Node *newElement = new Node(tile, nullptr);
    for (int i = 0; i < 6; i++)
    {
      // newElement = f->findNode(index);
      //TODO
      //
    }

   std::cout << "We found" << newElement->getTile();
    //return f->findNode(i);
    return nullptr;
  }

  void LinkedList::removeElement(char tile)
  {
    Node *current{head};
    Node *prev{nullptr};

    while(current != nullptr) {
      if(current->getTile()->getColour() == tile) {

        if (current == head){
            if(current->getNext() != nullptr) {
              current = current->getNext();
              head = current;
            }
            else {
              head = nullptr;
              tail = nullptr;
              current = nullptr;

            }
            numOfNodes--;
        }
        else if(current==tail){
          prev->setNext(nullptr);
          tail = prev;
          current = nullptr;
          numOfNodes--;
        }
        else {
            prev->setNext(current->getNext());
            current = current->getNext();
            numOfNodes--;
        }
      }
      else {
        prev = current;
        current = current->getNext();
      }
    }
    
  }

  void LinkedList::deleteAll(){

    Node* current = head;  
    Node* next;  
    
  while (current != NULL)  
  {  
      next = current->getNext();  
      free(current);  
      current = next;  
      
  }  

  numOfNodes = 0;  
  /* deref head_ref to affect the real head back  
      in the caller. */
  head = NULL;

  }

  void LinkedList::addLoaded(std::string tex){
    head = add(tex[0]); 
    Node* curr = head; 
  
    // curr pointer points to the current node 
    // where the insertion should take place 
    for (unsigned i = 1; i < tex.size(); i++) { 
        curr->setNext(add(tex[i])); 
        curr = curr->getNext(); 
    } 

}

Node* LinkedList::add(char data) 
{ 
    Node* newnode = nullptr; 
    newnode->getTile()->setColour(data); 
    newnode->setNext(NULL); 
    return newnode; 
} 
