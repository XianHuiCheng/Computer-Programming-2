#include <stdio.h>
int conversion (int time){ //Calculation in converting 24 hour notation to 12 hour notation
int hour,min, period = 0;
// Converting hour and minute from the input time
hour = time / 100;
min = time % 100;
if (hour < 12)  //Determine if AM or PM
    period = 1;
else{
    period = 0;
    hour = hour - 12; // Converting hour to 12-hour notation
}if (hour == 0)  //Converts hour if time is 12PM
    hour = 12;

if (period == 1) //Print result whether if it's AM or PM
  printf ("%d:%02d AM\n",hour, min);
else 
  printf ("%d:%02d PM\n",hour, min);
  }

int main() {
int time,error,invalid,choice = 1;
while (choice == 1){ //loop as long as user wants to continue
  printf ("\nEnter time in 24-hour notation: ");
  scanf ("%d", &time);
  //user input must be from 0 to 2400
  if (time < 0 || time > 2400){
        printf ("Invalid input: Time must be from 0 to 2400! Try Again.\n");
        continue;
  }else { //checking if the minutes do not exceed 60 since minutes only go from 0 to 59
    invalid = 0;
      if (time < 1000){
        error = (time/10)%10;
        if (error>=6)
          invalid = 1;
      }else{
        error = time % 100;
        if (error >= 60)
          invalid = 1;
      }if (invalid == 1){
        printf ("INVALID INPUT!\nChange minutes part of time to 00 to 59. Try Again!\n",time);
        continue;}
  } 
  printf ("12 Hour Format: ");
  conversion(time); //if there's no error with user input
//determines if program will loop or exit
  printf ("\nWould you like to convert again?\n");
  printf ("[1] Yes\n[2] No\nEnter number of choice: ");
  scanf ("%d",&choice);
  printf("---------------------------------------------------------\n");
}
printf ("\nThank you for using our program!\n");
  return 0;
}
