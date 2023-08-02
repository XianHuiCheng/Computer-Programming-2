#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Account {
    int accNum;
    int accPin;
    float accDep;
    float accWit;
    float accBal;
    int year;
    int month;
    int day;
};

void createRecord();
void deleteRecord();
void updateRecord();
void displayRecord();
void displayAllRecords();
bool accountExists1(int accNum);


int main(){
    int operation;
do{
    printf("\nATM MENU\n");
    printf("Choose Operation\n");
    printf("[1]Create\n");
    printf("[2]Delete\n");
    printf("[3]Update\n");
    printf("[4]Display\n");
    printf("[5]Exit\n");
    printf("\nResponse: ");
    scanf("%d", &operation);


    switch(operation){
        case 1: {
            //Create
            printf("\nATM ACCOUNT CREATION\n\n");
            createRecord();

            break;
        }
        case 2: {
            //Delete
            deleteRecord();
        
            break;
        }

        case 3: {
            //Update
            updateRecord();

            break;
        }

        case 4: {
            //Display
            printf("\n[1] SHOW ALL RECORDS\n");
            printf("[2] SHOW SPECIFIC RECORD\n");
            printf("Response: ");
            scanf("%d", &operation);
                
            if(operation == 1)
                displayAllRecords();
            else if(operation == 2)
                displayRecord();
            
            break;
        }

        case 5: 
            break;
        
        default:
            printf("Invalid Input\n");
    }
}while(operation != 5);

printf("\nThank you for using the program!");
    return 0;
}

bool accountExists(int operation, int accNum, int accPin){
    FILE *file = fopen("accounts.dat",  "r");

    if(file == NULL){
        printf("Error Opening File\n");
        return false;
    }

    struct Account acc;
    while(fscanf(file, "%d %d %d %d %d %f %f %f", &acc.accNum, &acc.accPin, &acc.month, &acc.day, &acc.year, &acc.accDep, &acc.accWit, &acc.accBal) != EOF){
        if((operation == 1 && acc.accNum == accNum) || (operation == 2 && acc.accPin == accPin && acc.accNum == accNum)){
            fclose(file);
            return true;
        }
    }
    fclose(file);
    return false;
}

bool accountExists1(int accNum){
    FILE *file = fopen("accounts.dat",  "r");

    if(file == NULL){
        printf("Error Opening File\n");
        return false;
    }

    struct Account acc;
    while(fscanf(file, "%d %d %d %d %d %f %f %f", &acc.accNum, &acc.accPin, &acc.month, &acc.day, &acc.year, &acc.accDep, &acc.accWit, &acc.accBal) != EOF){
        if(acc.accNum == accNum){
            fclose(file);
            return true;
        }
    }
    fclose(file);
    return false;
}

