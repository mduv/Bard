#include "linkedlist.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;


// Default constructor sets head to null
LinkedList :: LinkedList() {
  head = NULL;
}

// find word in list, return pointer to node with that word. if it doesn't exists return NULL
Node* LinkedList :: find(string word) {
  Node *curr = head; // set temp curr beggining at head, used to iterate thru linked list
  while (curr) { // loop over list
    if (curr->word == word) { // found word, so return curr
      return curr;
    }
    curr = curr->next; // otherwise, next iteration
  }
  // if loop ends, return NULL
  return curr;
}


// inserts string word into list, at the head.
void LinkedList :: insert(string word) {
  
  if (find(word)) {
    find(word)->freq += 1; // word found, increase frequency
  }
  else {
    Node *to_add = new Node; // creates new Node
    to_add->word = word; // sets word to hold input word
    to_add->len = strlen(word.c_str()); // sets len to length of word
    to_add->freq = 0; // sets freq to 0
    to_add->next = NULL;
    Node *curr = head;

    if (curr == NULL) {
      // printf("hello\n");
      head = to_add;
      return;
    }
    while (curr->next != NULL) {
      // printf("%s\n",curr->word.c_str());
      curr = curr->next;
    }
    // printf("hello\n");
    curr->next = to_add;

    
    // to_add->next = head; // make to_add point to existing head
    // head = to_add; // make to_add the head
  }
}


// print list in order
string LinkedList :: print() {
  string mylist_str = "";
  Node *curr = head; 
  while (curr != NULL) {
    mylist_str = mylist_str + (curr->word) + " ";
    curr = curr->next;
  }
  return mylist_str;
}

// returns length of linked list
int LinkedList :: length() {
  int length = 0;
  Node *curr = head;
  while (curr != NULL) {
    length++;
    curr = curr->next;
  }
  // printf("length: %d\n", length);
  return length;
}

void LinkedList :: reverse() {
  Node* curr = head;
  Node* prev = NULL;

  while (curr) {
    Node* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
}

void LinkedList :: sort()
{
  int count = 0, i;
  Node *start = head;
  Node *curr = NULL;
  Node *trail = NULL;
  Node *temp = NULL;

  while(start != NULL) { //grab count
    count++;
    start = start->next;
  }

  for(i = 0; i<count; ++i) { //for every element in the list

    curr = trail = head; //set curr and trail at the start node

    while (curr->next) { //for the rest of the elements in the list
      if (curr->freq < curr->next->freq) { //compare curr and curr->next

        temp = curr->next; //swap pointers for curr and curr->next
        curr->next = curr->next->next;
        temp->next = curr;

        //now we need to setup pointers for trail and possibly head
        if(curr == head) //this is the case of the first element swapping to preserve the head pointer
          head = trail = temp;
        else //setup trail correctly
          trail->next = temp;
        curr = temp; //update curr to be temp since the positions changed
      }
      else if (curr->freq == curr->next->freq) { //compare curr and curr->next
        if (curr->word > curr->next->word) {
          temp = curr->next; //swap pointers for curr and curr->next
          curr->next = curr->next->next;
          temp->next = curr;

          //now we need to setup pointers for trail and possibly head
          if(curr == head) //this is the case of the first element swapping to preserve the head pointer
            head = trail = temp;
          else //setup trail correctly
            trail->next = temp;
          curr = temp; //update curr to be temp since the positions changed
        }
      }
      //advance pointers
      trail = curr;
      curr = curr->next;
    }
  }
}