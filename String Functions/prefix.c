/* INSTRUCTION: Write and test a function that finds the longest common prefix of two words(e.g. the longest common prefix of “global” and “glossary” 
is “glo”, of “department” and “depart” is “depart”, and of “glove” and “dove” is the empty string);*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
char word1[80],word2[80],result[80];
int limit,i;

printf ("Enter first word: ");
scanf ("%s",word1);
printf ("Enter second word: ");
scanf ("%s",word2);

//converting strings to lowercase
strlwr(word1);
strlwr(word2);

//Getting length of common first characters
limit = strspn(word1,word2);

//loop until they reach the end of their common first characters
for (i = 0; i<limit; i++ ){
    result [i] = word1[i];
}

//adding a null terminator at the end of result variable
result[i] = '\0'; //Note: I can also use [limit] as the index to indicate the end
printf("%s",result);

}