#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int string_compare(char*x, char *y){
  while (*x != '\0' || *y != '\0'){
    if (*x == *y){
      x++;
      y++;
    }else{
      return 0;
    }
    return 1;
  }
}

int main(){
  
  char in[100];
  char str[100];
  List *list = init_history();

  add_history(list, "happy alone");
  add_history(list, "spiral staircase");
  print_history(list);
  
  void menu(){
    /*printf(">");
    fgets(str, 100, stdin);
    printf("%s", str);
    //scanf("%s", str);
    //printf("%s\n", str);

    char ** input = tokenize(str);
    add_history(list, str);
    print_tokens(input);
    free_tokens(input);*/
    
    }

  
  /* while(1){
      printf("------menu------\n");
      printf("a. enter a string\n");
      printf("b. print history\n");
      printf("q.quit\n");
      //scanf("%s", in);
      fgets(in, 100, stdin);
      printf("you entered: '%s'\n", in);

    //if(input[0] == '!'){
      
    
      if (string_compare(in, "a")){
	printf("enter your string below:\n");
	printf(">");
	fgets(str, 100, stdin);
	printf("%s", str);

	char ** input = tokenize(str);
	add_history(list, str);
	print_tokens(input);
	//free_tokens(input);
      }
      if(string_compare(in, "b")){
	printf("------history-------\n");
	print_history(list);
      }
      if(string_compare(in, "q")){
	printf("goodbye\n");
	goto done;
      }
    }
 done:
 return 0;*/
}
