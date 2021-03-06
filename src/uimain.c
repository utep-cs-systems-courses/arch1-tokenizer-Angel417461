#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  
  char in[100];
  char str[100];
  List *list = init_history();

   while(1){
      printf("--------menu--------\n");
      printf("a. enter a string\n");
      printf("b. print history\n");
      printf("q.quit\n");
      fgets(in, 100, stdin);
      printf("you entered: %s\n", in);
      
      if(string_compare(in, "a")){
	printf("enter your string below:\n");
	printf(">");
	fgets(str, 100, stdin);
	printf("%s", str);

	char ** input = tokenize(str);
	add_history(list, str);
	print_tokens(input);
	free_tokens(input);
      }
      if(string_compare(in, "b")){
	printf("------history-------\n");
	print_history(list);
      }
      if(in[0] == 33){ 
	char a = in[1];
	int id = a - '0';
	printf("History at %d is: %s\n", id, get_history(list, id));
      }
      if(string_compare(in, "q")){
	printf("goodbye\n");
	free_history(list);
	goto done;
      }
    }
 done:
 return 0;
}
 
