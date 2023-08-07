#include <stdio.h>
#include <stdlib.h> 
int arrayHard[9][9] = {{0}};
int arrayEasy[3][3]={{0}};

//this function prints the current sudoku board depending on the size
void printTable(int size) {
  switch (size){
    case 3:{ //if the user picks the 3x3 board
      for (int i = 0; i < 3; i++) {
        printf("\n-------------\n|");
        for (int j = 0; j < 3; j++) {
          printf(" %d", arrayEasy[i][j]); //print the value of the current cell
          //if the cell is empty, it replaces it with a space
          if (arrayEasy[i][j] == 0)
            printf("\b "); //replaces 0 with an empty cell
          printf(" |");
        }
      }
      printf("\n-------------\n");
      break;
  
    }case 9:{//if the user picks the 9x9 board
      printf("-------------------------\n");
      for(int i=0;i<9;i++){
      printf("| ");
        for(int j=0;j<9;j++){
          if(arrayHard[i][j]==0)
            printf(". "); //replaces 0 with a dot
          else //if it's not 0, it will print the value of the current cell
            printf("%d ",arrayHard[i][j]); 
        //adds a vartical line after every 3 cells/columns
          if((j+1)%3==0 )
            printf("| ");}
      //adds a horizontal line after every 3 rows
      if((i+1)%3==0 )
          printf("\n-------------------------");
  
      printf("\n");
     } break;
    }
  }
}
// This function deletes all contents inside the array
void clearTable(int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          if(size == 3) //if size of the board is 3x3
            arrayEasy[i][j] = 0; 
          else //if size of the board is 9x9
            arrayHard[i][j] = 0;
        }
    }
}

int verifyTable (int row, int col, int value, int size){
  int i, j;
  //convert the row and column into 0-based index
  row = row - 1; 
  col = col - 1;
  if (size == 3){ //if size of board is 3x3
    if (arrayEasy[row][col] != 0) {
        return 0; //invalid input: the cell already contains a value
    }
     // check duplicates in the 3x3 box
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        if (arrayEasy[i][j] == value) 
          return 1; //invalid input
      }
    }
   return 2; //valid input
  }
  else{//if size of board is 9x9
    if (arrayHard[row][col] != 0) {
        return 0;  //invalid input: the cell already contains a value
    } 

    //check if the value is present in the same row or column
    for(i = 0; i < 9; i++){
      if(arrayHard[row][i] == value ||arrayHard[i][col] == value)
        return 1; // invalid input: duplicate found in the row or column
    }
    
  // check duplicates in each 3x3 square sub-grid
    int squareRow = (row / 3) * 3; // calculate starting index of row in the 3x3 box
    int squareCol = (col / 3) * 3; //calculate staring index of column in the 3x3 box
    
    //loops over the cell within the 3x3 box and checks for duplicates
    for (i = squareRow; i <= squareRow + 2; i++) { 
      for (j = squareCol; j <= squareCol + 2; j++) {
        if (arrayHard[i][j] == value)
          return 1; // invalid input
      }
    }
    return 2; //valid input
  }
}

