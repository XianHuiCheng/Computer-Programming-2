/*INSTRUCTION:
Write a program to input your password. Password must be invisible or may not be seen by the user as you input your password*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
char input[80],i,password[] = "XianHuiCheng";
int check;
printf ("Enter password: ");
//using getch so input won't be echoed
//sentinel: as long as char input is not equal to 13 (ASCII: Enter), it will loop
for (i=0; (input[i] = getch()) != 13 ; i++){
if (input[i] == 8){ //if user inputs backspace (ASCII: 8)
    printf ("\b");//prints backspace on screen to erase previous input
    i-=2;//go back to the previous letter index
    continue;// repeat loop and not execute the code under
}
printf ("*"); // printing * every letter
}
input[i] = '\0'; //terminates password when done looping

//check if input is same as password
check = strcmp (input,password);
if (check == 0)
    printf ("\nLog-in successful!\n");
else
    printf ("\nIncorrect Password.\n");

return 0;

}
