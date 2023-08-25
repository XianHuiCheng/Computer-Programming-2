/*INSTRUCTION: Two positive integers i and j are considered to be relatively prime if there exist no integer greater than 1 that divides them both.
 Write a function rel_prime that has two input parameters, I and j, and returns a value of 1 if and only if I and j are relatively prime. 
Otherwise, rel_prime should return a value of 0.*/

#include <stdio.h>
int rel_prime (int i,int j) {
int loop,result;
    for (loop = 1; loop <= i ; loop++){
        //finding common factors
        if (i % loop == 0 && j % loop == 0 )
          result = loop;
    }//determining if they have 1 or more common factors through how much it looped
    if (result == 1)
        return 1;
    else 
        return 0;
}

int main() {
int num1,num2,choice = 1;
printf ("\n---- RELATIVE PRIME NUMBERS CALCULATOR ----\n");
do {
printf ("\nEnter first non-negative number: ");
scanf ("%d", &num1);
printf ("Enter second non-negative number: ");
scanf ("%d", &num2);
if (num1 < 0 || num2 < 0) // when the number is negative
    printf ("The number you entered was negative. Try Again!\n");
else {
    if (rel_prime(num1,num2) == 1) 
      printf ("%d and %d are RELATIVELY PRIME!\n",num1,num2);
    else
      printf ("%d and %d are NOT relatively prime!\n",num1,num2);

//determines if program will loop or exit
  printf ("\nWould you like to test another number?\n");
  printf ("[1] Yes\n[2] No\nEnter number of choice: ");
  scanf ("%d",&choice);}
  printf("----------------------------------------------\n");
} while(choice == 1); //loop as long as user wants to continue
  
printf ("\nThank you for using our program!\n");

  return 0;
}
