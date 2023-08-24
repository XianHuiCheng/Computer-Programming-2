#include <stdio.h>
#include <stdlib.h>
int main() {
    int num, i;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("Prime factorization of %d is: \n", num);

    for (i = 2; i <= num; i++) { // loop through numbers from 2 to n, since 1 is not prime
       //check prime factors of num
        while (num % i == 0) {
            printf("%d x ", i);
            num = num / i; //divide n by i
        }
    }
    printf("\b\b"); // removes the last x and space characters
    printf ("= %d\n",num);

    return 0;
}
