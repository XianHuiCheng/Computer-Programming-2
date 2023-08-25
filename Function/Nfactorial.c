#include <stdio.h>
long double factorial (int num){ //Function that calculates the result for n factorial
long double total = 1; //uising long double to prevent integer overflow
    for (int i = 1; i <= num; i++) {
      total *= i;}
    return total;
}
void solution (int num){ //fucntion that shows the solution for the factorial
  printf ("\nSolution:\n%d! = ",num);
  for (int i = num;i>0;i--){
    printf ("%d x ",i);
    if (i == 1)
      printf ("\b\b");} //erases "x" if it's the last number 
  printf ("= %1.0Lf\n", factorial(num)); //calling factorial function to show the total
}

int main() {
int num, choice,transact = 1;
do { 
printf ("\nInput a non-negative number: ");
scanf ("%d", &num);
// when the number is negative
if (num < 0)
    printf ("Invalid Input! Enter a positive integer. Try Again.\n");
  
else { //if user is a positive number
    printf ( "%d! = %1.0Lf\n", num, factorial(num)); //prints out the N factorial result
  //ask if user wants to see the solution for the N factorial
    printf ("\nWould you like to see the solution?\n[1] Yes\n[2] No\n"); 
    printf ("Enter number of choice: ");
    scanf("%d",&choice);
     if(choice == 1)
        solution(num); //If user chooses Yes, it will call the function for solution
  //determines if the program will loop or exit
    printf ("\nContinue calculation?\n[1] Yes\n[2] No\n"); 
    printf ("Enter number of choice: ");
    scanf ("%d", &transact);}
}while (transact == 1);
  
printf ("\nThank you for using our program!"); //end message to the user
  return 0;
}
