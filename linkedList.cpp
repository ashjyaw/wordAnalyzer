// Ash Yaw

#include "linkedList.h"
#include <string>
#include <iostream>

using namespace std;

void Node::freqUp()
{
    this->k++;
}


Node::Node()
{
    this->next = NULL;
    this->k = 0;
    this->word = "";
}

linkedList::linkedList()
{
  head = NULL;
}


int linkedList::length(Node* curr){
  int len = 0;
  while(curr != NULL)
  {
    len++;
    curr = curr->next;
  }
  return len;
}

bool linkedList::find(string w) //returns true and ups the frequency of the word
{
  Node *curr = head; // create a current node to traverse the list with
  while(curr != NULL)// while there is a node
  {
    if(curr->word == w)// if the current nodes word matches our word 
    {
      curr->freqUp();// increase the frequency which is labeled k
      return true; 
    }
    curr = curr->next; // traverse the list
  }
  return false;// if its not found then return false
}

void linkedList::insertNode(string word)//inserts a node at the front of the list and reassigns the head location to the appended node 
{
  Node *toAdd = new Node; // makes a n
  toAdd->word = word;
  toAdd->k = toAdd->k+1;
  toAdd->next = head;
  head = toAdd;
}

void linkedList::print()
{
  Node *curr = head;
  
  while(curr != NULL)
  {
    cout << "times recorded: "<< curr->k << " of word: " << curr->word << endl;
    curr = curr->next;
  }
}


void linkedList::insertionSort(Node* headRef)
{
  sorted = NULL; // set the sorted LL to empty 
  Node* curr = headRef;
  Node* after;
  while(curr != NULL)
  {
    after = curr->next;
    sort(curr);
    curr = after;
  }
  head = sorted; // change the head to point to the newly sorted LL
}


void linkedList::sort(Node *newNode)
{
   if(sorted == NULL || sorted->k <= newNode->k)
   {
     // if this is our first input or if the prev node is less then the new one
     newNode->next = sorted;
     sorted = newNode; 
   }
   else{
     Node* curr = sorted; // now we will traverse through the new ll
     while(curr->next != nullptr && curr->next->k >= newNode->k)
     {   
       if(curr->next->k == newNode->k && newNode->word.compare(curr->next->word) < 0)
          break;
       curr = curr->next;
     }
     
     newNode->next = curr->next;
     curr->next = newNode;
     
   }
 
}

Node* linkedList::retHead()
{
  return head;
}