//Author: Ash Yaw
//
// HW1: A dramatic analysis
// Bard.cpp
//

#include <iostream>
#include <fstream>
#include <string.h>

#include "linkedList.h"
using namespace std;

bool isRepeat(string w);
string retrieve(int k, int r);


linkedList listArr[39];//make an array of linked lists globally indexed using the length of the words


int main(int argc, char** argv)
{
  if (argc != 3)
  {
    throw std::invalid_argument("inproper number of arguments");
  }
  
  ifstream in; in.open(argv[1]); //opens the input file
  ifstream spear; spear.open("shakespeare-cleaned5.txt"); // opens shakespeares work
  ofstream out; out.open(argv[2]); // output to a file
  
  

  
  string line;
  int len;
  
  while(getline(spear, line))// get next line of file
  {
       len = line.length(); // get the length of the current word
       
       if(isRepeat(line))// boolean function to return if word is already in the list
       {
         continue; // restart the loop with a new line
       }
    
       listArr[len].insertNode(line); // since its not a repeat insert it at the index of its length in the listArr in a linked list;
 
  }
  
  for(int i = 5; i <= 39; i++)
  {
    listArr[i].insertionSort(listArr[i].retHead());
  }
  
  
  int k, r;
  while(in >> k >> r) // get input from the file
  {
     if((k <= 39) && (r >= 0))
     {
       string output = retrieve(k,r);
       if(output == "")
       {
          out << "-\n";   
       }
       else{
           out << output;
       }// retrieve the work and rank
     }
  }
  
  return 0;
  
  
}

bool isRepeat(string w)//returns true if word is a repeat
{
    int len = w.length(); // to identify what piece of the array to put it in
    if(listArr[len].find(w))//listArr[wordlength] and calls the find function which does 2 things returns true if word is a duplicate and it increases the frequency count in the node
    {
      return true;
    }
    else{
      return false;
    }
}

string retrieve(int k, int r)
{
  int i = 0;
  Node *curr = listArr[k].retHead(); // get head of list length k 
  while(curr != NULL)
  {
    if(i == r){
      return curr->word+"\n"; 
    }
    
    i++;
    curr = curr->next;
  }
  return "-\n";// error  so it would print the last word again instead of a new - this is the edit 
}