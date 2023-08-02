#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int firstTable[3][3] = {{0,1,3},{2,5,0},{0,6,8}}; // given data by maam
int game = 0, try = 0;
int *pTry = &try;

//prints the current sudoku board
void printTable(int array[][3]) {
  printf("\nCurrent Table:");
  for (int i = 0; i < 3; i++) {
    printf("\n-------------\n|");
    for (int j = 0; j < 3; j++) {
      printf(" %d", array[i][j]); //print the value of the current cell
      //if the cell is empty, it replaces it with x
      if (array[i][j] == 0)
        printf("\bx");
      printf(" |");
    }
  }
  printf("\n-------------\n");
}

//clears out the contents of the board for us to generate a new board
void clearTable(int array[][3]){
    // Delete all contents inside the array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            array[i][j] = 0; //sets all the values of the board to 0
        }
    }
}

//generate 6 random numbers in the cell from 1-9
void randomizeTable(int array[][3]){
  int size [9] = {0}; // keeps track of generated numbers
  int row, col, num;
  srand(time(0));
  clearTable(array);
  for (int i = 0; i < 6; i++) { // Generate 6 random numbers for Gene
    do {
      num = rand() % 9 + 1; } // generate random numbers from 1 to 9
    while (size[num-1] == 1);  // check if the number has already been generated
      size[num-1] = 1; //sets that the number is already generated
    do {
      row = rand() % 3; //random row index
      col = rand() % 3; } //random column index
    while (array[row][col] != 0); //check is the cell is already filled with a number
    array[row][col] = num; //assign generated number to the cell
  }
}

int checkInput(int array[][3], int row, int col,int value) {
   // Check if the cell is empty (contains 0)
    if (array[row-1][col-1] != 0) {
        printf ("The cell in row %d & col %d is already taken. Try Again.\n\n",row,col);
        return 0; //invalid input
    }

  // check duplicates in box
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (array[i][j] == value) {
        printf ("\nWrong Answer! The number '%d' is already in the table. Please try again.\n",value);
        *pTry += 1; //keeps track of the number of tries when user guesses wrong
        printf("Number of Tries: %d/3\n\n", *pTry);
        return 0; //invalid input
      }
    }
  }

  return 1; //valid input
}


int playSudoku (int array[][3]){
  int row, col, value, choice,invalid;
  game++;
  //generate the board with the contents given by ma'am
  if (game == 1){
    for(int i = 0; i < 3; i++){
          for(int j = 0; j < 3; j++){
          array[i][j] = firstTable[i][j];
        }
  }
  } else { //after first game, generate a table with random values every time
  randomizeTable(array);
  }
  printTable(array);
   for (int i = 0; i < 3 && try < 3; i++) {
    //get user input
    do{ //loops if user input is not valid based on the function (checkInput)
      do{
           //exits function if number of tries is reached (3/3)
        if (try >= 3) {
          *pTry = 0;
          return 0;
        }

        invalid = 0;//resets value of invalid counter
        printf ("Data %d:\n  Enter row (1-3): ",i+1);
        scanf ("%d", &row);
        printf ("  Enter column (1-3): ");
        scanf ("%d", &col);
        if (row>3 || row <= 0 || col>3 || col <= 0){
            printf ("One of the parameters you entered is invalid. Only 1-3 is accepted.\n\n");
            invalid = 1;
      }
      }while (invalid == 1);// loops if user does not enter a number from range 1-3
     
      do{
        invalid = 0;
        printf ("  Enter the number to be inserted: ");
        scanf ("%d", &value);
        if (value>9 || value <= 0){
            printf ("  Invalid Input! Only numbers from 1-9 are accepted.\n");
            invalid = 1;
      }
      }while (invalid == 1); // loops if user does not enter a number from range 1-9

    }while(!checkInput(array,row,col,value));

         
//assigns the value to the array based on the row and column index
    array[row-1][col-1] = value; 
//prints the current table
    printTable(array);

   }
   return 1; //returns True if user succesfully solved the sudoku

}
     

int main(){
  int choice = 1;
  int table[3][3] = {{0}};
  char name[80], exit;
  //gets user's name
  printf("Enter your first name: ");
  scanf("%s", name);
  printf("Hi %s! Welcome to SudoKode.\n", name);
  do{
    printf("\nHere's your new Sudokode puzzle.\n");
    //calls function that generates the sudoku game
    //if playSudoku returns as true, the user has solved it
    if (playSudoku(table) == 1){ 
      printf("\nCongratulations %s, you have solved the SudoKode! :D", name);
    } else{ // otherwise, the user has no more turns
      printf("You lose! Number of tries has been reached.");
    }
    do{//Ask user to play again
      printf("\n\nDo you want to play again?\n[1] Yes\n[2] Exit\nInput Choice: ");
      scanf("%d", &choice);

       // checks if the user entered valid input and loops if it's not valid
      if (choice != 1 && choice != 2)
        printf("Invalid Input! Only numbers from 1-2 are accepted. Please try again.");

      //prompt to re-check if user wants to exit
      if (choice == 2) {
      printf("\nAre you sure you want to exit?\n");
      printf("Press 'Y' for Yes\nPress 'N' for No\nInput choice: ");
      scanf(" %c", &exit);
      if (exit == 'Y' || exit == 'y')
        break; //exits the loop
      else{
        choice = 1; //used to loop and start the game again
      }
    }
    } while (choice != 1 && choice != 2);
        
  }while (choice == 1);
  printf("\nThank you for playing!\n");
return 0;


}


