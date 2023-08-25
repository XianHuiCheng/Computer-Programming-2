/*A famous conjecture, called the GOLDBACH conjecture, says that every even integer n greater than 2 has the property tat it is the sum of two prime numbers. Computers have been used extensively to test this conjecture. No counter example has been found. Write a program the will prove that the conjecture is true for all the even integers between the symbolic constants START and FINISH. For example, if you write:
#define START 700
#define FINISH 1100
Then the output of your program might look like this:
Every even number greater than 2 is the sum of two primes:
700 = 17 + 683
702 = 11 + 691
704 = 3 + 701
:
1098 = 5 + 1093
1100 = 3 + 1097
*/

#include <stdio.h>
#define START 700      
#define FINISH 1100   
int counterExample = 0;
//function to check if number is prime
int is_prime(int num) { 
// returns 1 if num is prime, 0 otherwise
  for (int i = 2; i < num; i++){
    if (num % i == 0)
      return 0;
  }if (num <= 1) //classifies 0 and 1 as NOT prime
      return 0;
  else
      return 1;  
}

// function to find 2 prime numbers that add up to an even number to prove goldbach conjecture true
void goldbach (int num){
  int track = 0; //use to track if there's a counterexample 
  // loop through all pairs of prime numbers that add up to num
    for (int i = 2; i <= num/2; i++) {
      if (is_prime(i) && is_prime(num-i)) { //checks if both i and num-i are prime
        track = 1; 
        printf("%d = %d + %d\n", num, i, num-i);
        break;
      }
    }
    if (!track) { // if track is false then no pair of primes adds up to num (proves goldbach as false)
      printf("Counterexample found: %d cannot be written as the sum of two primes.\n", num);
      counterExample = 1;
    }
}

int main() {
printf ("\n\n---- Program which checks if the Goldbach Conjecture is true! ----\n");
printf ("Goldbach Conjecture: every even integer n greater than two has the property that its the sum of 2 prime numbers\n\n");
  
printf("Proving the Goldbach conjecture for even numbers from %d to %d:\n", START, FINISH);
  for (int num = START; num <= FINISH; num += 2) { // loop through all even numbers between START and FINISH
    goldbach (num);  // fcalling goldbach function to find 2 primes that add up to num
}if (counterExample == 0)
    printf("\nConclusion:\nThe Goldbach conjecture is TRUE for all even numbers between %d and %d!\n", START, FINISH);
else
    printf ("The Goldbach conjecture was found FALSE because of the counterexample");
return 0;
}

