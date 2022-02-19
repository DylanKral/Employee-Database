
// ====================================================
//Dylan Kral
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

#include<iostream>
#include "llist.h" 

using namespace std;

llist::llist()
{ 
  //cout << "calling in llist constructor..." << endl; 

  this -> Count = 0;
  this -> Front = NULL;
  this-> Rear = NULL;
}

llist::~llist()
{ 
  //cout << "calling in llist destructor..." << endl; 
}

//PURPOSE: this will check front, rear, and count to see if the list is empty
//PARAMETER: none
bool llist::isEmpty() 
{
if (Count == 0 && Front == NULL && Rear == NULL)
{ return true; }

else return false;

} // be sure to check all 3 data members

//PURPOSE:displays the nodes in the list
//PARAMETER:none
void llist::displayAll() 
{
  Node * ptr;
  ptr = Front;

  if (Count == 0)
  { cout << "[ Empty ]";}

else
 {
  cout << "[";

  while (ptr != NULL)
  {
    cout << ptr->Elem << " ";
    ptr = ptr->Next;
  }
cout << "]" ;
 } 
} 
// be sure to display horizontally in [  ] with
// blanks between elements
  
//PURPOSE:adds a node into the rear of the list
//PARAMETER: NewNum elem
void llist::addRear(el_t NewNum) 
{
  Node * ptr = new Node;
  ptr->Elem = NewNum;

  if (Count == 0) // if there are no elements then front and rear equal the first elem
  {
    Front = ptr;//front points to ptr
    Rear = ptr; //rear points to ptr
    Rear->Next = NULL;//set rear next to NULL
    Count++;//increments the counter
  }

  else  //if the list is not empty then it will insert at rear 
  {
    Rear->Next = ptr;// adds ptr after rear
    Rear = ptr;//rear points to ptr
    Rear->Next = NULL;//set rear next to NULL
    Count++;//increment the counter
  }

} // comment the 2 cases

//PURPOSE: Adds the elem to the front of the list
//PARAMETER: newnum
void llist::addFront(el_t NewNum) 
{
  Node * ptr = new Node;
  ptr->Elem = NewNum;

  if (Count == 0) // if the list is empty then make front and rear = to the new elem
  {
    Front = ptr;//have front point to ptr
    Rear = Front;//have rear point to front
    Rear ->Next =  NULL;//set rears next to NULL
    Count++;//increment counter
  }

  else //Adds the elem in the front 
  {
    ptr->Next = Front; //connect ptr to front
    Front = ptr;//have front point to ptr
    Count++;//increment counter
  }

} // comment the 2 cases

//PURPOSE: Delete the front elem
//PARAMETER: oldnum to store the old element
void llist::deleteFront(el_t& OldNum) 
{ 
  Node *ptr = new Node;
  if (Count == 0) // if the list is empty then it will throw underflow
  {
    throw Underflow();
  }

  else if (Count == 1) //if the list will become 0 after the deletion
  {
    OldNum = Front ->Elem;
    delete Front;//delete front
    Front = NULL;//setfront to NULL
    Rear = NULL;//set rear to NULL
    Count--;//decrement counter
   
  }

  else // Normal Case
  {
    OldNum = Front->Elem;//store the elem to oldnum
    ptr = Front->Next;// connect ptr to front
    delete Front;//delete the object
    Front = ptr;//set front to ptr
    Count--;//decrement counter
  }

} // comment the 3 cases


//PURPOSE: Delete the rear elem
//PARAMETER: Oldnum 
void llist::deleteRear(el_t& OldNum)
{
  Node * ptr; // creates a pointer for the second to last elem
  OldNum = Rear->Elem;
  if (Count == 0) //throw underflow 
  {throw Underflow();}

  else if (Count == 1)//if this will make the list empty then delete and set front and rear to NULL
  {
    OldNum = Rear->Elem;//store the element to OldNum
    delete Front;// delete the object
    Front = NULL;//set front to NULL
    Rear = NULL;//set rear to NULL
    Count--;//decrementes counter
  }

  else //If the list is normal then it will only delete rear
  {
    moveTo(Count, ptr);//ptr goes to rear-1
    Rear = ptr;//rear points to ptr
    delete Rear->Next;//delete the object
    Rear->Next = NULL; //rear next must point to NULL
    Count--; //count is decremented
  }
} // comment the 3 cases

