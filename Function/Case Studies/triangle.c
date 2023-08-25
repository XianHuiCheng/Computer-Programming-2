/*INSTRUCTION: Write a program to call function TRIANGLE to determine if a given sides is equilateral, isosceles or scalene.
 A triangle is EQUILATERAL if all the three sides have the same length. ISOSCELES if only two sides have the same length and SCALENE if no sides have the same length.
 Input the length of the three sides and print whether the triangle is equilateral, isosceles or scalene.*/

#include <stdio.h>
void TRIANGLE (int s1, int s2, int s3){
    if (s1 == s2 && s2 == s3)
       printf("The triangle is EQUILATERAL!\n");
    else if (s1 == s2||s1 == s3||s2 == s3)
       printf("The triangle is ISOSCELES!\n");
    else 
       printf("The triangle is SCALENE!\n");
}
int main() {
   int side[3], choice = 1;
    printf ("\n------- TRIANGLE TYPE IDENTIFIER PROGRAM -------\n");
  do{
    printf("\nEnter the length of three sides of a triangle:\n");
    for (int i = 0; i < 3; i++) { // Use a for loop to get input for each side of the triangle
        printf("Side %d: ", i+1);
        scanf("%d", &side[i]);
    }
   TRIANGLE(side[0],side[1],side[2]);
    
  //determines if program will loop or exit
  printf ("\nWould you like to test another number?\n");
  printf ("[1] Yes\n[2] No\nEnter number of choice: ");
  scanf ("%d",&choice);
  printf("----------------------------------------------\n");
} while(choice == 1); //loop as long as user wants to continue
  
printf ("\nThank you for using our program!\n");
  return 0;
}
