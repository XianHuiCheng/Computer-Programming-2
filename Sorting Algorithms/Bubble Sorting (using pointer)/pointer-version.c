/*
Group 3: Bubble Sorting using Pointer pointer version
Members:
Agad, Jiro Laurenz
Alpornon, Christine Julia
Bacolod, Mikaila Jhay
Buga-ay, Carl Tristan
Cheng, Xian Hui 
Del Rosario, Kyle Ferell
Edusma, Marie Cris
Esteban, Anthony James
Miguel, Rafael Louie
Modelo, John Vincent
Mortel, Meg Edelviese
Orde, Cyrus Jezter
Pascual, Ian Nevri
Robles, Aira Mae
Rosarda, Jeroises Israel
Sebastian, Brian May
*/

#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

#define ROWS 3
#define COLS 3
#define DURATION 5

// Resets the formatting
#define RESET "\033[0m"

// Foreground colors
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// Background colors
#define B_BLACK "\033[40m"
#define B_RED "\033[41m"
#define B_GREEN "\033[42m"
#define B_YELLOW "\033[43m"
#define B_BLUE "\033[44m"
#define B_MAGENTA "\033[45m"
#define B_CYAN "\033[46m"
#define B_WHITE "\033[47m"

// Formatting options
#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"

// Function prototype
void BubbleSortRows(double *p, int ifAscend);
void BubbleSortWhole (double *p, int ifAscend);
void GetArray(double *p);
void printBoard(double *p);
void showSortingSpinner(int durationInSeconds);
void showLoadingSpinner(int durationInSeconds);
int getAscendingOrDescending();
double getValidNumber(int column, int index);
char getYesOrNoInput(char response);

int i, j, k;

int main()
{

    char tryAgain;

    do{
        // Dynamic memory allocation for the numbers array
        double **numbers = (double**)malloc(ROWS * sizeof(double*));
        int ifAscend;
        for (i = 0; i < ROWS; i++)
            *(numbers + i) = (double*)malloc(COLS * sizeof(double));

        double *p = numbers[0];
        

        printf("\n");
        printf("==========================================\n");
        printf("||");
        printf("%s 2d Array Sorter: Bubble Sort Edition %s", MAGENTA, RESET);
        printf("||\n");
        printf("==========================================\n\n");
        
        GetArray(p);

        printf("============================================================\n\n");

        ifAscend = getAscendingOrDescending();

        printf("%s%sYou entered: %s \n%s", BOLD, GREEN, ifAscend == 1 ? "Ascending" : "Descending", RESET);
        printf("\nPlease enter any key to continue.\n");
        getch();

        printf("\n%s%s<== BEFORE SORTING ==>\n%s", BOLD, GREEN, RESET);
        printBoard(p);

        printf("\n============================================================\n\n");

        // Show spinner animation for sorting duration
        setbuf(stdout, NULL);
        showSortingSpinner(DURATION);
        
        printf("%s%s<== AFTER SORTING ==>\n%s", BOLD, GREEN, RESET);

        // Perform per row sorting and print the board
        printf("\n1. Per Row Sorting: \n");
        BubbleSortRows(p, ifAscend);
        printBoard(p);

        // Perform whole board sorting and print the board
        printf("\n2. Whole Board Sorting: \n");
        BubbleSortWhole(p, ifAscend);
        printBoard(p);

        printf("\n============================================================\n");
        printf("\nTry Again? ");
        tryAgain = getYesOrNoInput(tryAgain);

        printf("%s%sValid Input: %s \n%s", BOLD, GREEN, tryAgain == 'Y' ? "Trying again" : "Exit", RESET);


        showLoadingSpinner(DURATION);
        printf("\n\nPlease enter any key to continue.\n");
        getch();
    
        if(tryAgain == 'Y'){
            free(numbers);
            system("cls");
        }
           
    }while(tryAgain == 'Y');

    printf("\n============================================================\n\n");
    printf("%sThank you for using the Program!\n%s", MAGENTA, RESET);
    getch();
}

// Sorts each row of a 2D array using bubble sort in ascending or descending order
void BubbleSortRows(double *p, int ifAscend) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 1; j++) {
            for (int k = 0; k < COLS - j - 1; k++) {

                double *current = (p + i * COLS + k);
                double *next = (p + i * COLS + k + 1);

                if (*(p + i * COLS + k) > *(p + i * COLS + k + 1) && ifAscend == 1 || *(p + i * COLS + k) < *(p + i * COLS + k + 1) && ifAscend == 2){
                    double temp = *(p + i * COLS + k);
                    *(p + i * COLS + k) = *(p + i * COLS + k + 1);
                    *(p + i * COLS + k + 1) = temp;
                }
            }
        }
    }
}

// Sorts the entire 2D array using bubble sort in ascending or descending order
void BubbleSortWhole(double *p, int ifAscend) {
    int totalElements = ROWS * COLS;

    for (i = 0; i < totalElements; i++) {
        for (j = 0; j < totalElements - i - 1; j++) {
            // Calculate the row and column indices for the current and next elements
            double* current = p + j;
            double* next = p + j + 1;

            // Check the sorting order and compare adjacent elements
            if ((*current > *next && ifAscend == 1) || (*current < *next && ifAscend == 2)) {
                // Swap the elements if they are in the wrong order
                double temp = *current;
                *current = *next;
                *next = temp;
            }
        }
    }
}

