#include "header.h";
#include <stack>
#include <vector>
using namespace std;

vector<int> create_vector(){//This function simply creates the vector and returns it
  vector<int> my_vector;
  return my_vector;
}

bool is_empty(vector<int> my_vector){//This function will use the built in .empty function to check of the vector is empty and return a bool
  return my_vector.empty();
}

void insert(vector<int> &my_vector, int element){//This function inserts the element to the top of the stack
    my_vector.push_back(element);
}

void remove(vector<int> &my_vector, int element){//This function will remove the topmost item of the stack
  my_vector.pop_back();
}

int top(vector<int> my_vector){//This function will return the top item of the stack
    return my_vector.back();
}

int average(vector<int> my_vector){//This function will return the average of the items in the stack
    int sum = 0;
    for (int i = 0; i < my_vector.size(); i++){
        sum += my_vector[i];
    }
    return sum / my_vector.size();
}
