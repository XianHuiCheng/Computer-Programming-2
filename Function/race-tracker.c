/*INSTRUCTION: Four track stars have entered the mile race at the Penn Relays. Write a program that scans in the race time in minutes and seconds for a runner 
and computes and displays the speed in feet per seconds and in meters per seconds. Hint: there are 5280 feet in one mile, and one kilometer equals 3282 feet. 
Write and call a function that displays instructions to the program users.*/
#include <stdio.h>
int min,distance = 1, racer;
float sec,time,fps,mps;
void userInput();
void calculate();

int main() {

   for (racer = 1; racer <= 4; racer++){
    printf ("Racer # %d\n",racer);
    userInput();
    calculate();
  }

  return 0;
}

//function for getting user input
void userInput(){
    printf ("Enter race time in minutes: ");
    scanf ("%d", &min);
    printf ("Enter race time in seconds: ");
    scanf ("%f", &sec);
}

void calculate (){
    //converting time to sec
    min = min * 60;
    time = min + sec;

    //calculate feet per second (fps)
    int numFeet = distance * 5280;
    fps = numFeet/time;
    printf ("\t Speed in feet per second : %.2f fps\n", fps);

    //calculate minute per second (mps)
    int km = numFeet / 3282;
    int meter = km * 1000;
    mps = meter/time;
    printf ("\t Speed in meters per second : %.2f mps\n\n", mps);
}