void createRecord(){
    FILE *file = fopen("accounts.dat", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Account acc;

    float amount = 0;

    while(1){
        printf("Enter Account Number (5 digits): ");
        scanf("%d", &acc.accNum);

        if(accountExists1(acc.accNum)){
            printf("INVALID INPUT, ACCOUNT NUMBER IS ALREADY IN USE! TRY ANOTHER ACCOUNT NUMBER.\n");
        }

        else{
            printf("ACCOUNT NUMBER IS AVAILABLE!\n");
            break;
        }
    }

    printf("Enter Account Pin (4 digits): ");
    scanf("%d", &acc.accPin);

    printf("Enter Initial Deposit: ");
    scanf("%f", &amount);

    printf("Enter Day: ");
    scanf("%d", &acc.day);
    printf("Enter Month: ");
    scanf("%d", &acc.month);
    printf("Enter Year: ");
    scanf("%d", &acc.year);

    acc.accBal = amount;
    acc.accDep = amount;
    acc.accWit = 0.0;

    fprintf(file, "%d %d %d %d %d %.2f %.2f %.2f\n", acc.accNum, acc.accPin, acc.month, acc.day, acc.year, acc.accDep, acc.accWit, acc.accBal);

    fclose(file);

    printf("Account Created Successfully!\n\n");
}

void deleteRecord(){
    FILE *file = fopen("accounts.dat", "r");
    FILE *tempFile = fopen("temp.dat", "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    if (tempFile == NULL) {
        printf("Error opening file.\n");
        fclose(file);
        return;
    }


    struct Account acc;

    int AccNum;
    int AccPin;

    while(1){
        printf("Enter Account Number (5 digits): ");
        scanf("%d", &AccNum);

        if(accountExists(1, AccNum, 0)){
            printf("VALID INPUT, ACCOUNT NUMBER EXISTS!\n");
            break;
        }

        else{
            printf("THERE ARE NO RECORDS OF THIS ACCOUNT NUMBER\n");
        }
    }

    while(1){
        printf("Enter Account Pin (4 digits): ");
        scanf("%d", &AccPin);

        if(accountExists(2, AccNum, AccPin)){
            printf("ACCOUNT PIN CORRECT!\n");
            break;
        }

        else{
            printf("INCORRECT ACCOUNT PIN\n");
        }

    }

    while(fscanf(file, "%d %d %d %d %d %f %f %f\n", &acc.accNum, &acc.accPin, &acc.month, &acc.day, &acc.year, &acc.accDep, &acc.accWit, &acc.accBal) != EOF){
        if(acc.accNum != AccNum && acc.accPin != AccPin){
        fprintf(tempFile, "%d %d %d %d %d %.2f %.2f %.2f\n", acc.accNum, acc.accPin, acc.month, acc.day, acc.year, acc.accDep, acc.accWit, acc.accBal);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("accounts.dat");
    rename("temp.dat","accounts.dat");
    printf("Account Deleted Successfully!\n\n");
}

void updateRecord(){
    FILE *file = fopen("accounts.dat", "r+");
    FILE *tempFile = fopen("temp.dat", "w+");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    int AccNum;
    int AccPin;
    int response = 0; // Initialize response to a default value
    int year, month, day;
    float amount = 0;

    struct Account acc;

    while(1){
        printf("Enter Account Number (5 digits): ");
        scanf("%d", &AccNum);

        if(accountExists(1, AccNum, 0)){
            printf("VALID INPUT, ACCOUNT NUMBER EXISTS!\n");
            break;
        }

        else{
            printf("THERE ARE NO RECORDS OF THIS ACCOUNT NUMBER\n");
        }
    }

    while(1){
        printf("Enter Account Pin (4 digits): ");
        scanf("%d", &AccPin);

        if(accountExists(2, AccNum, AccPin)){
            printf("ACCOUNT PIN CORRECT!\n");
            break;
        }

        else{
            printf("INCORRECT ACCOUNT PIN\n");
        }

    }

    while(fscanf(file, "%d %d %d %d %d %f %f %f", &acc.accNum, &acc.accPin, &acc.month, &acc.day, &acc.year, &acc.accDep, &acc.accWit, &acc.accBal) != EOF){
        if(acc.accNum == AccNum && acc.accPin == AccPin){
            printf("\nAccount Number: %d", acc.accNum);
            printf("\nAccount Balance: %.2f", acc.accBal);
            printf("\n1. Withdraw\n");
            printf("2. Deposit\n");
            printf("Enter your choice: ");
            scanf("%d", &response);


            switch(response){
                case 1: {
                    printf("Enter amount to withdraw: ");
                    scanf("%f", &amount); // Use the correct format specifier

                    if(amount <= acc.accBal){
                        acc.accBal -= amount;
                        acc.accDep = 0.0;
                        acc.accWit = amount;
                        printf("Withdrawal Successful. New balance: %.2f\n", acc.accBal);
                    }
                    else{
                        printf("Insufficient Balance\n");
                    }
                    break;
                }

                case 2: {
                    printf("Enter amount to deposit: ");
                    scanf("%f", &amount); // Use the correct format specifier

                    acc.accBal += amount;
                    acc.accDep = amount;
                    acc.accWit = 0.0;
                    printf("Deposit successful. New balance: %.2f\n", acc.accBal);
                    break;
                }

                default: {
                    printf("Invalid option.\n");
                    break;
                }
            }
            printf("\nEnter Day: ");
            scanf("%d", &day);
            printf("Enter Month: ");
            scanf("%d", &month);
            printf("Enter Year: ");
            scanf("%d", &year);

            acc.day = day;
            acc.month = month;
            acc.year = year;
        }

        fprintf(tempFile, "%d %d %d %d %d %.2f %.2f %.2f\n", acc.accNum, acc.accPin, acc.month, acc.day, acc.year, acc.accDep, acc.accWit, acc.accBal);
    }

    fclose(file);
    fclose(tempFile);
    remove("accounts.dat");
    rename("temp.dat", "accounts.dat");
}

void displayRecord(){
    FILE *file = fopen("accounts.dat", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    struct Account acc;

    int AccNum;
    int AccPin;

    while(1){
        printf("Enter Account Number (5 digits): ");
        scanf("%d", &AccNum);

        if(accountExists(1, AccNum, 0)){
            printf("VALID INPUT, ACCOUNT NUMBER EXISTS!\n");
            break;
        }

        else{
            printf("THERE ARE NO RECORDS OF THIS ACCOUNT NUMBER\n");
        }
    }

    while(1){
        printf("Enter Account Pin (4 digits): ");
        scanf("%d", &AccPin);

        if(accountExists(2, AccNum, AccPin)){
            printf("ACCOUNT PIN CORRECT!\n");
            break;
        }

        else{
            printf("INCORRECT ACCOUNT PIN\n");
        }

    }

    while(fscanf(file, "%d %d %d %d %d %f %f %f", &acc.accNum, &acc.accPin, &acc.month, &acc.day, &acc.year, &acc.accDep, &acc.accWit, &acc.accBal) != EOF){
        if(acc.accNum == AccNum && acc.accPin == AccPin){
            printf("\nAccount Details: \n");
            printf("Account Number: %d\n", acc.accNum);
            printf("Account Pin: %d\n", acc.accPin);
            printf("Account Balance: %.2f\n", acc.accBal);

            printf("\nPrevious Transaction: \n");
            printf("Date: %d/%d/%d\n", acc.month, acc.day, acc.year);

            if(acc.accDep == 0 && acc.accWit > 0){
                printf("\nWithdraw Amount of: %.2f\n", acc.accWit);
            }
            else if(acc.accDep > 0 && acc.accWit == 0){
                printf("\nDeposited amount of: %.2f\n", acc.accDep);
            }
            break;
        }
    }    
    fclose(file);
}

void displayAllRecords(){
    FILE *file = fopen("accounts.dat", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Account acc;

    printf("\nAccount Details\n");
    printf("====================================================================\n");
    printf("%-15s %-10s %-10s %-10s %-10s %-10s\n", "Account Num", "PIN", "Date", "Deposit", "Withdraw", "Balance");
    printf("--------------------------------------------------------------------\n");

    while(fscanf(file, "%d %d %d %d %d %f %f %f\n", &acc.accNum, &acc.accPin, &acc.month, &acc.day, &acc.year, &acc.accDep, &acc.accWit, &acc.accBal) != EOF){

    printf("%-15d %-10d %02d/%02d/%d %-10.2f %-10.2f %-10.2f\n", acc.accNum, acc.accPin, acc.month, acc.day, acc.year, acc.accDep, acc.accWit, acc.accBal);
    }

    fclose(file);
}