// Retrieves input values from the user and populates the 2-dimensional array
void GetArray(double *p) {
    for (i = 0; i < ROWS; i++) {
        printf("%s%sROW: %d \n%s", BOLD, YELLOW, i + 1, RESET);
        for (j = 0; j < COLS; j++) {
            double input;
            printf("Enter any number for [COLUMN %d]: ", j + 1);
            input = getValidNumber(input, j);
            *(p + i * COLS + j) = input;
        }
        printf("\n");
    }
}

// Prints the contents of the 2 Dimensional array
void printBoard(double *p) {
    for (i = 0; i < ROWS; i++) {
        if (i == 0 || i == 2)
            printf("\n+-----------------------+\n");
        else
            printf("\n-------------------------\n");
        for (j = 0; j < COLS; j++) {
            printf("%s%*s%*g%*s%s", j < COLS ? "|" : "",
                *(p + i * COLS + j) < 10 ? 3 : (*(p + i * COLS + j) < 100) ? 3 : 2, "",
                *(p + i * COLS + j) < 10 ? 1 : (*(p + i * COLS + j) < 100) ? 2 : 3,
                *(p + i * COLS + j),
                *(p + i * COLS + j) < 10 ? 3 : (*(p + i * COLS + j) < 100) ? 2 : 2, "",
                j == COLS - 1 ? "|" : "");

        }
    }
    printf("\n+-----------------------+\n");
}


// Displays a spinner animation during the sorting process for a specified duration
void showSortingSpinner(int durationInSeconds) {
    const char spinner[] = { '|', '/', '-', '\\' };
    i = 0;
    int secondsPassed;
    int millisecondsPassed;

    for (secondsPassed = 0; secondsPassed < durationInSeconds; secondsPassed++) {
        for (millisecondsPassed = 0; millisecondsPassed < 100; millisecondsPassed += 20) {
            printf("%s%sSorting %c\r%s", BOLD, YELLOW, spinner[i % 4], RESET);
            fflush(stdout);
            Sleep(100);
            i++;
        }
    }
    printf("\r                \r");
    printf("%s%sSorting Complete\n\n%s", BOLD, GREEN, RESET);
}

// Displays a loading spinner animation for a specified duration
void showLoadingSpinner(int durationInSeconds) {
    const char spinner[] = { '|', '/', '-', '\\' };
    i = 0;
    int secondsPassed;
    int millisecondsPassed;
    for (secondsPassed = 0; secondsPassed < durationInSeconds; secondsPassed++) {
        for (millisecondsPassed = 0; millisecondsPassed < 100; millisecondsPassed += 20) {
            printf("%s%sLoading %c\r%s", BOLD, YELLOW, spinner[i % 4], RESET);
            fflush(stdout);
            Sleep(100);
            i++;
        }
    }
    printf("\r                \r");
    printf("%s%sProceed%s", BOLD, GREEN, RESET);
}

// Asks the user for ascending or descending order and returns the choice as an integer
int getAscendingOrDescending() {
    char input[100];

    while (1) {
        printf("ENTER [1] FOR ASCENDING OR [2] FOR DESCENDING: ");

        fflush(stdin);

        gets(input);

        // Remove the trailing newline character
        input[strcspn(input, "\n")] = '\0';

        int isNumber = 1;

        // Check if the input is a valid number
        for (i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                isNumber = 0;
                break;
            }
        }

        // Return 1 for ascending and 2 for descending
        if (isNumber) {
            int ifAscend = atoi(input);
            if (ifAscend == 1 || ifAscend == 2) {
                return ifAscend;
            }
        }

        printf("%s%sInvalid input. Please enter a valid number.\n%s", BOLD, RED, RESET);
    }
}

// Prompts the user for a valid number at a specific column and index in the 2D array
double getValidNumber(int column, int index) {
    double input;

    // Check if the input is a valid number and within the specified range
    while (scanf("%lf", &input) != 1 || input >= 1000 || input < 0) {
        printf("%s%sInvalid input. Please enter a valid number (0-999).\n%s", BOLD, RED, RESET);
        scanf("%*[^\n]");
        scanf("%*c");
        printf("Enter any number for [COLUMN %d]: ", index + 1);
    }

    return input;
}

// Asks the user for a 'Yes' or 'No' input and returns the choice as a character
char getYesOrNoInput(char response) {
    char input[100];
    int isValidInput = 0;

    while (!isValidInput) {
        printf("\nEnter 'Y' for Yes or 'N' for No: ");
        gets(input);
        input[strcspn(input, "\n")] = '\0';

        // Check if the input is a single character
        if (strlen(input) == 1) {
            // Convert the input to uppercase
            input[0] = toupper(input[0]);

            // Check if the input is either 'Y' or 'N'
            if (input[0] == 'Y' || input[0] == 'N') {
                isValidInput = 1;
            }    
        } 
        // Check if the input is lowercase "yes"
        else if (strcasecmp(input, "yes") == 0) {
            isValidInput = 1;
            input[0] = 'Y';
        } 
        // Check if the input is lowercase "no"
        else if (strcasecmp(input, "no") == 0) {
            isValidInput = 1;
            input[0] = 'N';
        }
        // Display an error message for invalid input
        if (!isValidInput) {
            printf("\033[1;31mInvalid input. Please enter either 'Y' or 'N'\033[0m");
        }
    }

    return input[0];
}
