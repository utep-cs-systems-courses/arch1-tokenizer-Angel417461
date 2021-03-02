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
  char *clone = copy_str(str, len_of(str));
  Item *item = malloc(sizeof(Item)); // allocates memory to the size of struct Item
  if(list->root == NULL){ //checks to see if the list is empty
    item->id = 1;  // 1 because the assignment requests the id's to start at 1
    item->str = clone;
    list->root = item;
  }else{
    int id_count = 2; 
    Item *temp = list->root;
    while(temp->next != NULL){
      temp = temp->next;
      id_count++;
    }
    item->id = id_count;
    item->str = clone;
    temp->next = item;
  }
}
    
    

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  char * str; // will assign to and return later
  Item * temp = list->root;  // temp of type Item
  while(temp!=NULL){ // traversing the linked list
    if(temp->id == id){ // enter if the node has matching id
      str = temp->str;
      return str;
    }
    temp = temp->next;
  }
}


/*Print the entire contents of the list. */
void print_history(List *list){
  Item * temp = list->root; //creting tem
  while(temp != NULL){ // traverse entire linked list
    printf("%d. %s", temp->id, temp->str);
    temp = temp->next;
  }
}
/*Free the history list and the strings it references. */
void free_history(List *list){
  while(list->root != NULL){
    free(list->root);
    list->root = list->root->next;
  }
}

