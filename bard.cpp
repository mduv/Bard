/// This is the main program ///


#include <iostream>
#include "linkedlist.h"
#include <stack>
#include <stdexcept>
#include <fstream>
#include <array>
#include <vector> 
#include <algorithm>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

#define MAX_LEN 500
  
int main(int argc, char * argv[]) {

    // initialize linked list
    LinkedList myList;

    // read in shakespeare words
    char const* const fileName = "shakespeare-cleaned5.txt";
    
    // open shakespeare file for reading
    FILE* file = fopen(fileName, "r");


    // if not file 
    if (!file) {
      printf("Unable to open file\n");
      return -1;
    }

    // get line
    char line[MAX_LEN];

    int size = 37;
    LinkedList arr_link[size];

    // insert shakespeare word into linked list
    while(fgets(line, sizeof(line), file) != NULL) {
      strtok(line, "\n");
      myList.insert(line);
    }
    
    myList.sort();
    

    // close file
    fclose(file);

    

    Node *curr = myList.head; 
    while (curr) {
      arr_link[curr->len].insert(curr->word);
      curr = curr->next;
    }
    

    FILE *in, *out;
    // check command line for correct number of arguments
    if( argc != 3 ){
      printf("Usage: %s <input file> <output file>\n", argv[0]);
      exit(1);
    }
    // open files for reading and writing 
    in = fopen(argv[1], "r");
    if(in==NULL){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
    }
    out = fopen(argv[2], "w");
    if(out==NULL){
      printf("Unable to open file %s for writing\n", argv[2]);
      exit(1);
    }
    rewind(in);
    int len,rank;
    while(fscanf(in, "%d\t%d", &len, &rank) != EOF) {
      string gotem;
      if (len >= size) {
        gotem = "-";
      } else if (!(arr_link[len].head)) {
        gotem = "-";
      } else if (rank >= arr_link[len].length()) {
        gotem = "-";
      } else {
        Node* temp = arr_link[len].head;
        for (int i = 0; i < rank; i++) {
        temp = temp->next;
        }
        gotem = (temp->word);
      }
      fprintf(out, "%s\n", gotem.c_str());
    }
    
    fclose(in);
    fclose(out);
    return 0;
};