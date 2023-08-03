/* INSTRUCTION:
  An applicant will be accepted to the Jedi Knight Academy if he is at least 200 cm tall; age is between 21 and 25 inclusive, and a citizen of the Planet Endor. However, if the applicant is recommendee of Jedi Master Obi Wan, he is accepted automatically regardless of his height, age and citizenship. Write a program that would input the applicant’s height, age, citizenship code (1- citizen 0-not citizen) and recommendee’s code (1- recommended 0- not recommended) and then output whether the applicant is accepted or rejected */

#include <stdio.h>
#include <stdlib.h>
int main() {
float height;
int age, citizen, recommend; 
char name[80];
//Asking for the user's first name to make the program friendly
printf("Enter your first name: ");
scanf("%s", name);
//Asking if the user is a recomendee of Jedi Master Obi Wan
printf ("\nAre you a recommendee of Jedi Master Obi Wan? \n");
printf ("\tIf YES: Press \'1\' \n");
printf ("\tIf NO: Press \'0\' \n");
printf ("\tAnswer: ");
scanf ("%d", &recommend);

//If user is recommendee then it will execute the code under and exit the conditional
if (recommend == 1)
    printf ("\nYou are ACCEPTED because you were recommended by Jedi Master Obi Wan!\n");
// If not a recomendee, the user must pass the three requirements to enroll
else if (recommend == 0){
  printf ("\nEnter your height in cm: ");
  scanf ("%f", &height);
    if (height >= 200){ //Check if the user's height meets the requirement
        printf ("\tYou passed the height requirement! \n");
        printf ("\nEnter your age: ");
        scanf ("%d", &age);
//executes if user passes height requirement; check if the user's age is within the age range
            if(age >= 21 && age <= 25){
              printf ("\tYou passed the age requirement! \n");
              printf ("\nAre you a citizen of Planet Endor? \n");
              printf ("\tIf YES: Press \'1\' \n");
              printf ("\tIf NO: Press \'0\' \n");
              printf ("\tAnswer: ");
              scanf ("%d", &citizen);
//executes if user passes age range; check if the user meets the citizenship requirement
                if (citizen == 1){
                   printf ("\tYou passed the citizenship requirement!\n");
                   printf ("\nCongratulations! %s, You met all the needed requirements to enroll at the Jedi Academy!\n",name);
              }else
              printf("\nSorry, %s you are rejected. You did not meet the citizenship requirement \n",name);
          }else 
              printf("\nSorry, you are rejected. You did not meet the age requirement \n");
      } else
          printf("\nSorry, you are rejected. You did not meet the height requirement \n");
}else //executes if user did not satisfy the first two main conditions
  printf("Invalid Input");

//Message to indicate end of program 
printf ("\nThank you for using our program\n");
return 0;
}
