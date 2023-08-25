/*INSTRUCTION:
Write a program to input your password. Password must be invisible or may not be seen by the user as you input your password. If the password is correct, call function Pig_Latin_Converter
Rules for Pig Latin –
Each word is converted individually according to the following rules:
 1. If the word has no vowels (other than 'y', e.g. "my", "thy") append "yay" to it -- i.e., "myyay", "thyyay".
 2. If the word begins with a vowel (e.g., "art", "else") append "yay" to the word (i.e., "artyay", "elseyay").
 3. If the word begins with a consonant (e.g., "song", "pig") divide the word at the first vowel, swapping the front and back halves and append "ay" to the word (i.e., "ongsay", "igpay")
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Pig_Latin_Converter (char password[80]);

int main() {
char input[80],i,password[] = "Anaconda";
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
if (check == 0){
    printf ("\nLog-in successful!\n");
    Pig_Latin_Converter (input); //calling function
}else
    printf ("\nIncorrect Password.\n");


return 0;

}
//Note: FIX FUNCTION parameter
void Pig_Latin_Converter (char password[80]){

char vowel[] = "aeiouAEIOU", prefix[]= " ";//needs to be string since we use strcat
int compare, checkY,length,i;
length = strlen (password); //get length of password
compare = strcspn (password,vowel); //can change vowel to "aeio.."
checkY = strcspn (password, "yY"); //check if there is a 'y' character


//if no vowels other than y or if the word begins with a vowel
if (compare == 0 || (compare == length && checkY != length)) //since if there's no match, strcspn returns the length
    strcat(password,"yay");
//if the word begins with consonants
else if (compare != 0){
    prefix[0] = password [0];
    //delete first element:
    for (i=0; i<length;i++){
        password[i] = password [i+1];
    } //concatenate
    strcat (password,prefix);
    strcat (password,"ay");
}
printf ("%s\n", password);
}
