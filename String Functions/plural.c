/*INSTRUCTION: 
Write a program that takes nouns and forms their plurals on the basis of these rules:
a. if noun ends in “y”, remove the “y” and add “ies”
b. if noun ends in “s”, “ch”, or “sh” add “es”
c. in all other cases, just add “s”
Print each noun and its plural.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {

char noun [80],suffix[80],plural[80];
printf ("Enter a noun: ");
scanf ("%s",noun);
strcpy (plural,noun); //assigning the value of noun to plural variable
//Getting length of the noun
int length = strlen(plural); 
//Getting the last character of the string
char last_char = plural[length - 1];

//checking the value of the last character
if (last_char == 'y'){
    strcpy (suffix,"ies"); //assigning a value to suffix using strcpy
    plural[length - 1] = '\0'; //removing last character
}else if (last_char == 's'){
    strcpy (suffix,"es");
}else if (last_char == 'h'){
    if (plural[length - 2] == 'c'|| plural[length - 2] == 's'){
            strcpy (suffix,"es");
    }else { strcpy (suffix,"s");}
}else {
    strcpy (suffix,"s");
}

//concatenate noun with its plural suffix
strcat(plural,suffix);
printf("\n\t Noun: %s\n",noun);
printf ("\t Plural form: %s\n", plural);

   return 0;
}

