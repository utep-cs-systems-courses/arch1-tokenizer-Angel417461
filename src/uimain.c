#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main(){
  
  char str[100];
  
  printf(">");
  fgets(str, 100, stdin);
  printf("%s", str);

  char ** input = tokenize(str);
  print_tokens(input);
  free_tokens(input);

  return 0;

  //printf("%d\n", space_char('f'));
  //printf("%d\n", space_char(' '));
  //printf("%d\n", non_space_char('f'));
  //printf("%d\n", non_space_char(' '));
  //printf("%s\n", word_start(str));
  //printf("%s\n", word_terminator(str));
  //printf("%d\n", count_words(str));
  //char ** a = tokenize(str);
  //print_tokens(a);
  //free_tokens(a);
}
