/* INSTRUCTIONS:
  Assume a range of integer values starting from N1 and ending at N2. Assume also an integer say M. Write a program that will print and display all the numbers from N1 to N2 which are divisible by M. You are also required display the count of such numbers. For example, if N1 = 4, N2 = 12 and M = 4, the output will be: 4, 8, 12. The value 3 will also be displayed indicating that there are 3 numbers which are divisible by 4.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
int n1, n2, M,i;
int totalCount = 0;
//Getting user input
printf ("Enter a number(M): ");
scanf ("%d", &M);
printf ("Enter two numbers that you want to check divisibility with %d \n", M);
printf ("\t Enter starting number: ");
scanf ("%d", &n1);
printf ("\t Enter last number: ");
scanf ("%d", &n2);
printf("Numbers from %d to %d that are divisible by %d: ",n1,n2,M);
// loop through the range of values from n1 to n2
 for (i = n1; i <= n2; i++){
    if (i % M == 0){ //check if the current value of i is divisible by M
        // check if it's the last iteration of the loop to prevent adding comma at end
        if (i == n2 || i + M > n2) 
            printf("%d", i);
        else //if it's not the last iteration, it will print out a comma besides i
            printf("%d, ", i);
    }
    totalCount++; // tracks the count of numbers divisible by M
 }
//Display output to user
printf ("\nThe count of numbers that are divisible by %d: %d\n", M,totalCount);

return 0;

}
