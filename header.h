#include <iostream>
#include <string>
using namespace std;

class LinkedList {//This is the declaration of the class for the linked list
private:

  typedef struct node{//This is the struct of the nodes for the linked lists which has a pointer and a data item 
    string item;
    node* next;
  } *nodePtr;

  nodePtr head;
  nodePtr tail;
  int num_items;


public://This is all the public objects that are in the linked list class
  LinkedList();
  void push_front(string s);
  void push_back(string s);
  void pop_front();
  void pop_back();
  node front(){return *head;};
  node back(){return *tail;};
  bool empty();
  void insert(int index, const string& item);
  bool remove(int index);
  int find(const string item);
};