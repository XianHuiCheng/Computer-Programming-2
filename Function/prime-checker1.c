/*INSTRUCTION: An integer is considered prime if its only factors are 1 and itself. 1 can be considered a prime integer because its factors are 1 and only
 1. Write a program that will input a nonnegative and would call the function prime that returns 0 for true and 1 for false.
  (Precondition: Test if the entered value is nonnegative)*/
#include <stdio.h>
int num,i;
int prime(); // Function Declaration

int main() {
printf ("Enter non-negative number: ");
scanf ("%d", &num);

// when the number is negative
if (num < 0){
    printf ("The number you entered was negative\n");
}else {
    printf ("%d \n", prime ());
    }

  return 0;
}

int prime() {
    for (i = 2; i < num; i++){
        if (num % i == 0){
        return 1;
        }
    }if (num == 0 || num == 1){
        return 1;
    }else {
        return 0;
    }
}
