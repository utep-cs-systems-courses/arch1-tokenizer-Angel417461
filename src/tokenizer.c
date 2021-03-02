#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if (((c == 32) || (c == 9)) && c != '\0'){ // 32 is ascii for space and 9 is ascii for tab
    return 1;
  }
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */
int non_space_char(char c){
  if (!(space_char(c)) && c != '\0'){
      return 1;
    }
  return 0;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str){
  while(space_char(*str)){ // continue until the char is not a space
    *str++;
  }
  return str;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
  while(non_space_char(*word)){ // continue until the char is a space 
    *word++;
  }
  return word;
}
/* Counts the number of words in the string argument. */
int count_words(char *str){
  
  int count= 0;
  char *string = str;

  while(*string){// while string is not empty
    string = word_start(string);
    string = word_terminator(string);
    count++;
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *cp = malloc((len+1) * sizeof(char));  //allocates memory + 1 for last 0 token
  for(int i = 0; i < len; i++){
    cp[i] = inStr[i]; // where the actual copying happens
  }
  cp[len] = '\0'; // assigning the null terminator at the end of the copy string
  return cp;
}


/* Returns a freshly allocated zero-terminated vector of freshly allocated                            space-separated tokens from zero-terminated str.                                                            
   For example, tokenize("hello world string") would result in:            
     tokens[0] = "hello"               
     tokens[1] = "world"     
     tokens[2] = "string"   
     tokens[3] = 0          
*/                                                                          
char **tokenize(char* str){
  int num_words = count_words(str);
  char ** ptr = malloc((num_words+1) * sizeof(char*));
  str = word_start(str); // makes sure the string is not starting with any spaces
  for (int i = 0; i < num_words; i ++){  
    int len = word_terminator(str) - word_start(str); // finds the length of current word in the string
    ptr[i] = copy_str(str, len); // assigns the word to specific "token"
    
    str = word_terminator(str);
    str = word_start(str); 
  }
  ptr[num_words] = 0;
  return ptr;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  int i= 0;
  while(*tokens){
    printf("token[%d] = %s\n",i, *tokens);
    tokens++;
    i++;
  }
}
/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  while(*tokens){
    free(*tokens);
    tokens++;
  }
}

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

int len_of(char *x){
  int i;
  for(i = 0; x[i] != '\0'; i++);
  return i;
}
