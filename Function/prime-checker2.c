/*INSTRUCTION: Write a function int is_prime (int n) that returns 1 if n is prime and 0 otherwise. Hint: if k and n are positive integer, then k divides n if and only if n % k has value 0*/
#include <stdio.h>
int is_prime(int n) {
    for (int k = 2; k < n; k++){
    //for it to be prime every iteration must NOT have a remainder of 0
        if (n % k == 0)
           return 0;//breaks the loop if current i value is NOT prime
        
        if (n == 0|| n == 1) //classifies 0 and 1 as NOT prime
          return 0;
        else //indicates that num is PRIME
          return 1;}
}

int main() {
int input,choice=1;
do{ 
printf ("\nEnter non-negative number: ");
scanf ("%d", &input);

// when the number is negative
if (input < 0) //loops again if user enters a negative number
    printf ("The number you entered was negative. Try Again!\n");
else {
  if (is_prime(input) == 1)//checks if return value of is_prime() is PRIME
      printf ("%d is a PRIME number!\n", input);
  else //if return value of is_prime() is 0 
      printf ("%d is NOT a prime number!\n",input);
//determines if program will loop or exit
  printf ("\nWould you like to test another number?\n");
  printf ("[1] Yes\n[2] No\nEnter number of choice: ");
  scanf ("%d",&choice);}
} while(choice == 1); //loop as long as user wants to continue
  
printf ("\nThank you for using our program!\n");
return 0;
}

