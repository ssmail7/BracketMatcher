//************************************************************
// bracketMatcher.cpp (Project 2)
//
// Written by Steven Smail for COP4530
//
//************************************************************

#include <iostream>
#include <stack>
#include <cassert>
#include "bracketMatcher.h"

string left_brackets("[({");
string right_brackets("])}");

bool is_left(char c)
{
  return left_brackets.find(c) != string::npos;
}

bool is_right(char c)
{
  return right_brackets.find(c) != string::npos;
}

bool matches(char L, char R)
{
  assert(is_left(L) && is_right(R));
  return left_brackets.find(L) ==  right_brackets.find(R);
}

bool balanced(string str)
{
  stack<char> S;
  string::iterator strIter;
  int index = 0;

  for(strIter = str.begin(); strIter != str.end(); strIter++)
  {
    if(is_left(*strIter))
      S.push(*strIter);
    else if(is_right(*strIter))
    {
      if(S.empty())
      {
        cout << "Unmatched bracket at index " << index
             << ": " << *strIter << endl;
        return false;  // Nothing to match with //
      }
      if(!matches(S.top(), *strIter))
      {
        cout << "Bracket mismatch at index " << index
             << ": " << S.top() << " and " << *strIter
             << endl;
        return false;  // Wrong type //
      }
      S.pop();
    }
    index++;
  }
  if(S.empty())
  {
    cout << "The brackets in your string are properly matched"
         << endl;
    return true;  // Every symbol matched //
  }
  else
  {
    stack<char> tmp;
    while(!S.empty())
    {
      tmp.push(S.top());
      S.pop();
      index--;
    }
    cout << "Unmatched bracket at index " << index
         << ": " << tmp.top() << endl;
    return false;  // Some symbols were never matched //
  }
}