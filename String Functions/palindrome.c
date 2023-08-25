#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int palindrome (int input);
int main() {
char userInput [80];
//Getting user input
printf ("Enter a word or phrase: ");
fgets (userInput, 80, stdin); 
//Removing the newline character when using fgets()
userInput[strcspn( userInput, "\n" ) ] = '\0';

printf ("%d", palindrome (userInput));

  return 0;
}

int palindrome (int input){
char reverse[80];
int result;
//copying the value of userInput to another variable
strcpy(reverse,input);
//reversing the string inside the reverse variable
strrev(reverse);

//Using strcmp() to compare the values of reverse & userInput
result = strcmp(reverse,input);

if (result == 0){ //Since strcmp() will return 0 if both strings are equal
    return 1;
}else {
    return 0;
}
}
