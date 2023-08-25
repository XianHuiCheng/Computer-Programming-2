/* INSTRUCTION: The proper divisor of an integer N are the positive divisors less than N, a positive integer is said to be DEFICIENT, PERFECT or ABUNDANT numbers
 if the sum of its proper divisors is less than, equal to or greater than the number respectively. Write a program using function call by reference 
 to input integer N and call function KOMPUTE to determine of integer N is DEFICIENT, PERFECT or ABUNDANT .*/

#include <stdio.h>
int i, sum = 0;
void divisor (int *num, char sign){ //function that gets and calculates the proper divisors
  for (int i = 1; i < *num; i++){
        if (*num % i == 0){ 
            sum += i; 
            printf ("%d %c ",i,sign); //use to print out + or , in between
        } 
    }printf ("\b\b "); //erases the last space and sign 
      if (sign == '+')
          printf ("= %d",sum); //use to print the sum of proper divisors
}
void KOMPUTE (int *num){ //function to determine whether num is D,P, or A
  for (i = 1; i < *num; i++){
      if (*num % i == 0)
          sum += i; //Contains the sum of each proper divisors
  }// Determining whether it's DEFICIENT, PERFECT, or ABUNDANT
  if (sum < *num)
      printf ("\n%d < %d is DEFICIENT \n",sum,*num);
  else if (sum == *num)
      printf ("\n%d = %d is PERFECT \n",sum,*num);
  else
      printf ("\n%d > %d is ABUNDANT \n",sum,*num);
}
int main() { 
int N,choice = 1;
printf ("\nDetermine if integer is DEFICIENT, PERFECT or ABUNDANT\n");
do {
  printf ("\nEnter a positive integer: ");
  scanf ("%d",&N);
  // Making sure user input is positive
  if (N < 0) 
      printf ("The number you entered was negative. Try Again!\n");
  else {
      //Compute Proper Divisors and its sum
      printf ("Proper divisors: ");
      divisor(&N,','); //putting comma in between the proper divisors
      printf ("\nSum of proper divisors: ");
      divisor (&N,'+'); //putting + in between the proper divisors & printing sum
      KOMPUTE (&N);
//determines if program will loop or exit
  printf ("\nWould you like to test another number?\n");
  printf ("[1] Yes\n[2] No\nEnter number of choice: ");
  scanf ("%d",&choice);}
  printf("----------------------------------------------\n");
} while(choice == 1); //loop as long as user wants to continue
  
printf ("\nThank you for using our program!\n");

  return 0;
}
