// Filename: linkedlist.h
// 
// Header file for the class LinkedList that represents a linked list
// 

#include <string>

using namespace std;

// node struct to hold data
struct Node {
  string word;
  int len;
  int freq;
  Node *next;
};

class LinkedList 
{
  // private:
  //   Node *head; // stores head of linked list
  public:
    Node *head;
    LinkedList(); // Default constructor sets head to null
    void insert(string); // insert int to list
    Node* find(string); // find int in list, return pointer to node with that int
    string print(); // construct string with data of list in order
    int length(); // returns length of linked list
    void reverse();
    void sort();
    Node *getRank(int);
};