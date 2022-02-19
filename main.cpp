// CS 311 Dylan Kral Final Project
// Employee database
// 
//  Load Data
//  See All employees
//  Search for employee
//  Add Employee
//  Delete Employee
//  Save to a file
//  Exit

#include <iostream>
#include "htable.h"
#include "elem.h"
#include <string>
#include <fstream>
#include <limits>

using namespace std;

void menu(htable& table);
void fillTable(htable& table);  // fills the table from the input file
el_t findEmployee(htable& table); // finds an employee
void addEmployee (htable& table); // adds an employee to the table
void saveTable(htable& table); // saves the table to a file 

int main() 
{
  htable table; // create table
  
  menu(table);// load the menu
}

void menu(htable& table) // menu
{
int menu_option;

  cout << "\n||||||||||||||||||||||||||||||||||||||\n\n"
       << "Enter a number 1-7\n\n"
       << "1. Load Data\n" // Menu
       << "2. See All Employees\n"
       << "3. Search for Employee\n"
       << "4. Add Employee\n"
       << "5. Delete Employee\n"
       << "6. Save to file\n"
       << "7. Exit\n"
       << "\n||||||||||||||||||||||||||||||||||||||\n";

  cin >> menu_option;

 if (menu_option == 1) // get input data from file
 {
  fillTable(table); // fill the table from the input file
  menu(table);
 }

 else if (menu_option == 2)// see all employees
 {
   table.displayTable(); //display the table
   menu(table);
 }

 else if (menu_option == 3) // search for an employee
 {
   findEmployee(table); // find the employee
   menu(table);
 }

 else if (menu_option == 4)// add an employee
 {
   addEmployee(table);
 }

 else if (menu_option == 5)// delete an employee
 {
   el_t employee = findEmployee(table);

   table.deleteEmployee(employee);

   menu(table);
 }

 else if (menu_option == 6) // save to a file
 {
   saveTable(table);
   menu(table);
 }

 else 
 {
   cout << "\n\nGoodbye\n\n"; // if 7 or anything else is entered, program closes

   exit(1);
 }

}

void fillTable(htable& table) // fill the table from the input file
{
  string firstName; // instantiate necessary variables
  string secondName;
  string gender; 
  bool employed; 
  int age; 
  int bank;
  string fname; // file name

  cout << "Enter a file name: \n"; // ask for file name
  cin >> fname; // user input filename

  ifstream fin (fname.c_str(), ios::in);  // open the file

  if (!fin)
  {
    cout << "Error opening file!\n Exiting program";
    exit(1);
  }

  while (fin>> firstName >> secondName >> gender >> employed >> age >> bank)  // while the file is open
  {
     // take the input from the file and save it to the variables created
     firstName = firstName+ " " +secondName; // concatenate the two names

    el_t employee(bank, firstName, age, gender, employed); // put all of the information to an el_t object

    table.add(employee); // add it to the table
  }
}

el_t findEmployee(htable& table)// finds employee
{
  int employeeKey;

  cout << "Enter the key of the employee you are tring to locate\n";
  cin >> employeeKey;
  
  cout << "\n";

  el_t employee = table.find(employeeKey);

  return employee;
}

void addEmployee (htable& table) // add employee to the table
{
  char cont = 'Y'; // variable for continuation
  string firstName; // instantiate necessary variables
  string gender; //
  bool employed; //
  int age; //
  int bank;//
  int x = 1; // variable for employee number
  
  while(cont == 'Y') // loop if the user wants to add another employee
  {
    try{
    cin.ignore();
    cout << "Employee #" << x << "\n"
         << "Name: \n";
    getline(cin, firstName); // get employee name
    
    cout << "Gender (M/F)\n";
    cin >> gender; // get gender of employee
    while(cin.fail()) 
    {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Bad entry.  Enter Gender (M/F): \n";
    cin >> gender;
    }

    cout << "Employeed (1 = true/ 0 = false)\n";
    cin >> employed;// get employment status

    while(cin.fail()) // if incorrect input, try again
    {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Bad entry.  Enter (1 = true/ 0 = false): \n";
    cin >> employed;
    }

    cout << "Age (18-99)\n";
    cin >> age; // get age

    while(cin.fail()) // if incorrect input, try again
    {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Bad entry.  Enter Age (18-99): \n";
    cin >> age;
    }

    cout << "Enter last 4 of bank account (XXXX)\n";
    cin >> bank;// get bank info

    while(cin.fail()) // if incorrect input, try again
    {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Bad entry. Enter bank info (XXXX): \n";
    cin >> bank; 
    }

    el_t employee (bank, firstName, age, gender, employed); //create the new elem
    table.add(employee);// add the employee to the table

    cout << "Would you like to add another employee? (Y/N)\n";// asks for another employee
    cin >> cont;
    cont = toupper(cont);
    x++;
    }
    catch(...)
    {
      cout << "Error inputing new employee!\n Returning to menu";
      menu(table);
    }
  }

  menu(table);
}

void saveTable(htable& table) // saves the table to a file
{
  string fname;

  ofstream fout;

  cin.ignore();
  cout << "Enter a file name you would like to save to: \n"; // ask for file name
  getline(cin,fname); // user input filename
  
  fout.open(fname.c_str(), ios::app);

  table.saveFile(fout);
  menu(table);
}
