#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "queue.h"
#include "stack.h"

#define MAX_STR_LEN 256

/*
 * This function prompts the user for input and stores a maximum of `n`
 * characters of the string they enter into `dest`.  Any trailing line ending
 * characters are removed from the input string.  Returns 1 if a string was
 * successfully read from the user or 0 otherwise.
 */
int get_user_str(char* dest, int n) {
  printf("\nEnter a string, and we'll check whether it's a palindrome:\n");
  if (fgets(dest, MAX_STR_LEN, stdin) != NULL) {
    /*
     * If a string was successfully read from the user, remove any trailing
     * line ending characters.  Here's some documentation on strcspn() to help
     * understand how this works:
     *
     * https://en.cppreference.com/w/c/string/byte/strcspn
     */
    dest[strcspn(dest, "\r\n")] = '\0';
    return 1;
  } else {
    return 0;
  }
}

int comparechar(char a, char b){
  if(tolower(a) == tolower(b)){
    return 1;
  }else{
    return 0;
  }
}
//initialize variables
int main(int argc, char const *argv[]) {
  char* in = calloc(MAX_STR_LEN, sizeof(char));
  int arrSize; int i; int index;
  index = i = arrSize = 0;
  char* alpha_array = calloc(MAX_STR_LEN, sizeof(char));
  void* queueChar; void* stackChar;
  struct queue* q = queue_create(); struct stack* s = stack_create();
  int doAgain = 1; int notApali = 0;
  while (get_user_str(in, MAX_STR_LEN)) {
    
    for(int i = 0; i < MAX_STR_LEN; i++){
      if(isalpha(in[i]) != 0){ //this iterates through the user input and adds each element to the stack and queue
        stack_push(s, (void*)in[i]); //push the stack with the object and element
        alpha_array[arrSize] = in[i]; 
        queue_enqueue(q, (void*)in[i]); //push the queue with the object and element
        arrSize++;
      }
    }
      alpha_array[arrSize] = "\0";
      while(doAgain == 1){
        //pop and dequeue the stack and queue and compare the values. This will move the pointer from the furthest
        //bounds, high and low, inward. Then if the element of the dequeue and pop dont equal eachother, break the loop
        queueChar = queue_dequeue(q); stackChar = stack_pop(s);
        if(comparechar(queueChar, stackChar) == 0){
          notApali = 1; doAgain = 0; 
          //if a char is not equal break the loop and set the not a palidrome flag to true
          break;
        } //if both equal one break the while loop
        if(stack_isempty(s) == 1 || queue_isempty(q) == 1){
          //if both the stack and queue are empty it means that it must be a palidrome
          doAgain = 0; 
          break;
        }
        i++;
      }
      //if flag is 1 print not a palindrome
      if(notApali == 1){
         for(int i = 0; in[i] != '\0'; i++){
            printf("%c",in[i]);
           }
          printf(" %s\n", "aint no palidrome");
        }else{
          //else print 0
          for(int i = 0; alpha_array[i+1]!= '\0'; i++){
            printf("%c",alpha_array[i]);
            }
          
          printf(" %s\n", "is a paldrome");
        }
        break;
  }
      
  //free all of the allocated memeory
  
  stack_free(s); queue_free(q); free(in); free(alpha_array);
  return 0;

}
