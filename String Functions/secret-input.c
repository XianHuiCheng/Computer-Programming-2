/*INSTRUCTION: Write a program that takes a sequence of lines and displays each line with all four-letter words replaced by asterisks. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
char text [80]; //Note: I can increase character count
int length,i,count = 0;
//Getting user input
printf("Enter text: ");
fgets (text,80,stdin);
//Getting length of text variable to set as limit in the loop
length = strlen(text);

for (i=0; i <= length; i++){
    count++; //used to count each character in a word
    if (text[i]== ' '){
       count = 0; //count will reset once it encountered a whitespace and count another word again
    }
    //check if a word has 4 words
    if (count == 4){
        //check if the next word is a space or a new character (5+ characs)
        i+=1;
        //make sure that it will not replace words with 5+ characters
        if (text[i] == ' '){
        //go back 4 places and replace each characters with '*'
        i -= 4;
        text[i] = '*';
        i++;
        text[i]='*';
        i++;
        text[i] = '*';
        i++;
        text[i]='*';
        }
    }
}

//checking if the last word has 4 letters
if (text[length - 6]== ' '){ // 6 instead of 5 because fgets() adds a new line to the string
    //removing last word and replacing it with "****"
    text [length - 5] = '\0';
    strcat (text,"****");
        }

//printing result
printf ("Output: %s\n",text);
   return 0;
}
