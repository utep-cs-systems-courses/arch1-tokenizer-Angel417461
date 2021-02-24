#include <stdio.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if ((c == 32) || (c == 9)){
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
  //str = word_terminator(str);
  while(space_char(*str)){
    *str++;
  }
  return str;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
  while(non_space_char(*word)){
    *word++;
  }
  return word;
}
/* Counts the number of words in the string argument. */
int count_words(char *str){
  int count= 0;
  char *string = str;

  while(*string){
    string = word_start(string);
    //printf("%s\n", string);
    string = word_terminator(string);
    //printf("%s\n", string);
    count++;
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *cp = malloc((len+1) * sizeof(char));
  for(int i = 0; i < len; i++){
    cp[i] = inStr[i];
  }
  cp[len] = '\0';
}


/* Returns a freshly allocated zero-terminated vector of freshly allocated                                          
   space-separated tokens from zero-terminated str.                                                            
   For example, tokenize("hello world string") would result in:            
     tokens[0] = "hello"               
     tokens[1] = "world"     
     tokens[2] = "string"   
     tokens[3] = 0          
*/                                                                          
/*char **tokenize(char* str){
  int num_words = word

  
  }*/