int getInput (int input, int size){
  int row, col, value, invalid,limit;
  printTable(size);
  for (int i=0; i < input; i++){
    //get user input
    do{ //loops if user input is not valid based on the function (checkInput)
      do{
        invalid = 0;//resets value of invalid counter
        printf ("\nData %d:\n  Enter row (1-%d): ",i+1,size);
        scanf ("%d", &row);
        printf ("  Enter column (1-%d): ", size);
        scanf ("%d", &col);
        if (row>size || row <= 0 || col>size || col <= 0){
            printf ("The parameter/s you entered is invalid. Only 1-%d is accepted.\n\n", size);
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
      switch (verifyTable(row, col, value,size) ) 
      {
      case 0:
        printf ("The cell in row %d & col %d is already taken. Try Again.\n\n",row,col);
        break;
      case 1:
        printf ("\nNo Duplicates Allowed: The number '%d' will result to an invalid puzzle.\n",value);
        break;
      } 
    }while(verifyTable(row, col, value, size) != 2);
    if (size == 3){ //assigns value to the current cell
      arrayEasy [row-1][col-1] = value;
    }else
      arrayHard[row-1][col-1] = value;

    //prints the current table
    printTable(size);

  }
}

int solveSudoku(int size){
  int i,j, num = 1; 
    for (i = 0; i < size; i++){//iterate over rows
      for (j = 0; j < size; j++){//iterate over columns
      //if the size of the board is 3x3
        if (size == 3){ 
          if (arrayEasy[i][j] == 0){ //checks if cell is empty
      //if there are no duplicates in the cell, it places num at the current cell
              if (verifyTable(i+1,j+1,num,size) == 2)
                arrayEasy[i][j] = num;
              else{
                num++; //increment num to try next number
                j--; // move back one column to recheck the cell
                continue;}
          }
        }else{ //if the size of the board is 9x9
          if (arrayHard[i][j] == 0){ //checks if cell is empty
            for (num = 1; num <= size; num++){ //loop from num 1-9
      //if there are no duplicates in the cell, it places num at the current cell
              if(verifyTable(i+1,j+1,num,size) == 2){ //
                arrayHard[i][j] = num;
                if (solveSudoku(size)) //recursively call solveSudoku function
                  return 1;//exit function and return 1 if sudoku is solved
              
              arrayHard[i][j] = 0;}//If sudoku is not solved, reset current value of cell 
          }
          return 0;}
      }
    }
  }
  return 1;//if sudoku is solved
}

int main(){ 
  int tableSize, size, limit, input, choice, play,exit;
  printf ("\n------ Welcome to Sudoku Solver! ------\n");
  do{
  tableSize = 0;
  input = 0;
  while (tableSize != 1 && tableSize != 2){
    printf ("\nChoose your board size:\n[1] Easy (3x3)\n[2] Hard (9x9)\nInput Choice: ");
    scanf ("%d", &tableSize);
    if (tableSize != 1 && tableSize != 2)
      printf ("Invalid Input! Try Again\n");
  }
  if(tableSize == 1){
    size = 3;
    limit = 6; }
  else{
    size = 9;
    limit = 25;}

    clearTable(size); 
    while (input < 1|| input > limit){
      printf ("\nEnter number of data you want to input (1-%d): ",limit);
      scanf("%d", &input);
      if (input <1 || input > limit)
        printf ("Invalid Input! Only enter numbers from 1-%d. Try Again.\n\n", limit);
    } getInput(input, size); 

    choice = 0; 
    while (choice != 1){
      printf ("\nPress [1] to see solved board\nInput choice: ");
      scanf ("%d", &choice);
      if(choice != 1)
        printf ("Invalid Input! Try Again");
    }
    if (solveSudoku(size)){ 
        printf ("\nSudoku Problem has been solved!\n");
        printTable(size);
    }else
        printf ("\nNo solution found in this board.\n");
    do{
      printf("\nDo you want to play again?\n[1] Yes\n[2] Exit\nInput Choice: ");
      scanf("%d", &play);
    // checks if the user entered valid input and loops if it's not valid
      if (play != 1 && play != 2)
        printf("Invalid Input! Only numbers from 1-2 are accepted. Please try again.");

      //prompt to re-check if user wants to exit
      if (play == 2) {
        printf("\nAre you sure you want to exit?\n");
        printf("Press 'Y' for Yes\nPress 'N' for No\nInput choice: ");
        scanf(" %c", &exit);
        if (exit == 'Y' || exit == 'y')
          break; //exits the loop
        else{
          play = 1; //used to loop and start the game again
        }
      }
    }while (play != 1 && play != 2); 
    
  }while (play == 1);
  printf ("\nThank you for using our Sudoku Solver!\n");
  return 0;
}
