#include <stdio.h>
#include <stdlib.h>

int main(){
int num, i; // Note: I could also use unsigned int 
int total = 1;
printf("Enter non-negative number: ");
scanf ("%d ", &num);

// when the number is negative
if (num < 0){
        printf ("The number you entered was negative\n");
// when the number is equal to 0
}else if (num == 0){
        printf ("%d! = 1", num);
// Note: it can only do 12! and not 13 and above
}else {
    for (i = 1; i <= num; i++) {
        total *= i;}
    printf ( "%d! = %d\n", num, total);
  }
}
