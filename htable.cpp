// CS311 Yoshii - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: Dylan Kral
// File Type: implementation htable.cpp
// =============================================


#include <iostream>
#include "htable.h"
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

htable::htable()
{}

htable::~htable()
{}

// a simple hash function that uses % TSIZE simply
int htable::hash(int key) // a is key
{ 
 unsigned int hashval;

   hashval = 0;
   hashval = key;
   hashval = ((hashval >> 5) ^ hashval) * 0x45d9f3b; // shift the bits of the hashval to the right then use the original hashval as the exponent and multiply by 0x45d9f3b
  
   return hashval % TSIZE;
}

// adds the element to the table and returns slot#
int htable::add(el_t element )
{
  int slot = hash(element.getkey()) -1;  // hash with the key
  
  table[slot].addRear(element);//** Note that this means adding the element to a slist in the slot (addRear)

  return slot;// returns the slot number
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(int skey)
{ 
 int slot = hash(skey) -1; // hash with skey
 
 el_t selement;  // this is the element to look for in slist

 selement.setkey(skey);//** // initialize selement with just the skey

 table[slot].search2(selement);//** // call slist's search2 with selement which returns the found element 
 
 return selement;//** // return the found element from here (it could be blank)

}

// displays the entire table with slot#s too
void htable::displayTable()
{
  cout << setw(10) << left << "\n[ Employee | "
       << setw(7) << left << "Gender | " 
       << setw(5) << left << "Age | "
       << setw(20) << left << "Employement Status | "
       << setw(10) << left << "ID Number ]\n\n";
           //<< "|||||||||||||||||||||||||||||||||||\n";

  for (int i = 0; i < TSIZE; i++)
    { 
      cout << i+1 << ":" ;   
      table[i].displayAll(); // call slist's displayAll
      cout << endl;
    }
}

void htable::deleteEmployee(el_t elem) //deletes an employee from the table
{
  int skey = elem.getkey(); // gets the key

  int slot = hash(skey) -1; // gets slot

  int pos = table[slot].search(elem); // returns position to pos

  table[slot].deleteIth(pos, elem); // delete the elem

}

void htable::saveFile(ofstream& output) // saves the file 
{
  for (int i = 0; i < 97; i++)
  {
    
    slist list = table[i]; // the list at the given index
    
    list.saveFile(output);
  }
}
