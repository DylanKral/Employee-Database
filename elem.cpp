// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//----------------------------------------------------

#include "elem.h"
#include <string>
#include <iostream>

// blank element
el_t::el_t()
{
  key = -1;  // cannot be 0 because 0 is a valid key
  name = ""; // initialize name 
  age = -1; //initialize age 
  gender = " "; //initialize gender
  bank = 0;//initialize bank
  employed = false;//initialize employed
}

// initializing constructor to create an el_t object 
el_t::el_t(int akey, string aname, int aage, string agender, bool aemployed)
{
  key = akey; //sets key
  name = aname;//sets name
  age = aage;// sets age
  gender = agender; //sets gender
  employed = aemployed; //sets employed status
}

// ONLY the key part should be available to the user of this class
int el_t::getkey()
{
  return key;
}

// ONLY the key part should be available to the user of this class 
void el_t::setkey(int akey)
{
  key = akey;
}
  
// overload == for search based on the key part only
bool el_t::operator==(el_t OtherOne)
{
  if (key == OtherOne.key) return true; else return false;
}

bool el_t::operator!=(el_t OtherOne)
{
  if (key != OtherOne.key) return true; else return false;
}

// overload cout 
ostream& operator<<(ostream& os, const el_t& E)  // outputs the information
{
    
  os << E.name << " " << E.gender << " " << E.age << " "; 
  
  if (E.employed == 1)
  {
    os << "Employed ";
  }

  else 
  {
    os << "Not Employed ";
  }

  os << E.key;

  return os;  
}  

