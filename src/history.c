#include <stdlib.h>
#include <stdio.h>
#include "history.h"


/* Initialize the linked list to keep the history. */
List* init_history(){
  List * list = malloc(sizeof(List));
  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  Item *item = malloc(sizeof(Item)); // allocates memory to the size of struct Item
  if(list->root == NULL){ //checks to see if the list is empty
    item->id = 1;  // 1 because the assignment requests the id's to start at 1
    item->str = str;
    list->root = item;
  }else{
    int id_count = 2; 
    Item *temp = list->root;
    while(temp->next != NULL){
      temp = temp->next;
      id_count++;
    }
    item->id = id_count;
    item->str = str;
    temp->next = item;
  }
}
    
    

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id);

/*Print the entire contents of the list. */
void print_history(List *list);

/*Free the history list and the strings it references. */
void free_history(List *list);
