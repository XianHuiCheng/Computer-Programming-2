#include <stdio.h>
#include <stdlib.h>
int main(){
unsigned int num;
int total;
int sum = 0;
int i = 0;
printf ("Enter a non-negative integer: ");
scanf ("%d", &num);
// Getting the Factors of num
printf ("Factors are ");
while (i < num){
    ++i;
    total = num / i;
    if (num % i == 0 && i < num){
    sum += i; /* Getting the sum of its factors
    (Adding the loops previous value with its current value) */

    printf ("%d ", i); // printing its factors
}
}
printf ("\nSum of its factors: %d\n", sum);
int half = num / 2;
printf ("Half of %d: %d", num, half);

if (sum > half){
    printf ("\n\n\t %d is DWARF\n",num);
} else {
    printf ("\n\n\t %d is NOT DWARF\n", num);}
}