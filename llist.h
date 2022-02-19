//Dylan Kral
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================
#ifndef LLIST_H
#define LLIST_H
#include "elem.h"
#include <fstream>
// alias el_t : element type definition
//typedef char el_t;  // int for now but can change later

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist 
{
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //shows if the list is empty
  bool isEmpty();
    
  // displays all the nodes in the list
  void displayAll();

  //adds a node to the front of the list
  void addFront(el_t);
    
  //adds a node to the rear of the list
  void addRear(el_t);

  // deletes a node in the front of the list 
  void deleteFront(el_t&);
    
  //deletes a node in the rear of the list
  void deleteRear(el_t&);
    
  //delets the Ith noded in the list
  void deleteIth(int, el_t&);  // calls moveTo

  //inserts a node at the Ith position
  void insertIth(int, el_t);   // calls moveTo

  void saveFile(ofstream&);


  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

  
};
#endif
