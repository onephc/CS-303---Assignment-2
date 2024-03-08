#include "header.h";
using namespace std;

LinkedList::LinkedList(){//The linked list has to have a head and tail and keep track of the number of items
  head = NULL;
  tail = NULL;
  num_items = 0;
}

void LinkedList::push_front(string s){//This function will push a new item onto the front of the linked list
  node* tempNode = new node;
  tempNode -> item = s;
  tempNode -> next = head;
  head = tempNode;
  num_items ++;
}

void LinkedList::push_back(string s){//This will push an item onto the back of the linked list
  node* tempNode = new node;
  tempNode -> item = s;
  tempNode -> next = NULL;
  if(tail == NULL){
    head = tempNode;
    tail = tempNode;
  }
  else{
    tail -> next = tempNode;
    tail = tempNode;
  }
  num_items ++;
}

void LinkedList::pop_front(){//This will delete the front item from the linked list
  node* tempNode = new node;
  if (head == NULL){
    return;
  }
  else if (head -> next == NULL){
    tempNode -> next = head;
    head = NULL;
    delete tempNode;
    num_items --;
  }
}

void LinkedList::pop_back(){//This will remove the item at the back of the list
  if (tail == NULL){
    return;
  }
  else if (head -> next == NULL){
    delete head;
    head = NULL;
    tail = NULL;
    num_items --;
  }
  else{
    node* tempNode = new node;
    tempNode -> next = head;
    while(tempNode -> next != tail){
      tempNode = tempNode -> next;
    }
    delete tail;
    tail = tempNode;
    tail -> next = NULL;
    num_items --;
  }
}

bool LinkedList::empty(){//This function simply returns if the list
  if (head == NULL){
    return true;
  }
  else{
    return false;
  }
}

void LinkedList::insert(int index, const string &item){//This will insert an item at the given index into the linked list
  if (index < 0){
    return;
  }
  else if (index == 0){
    push_front(item);
  }
  else if (head == NULL){
    return;
  }
  else{
    node* tempNode = new node;
    tempNode -> item = item;
    node* position = head;
    int i = 0;
    while(position != nullptr && i <= index - 1){
      position = position -> next;
      i++;
    }
    if (position == NULL){
      push_back(item);
      return;
    }
    else{
      tempNode -> next = position -> next;
      position -> next = tempNode;
      num_items++;
    }
  }
}

bool LinkedList::remove(int index){//This function will remove an item from the front of the list 
  if (index < 0){
    return false;
  }
  if (index == 0){
    pop_front();
    return true;
  }
  int i = 0;
  node* position = head;
  while(position != NULL && i <= index -1){
    position = position -> next;
    i++;
  }
  if (position == NULL || position -> next == NULL){
    return false;
  }
  node*tempNode = position -> next;
  position -> next = position -> next -> next;
  delete tempNode;
  num_items --;
  return true;
}

int LinkedList::find(const string item){
  node* position = head;
  int i = 0;
  while(position != NULL){
    if(position -> item == item){
      return i;
    }
  }
  return i;
}