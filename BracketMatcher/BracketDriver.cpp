//***********************************************
// BracketDriver.cpp (Project 2)
//
// Written by Steven Smail for COP4530
//
//***********************************************

#include <iostream>
#include "bracketMatcher.h"
using namespace std;

int main()
{
  string phrase;

  cout << "This is the Bracket Driver.\n";

  do
  {
    cout << "Please enter a statement: ";
    getline(cin, phrase);
    cout << phrase << endl;
    balanced(phrase);
    cout << endl;
  } while(phrase.size());
}