// ash yaw


#ifndef linkedList_H
#define linkedList_H

#include <string>
using namespace std;

class Node
{
  public:
    int k;
    string word;
    Node* next;
   
   Node();
   void freqUp();
   
};


class linkedList
{
  
    Node* head;
    Node* sorted;
    
    public:
      linkedList();
      void insert(string word);
      bool find(string w);
      void insertNode(string word);
      void print();
      void insertionSort(Node* headRef);
      void sort(Node* newNode);
      Node *retHead();
      int length(Node *curr);
};

#endif