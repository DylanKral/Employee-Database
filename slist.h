// Name: Dylan Kral
// File: slist.h
//=================================================

#include "llist.h"  // for includes

#ifndef SLIST_H
#define SLIST_H

class slist : public llist 
{

 public:
  
  slist();   // constructor. cout "in slist constructor".
             // Make it do nothing else.
             // Experiment and see what happens.
             // Taking this out completely would not work.
             // But note that there is no destructor.
             // PLEASE DO NOT delete the couts in slist and llist
             // constructors and destructors for HW6!!!!!

  int search(el_t);
    // search through the list to see if any node contains the key.
    // If so, return its position (>=1). Otherwise, return 0.

    el_t search2(el_t);//uses same algorithm as search but returns elem

    void replace(el_t,  int);
    // go to the Ith node (if I is between 1 and Count) and 
    // replace the element there with the new element. 
    // If I was an illegal value, throw OutOfRange 
    
    bool operator==(const slist&);
    // checks to see of the two lists look the same
};
#endif
