/*INSTRUCTION:
Write a program to ask the user to input the name of boy and name of girl. Count the number of common letters to their names and add them up. Determine the corresponding equivalent using the game FLAMES!
Example:
Name of Boy : John Victor Name of Girl : Vicenta Joy
Number of common letters Boy: 8 (J, o n,V,i,c,t,o)
Name of common letters Girl : 7 (V,i,c,n,t,J,o)
Total Number : 15 – Angry
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int common_letter(char input[], int size);
int main() {
char boy[80],girl[80],input1[80],input2[80],result[80],status[80];
int i,boySize,girlSize,diff,j,length,count=0;

printf ("PLAY A GAME OF FLAMES!\n");
printf ("\tName of Boy: ");
fgets (boy,80,stdin);
printf ("\tName of Girl: ");
fgets (girl,80,stdin);

//Removing the newline character when using fgets() to accurately get the length
boy[strcspn(boy, "\n" ) ] = '\0';
girl[strcspn(girl, "\n" ) ] = '\0';

//getting the length of the strings
boySize = strlen(boy);
girlSize = strlen (girl);

//convert string to lower case
strlwr(boy);
strlwr(girl);

//copying input
strcpy (input1,boy);
strcpy (input2,girl);

//Boy:
for (i=0;i <= boySize;i++){
    diff = strspn(input1,girl);
    if (diff == i || input1[i] == ' ' ){
        j = i;
        while(j < boySize){
            input1[j] = input1[j+1];
            j++;
        }boySize--;
        i--;
    }
}

for (i=0;i <= girlSize;i++){
    diff = strspn(input2,boy);
    if (diff == i || input2[i] == ' ' ){
        j = i;
        while(j < girlSize){
            input2[j] = input2[j+1];
            j++;
        }girlSize--;
        i--;
    }
}
//getting number of common letters
boySize = strlen (input1);
girlSize = strlen (input2);

//get the total number of characters when combined
length = boySize + girlSize;

//determining FLAMES
for (i=0; i < length;i++){
        count++;
    if (count == 7){
        count = 1;
    }

}
switch (count){
case 1:
    strcpy(status,"Friends");
    break;
case 2:
    strcpy(status,"Lovers");
    break;
case 3:
    strcpy(status,"Angry");
    break;
case 4:
    strcpy(status,"Marriage");
    break;
case 5:
    strcpy(status,"Enemies");
    break;
case 6:
    strcpy(status,"Soulmates");
    break;
default:
    strcpy (status,"Strangers"); //This is a joke lol
}
printf ("\tNumber of common letters Boy: ");
common_letter(input1,boySize);
printf ("\tNumber of common letters Girl: ");
common_letter(input2,girlSize);
printf ("\tTotal Number: %d - %s",length,status);

   return 0;
}

//function that displays the size and the common letters with a comma 
int common_letter(char input[], int size){
int i;
    printf("%d ",size);
    printf ("(");
    size -= 1; //since array starts at 0, and I need to ouput the last charac with no comma(,)
    for (i = 0; i < size;i++){
        printf ("%c,",input[i]); //seperate the letters with comma
    }
    printf ("%c",input[i]);//print the last char with no comma
    printf (")\n");
}