/* harder ones follow */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times to go to the Jth node
  // for ( int K = ... ) temp = temp->Next;
 temp = Front; 
  for (int k = 1; k < J-1; k++)
  {temp = temp->Next;}
}

//PURPOSE: Delete the ith element
//PARAMETER: Ith element number and the contents of the old element
void llist::deleteIth(int I, el_t& OldNum) 
{
  if (I > Count || I < 1) // Error case
  {throw OutOfRange();}

  if (I == 1) //if i is equal to 1 then delete front
  {
    deleteFront(OldNum);
  }

  else if (I == Count) // if i is equal to count then delete rear
  {
    deleteRear(OldNum);
  }

  else // Regular case
  {
    Node * ptr;//points at the element before the element that is deleted
    Node *ptr1;//local pointer

    moveTo(I, ptr);//moves to j-1

    ptr1 = ptr->Next->Next;//ptr1 got two times over
    OldNum = ptr->Next->Elem;//store the elem to oldnum
    delete ptr->Next;//delete the object

    ptr-> Next = ptr1;//reconnect the list
    Count--;//decrement the counter
  }
} 
// use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  

//PURPOSE: Insert an element at the Ith position
//PARAMETER: counter variable, NewNum variable for elem
void llist::insertIth(int I, el_t newNum)
{
  if (I > Count +1  || I < 1) // Error case
  {throw OutOfRange();}

  if (I == 1) //if i is equal to 1 then add front
  {
    addFront(newNum);//go to addFront
  }

  else if (I >= Count) // if i is equal to count then add rear
  {
    
    addRear(newNum);//go to addRear
  }

  else
  {
    Node *ptr = new Node;// holds the new value that is to be input
    Node *secondptr;//points to the element before the position
    Node * thirdptr;//points to the elements at the position

    ptr->Elem = newNum;//new num equals the element ptr points to
 
    moveTo(I, secondptr);//move second pointer to i
    
    thirdptr = secondptr->Next;//thirpointer is the object after seconpointer

    secondptr->Next = ptr;//connect secondptr to ptr

    ptr->Next = thirdptr;//connect ptr to thirdptr
    Count ++;//increment the count
  }
} // use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE: Creates a seperate copied list
//PARAMETER: original list
llist::llist(const llist& Original) 
{
//  this->'s data members need to be initialized here first
    Front = NULL; Rear = NULL; Count = 0;
    //  this-> object has to be built up by allocating new cells
    //  and copying the values from Original into each cell as we did with 
    //  operator= above. To do this,
     // this-> object has to be built up by allocating new cells with OtherOne elements (**)
      Node* P;  // local pointer for OtherOne
       P = Original.Front;
      while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
      {

     this->addRear(P->Elem);    //Pâ€™s element is added to this->
      P = P->Next;                         // Go to the next node in OtherOne   
        } 
      // end of if              
    //  Nothing to return because this is a constructor.
} // use my code

//PURPOSE: Deep copies a list to another
//PARAMETER: Original List
llist& llist::operator=(const llist& OtherOne)
{ el_t x;
     // First make sure this-> and OtherOne are not the same object.
     // To do this, compare the pointers to the objects .
     if (&OtherOne != this)  // if not the same
      {
        // this-> object has to be emptied first.
        while (! this->isEmpty() )
                   this->deleteRear(x);  
        // this-> object has to be built up by allocating new cells with OtherOne elements (**)
        Node* P;  // local pointer for OtherOne
        P = OtherOne.Front;
        while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
        {
           this->addRear(P->Elem);    //Pâ€™s element is added to this->
           P = P->Next;                         // Go to the next node in OtherOne   
         } 
      }// end of if              
     return *this;   
} // use my code

void llist::saveFile(ofstream& output)
{
  Node * ptr;
  ptr = Front;

  if (ptr == NULL)
  {
    return;
  }

  else
  output << ptr->Elem;
}
