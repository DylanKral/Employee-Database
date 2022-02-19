//Dylan Kral
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

#include<iostream>
#include "slist.h" 
#include "htable.h"

using namespace std;
// ** Make sure llist constructor and destructors have couts in them

// do not change this one
slist::slist()
{ //cout << "slist constructor:" << endl;
}

// positions always start at 1

int slist::search(el_t key) //searches 
{
  Node * ptr;// create local pointer
  ptr = Front; //make the pointer point to front of the list
  int pos = 1; // instantiate pos to 1

    while (pos <= Count) // while the position does not equal key, keep searching
    {
      if (ptr->Elem == key)// once it finds the key, return its poistion
      {
        return pos;
      }

      else // if key is not found go to next node
      ptr = ptr->Next; // ptr moves to next
      pos++;//increment the pos
    }

    return 0;// if not found, return 0
  
}

el_t slist ::search2(el_t key)
{
 Node *ptr;
 ptr = Front;
 int count = 1;
 el_t blank;
 
 if (Count == 0)
{
  cout << "No User exists\n";
  return blank;
}

 while (ptr->Elem != key)
 {
   ptr = ptr->Next;
   count++;

 }
 if (ptr->Elem == key)
 {
   cout << ptr->Elem << endl;
   return ptr->Elem;
 }
cout << "HERE\n";
return blank;
}

// don't forget to throw OutOfRange for bad pos 
// go to the Ith node (if I is between 1 and Count) and 
// replace the element there with the new element. 
// If I was an illegal value, throw OutOfRange 
void slist::replace(el_t element, int pos)
{
  Node *ptr;

  if (pos > Count || pos < 1)//if pos is out of range, throw out of range
  {
    throw pos;
  }

  else// if position is in range continue
  {
      moveTo(pos, ptr);// move ptr to node before pos

      ptr = ptr->Next;// move ptr to next node which is desired node

      ptr->Elem = element; // replace the element in the node with the one that is desired
  }
}

bool slist::operator==(const slist& OtherOne)
{
  if (OtherOne.Count != Count)// if not the same length, return false    
  {
    return false;
  }

    // if the same lengths,
    // check each node to see if the elements are the same
  else
  {
    Node *ptr;// create local pointer
    Node *secondPtr;// create local pointer
    ptr = Front;//instantiate ptr to front node of original list
    secondPtr = OtherOne.Front;//instantiate secondPtr to OtherOne front node

    while (ptr != NULL) // traverse through the list until it reaches the end
    {
      if (ptr->Elem != secondPtr->Elem) //if the elements are not the same, then return false
      {
        return false;
      }
      
      else // if the elements are the same then move to next node
      {
        ptr = ptr->Next;//move ptr to next
        secondPtr = secondPtr->Next;//moce secondPtr to next node
      }
    }

    return true; // if the while loop finishes without a problem then return true
  }
}
