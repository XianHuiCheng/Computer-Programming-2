/*INSTRUCTION: 
Pizza parlors offers different pizza sizes in terms of diameters. For example, Domino’s has three options: 10 inches, 12 inches, 14 inches diameter. Extravaganza pizza costing 178 pesos, 259 pesos and 314 pesos respectively. Write a program that will input the diameter of the pizza, and its price. Determine the (a) area of the pizza and (b) the price by the divided area. Find out which of the three options above (for Domino’s) is the least expensive in terms of price per square inch of pizza. Note that the area of a circle is equivalent to PI* (diameter / 2)2. */

#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159

int main() {
double diameter, price, area,price_per_sqr, radius, prevPrice, finalPrice, prevArea, finalArea;
int input,loop = 0, count =0;
printf ("\tWELCOME TO PIZZA PRICE CALCULATOR\n");

do {
    printf ("----------------------------------------------------\n");
    printf  ("Input the diameter of pizza (inches): ");
    scanf ("%lf", &diameter);
    printf ("Input the price of pizza: Php ");
    scanf ("%lf", &price);
//determine area of pizza
    radius = diameter/2;
    area = PI * radius *radius ;
//determine price per area
    price_per_sqr = price/area;
//display pizza calculations to user
    printf ("Area of the pizza: %.2lf \n", area);
    printf ("Price by the divided area (per sqaure inch):Php %.2lf \n",price_per_sqr);
//If input = 1, program will loop again. If input = 2, loop ends
    printf ("\nWould you like to calculate another pizza?\n");
    printf ("\t[1] Yes \n\t[2] No \n");
    printf ("Input number of choice:");
    scanf ("%d", &input);

    if (loop == 0){//before loop
        prevPrice = price_per_sqr;//sets the previous price and area as a value
        prevArea = area;}
    if (loop > 0) { //first loop
        finalPrice = price_per_sqr; //sets the present price and area as a value
        finalArea = area; 
        if (finalPrice > prevPrice){ //checks which pizza has the smaller cost
            finalPrice = prevPrice; //if finalPrice is larger, it will assign the smaller cost as a value for finalPrice and finalArea
            finalArea = prevArea;
            count--; //tracks which input version is the smallest
            }
    }
loop++; // tracks how many times the program loops
count++; // tracks how many times the user made a calculation

} while (input == 1);

if (loop > 1){ // if program loop = 0, this will not print
printf ("-------------------------------------\n");
printf ("Based on your previous calculations:\n");
printf ("Cheapest pizza: INPUT %d\n", count);
printf ("Area of the pizza: %.2lf\n", finalArea);
printf ("Price by the divided area (per sqaure inch): Php %.2lf\n",finalPrice);
}// Message that indicates the end of the program
printf ("\nThank you for using our program!\n");
return 0;

}
