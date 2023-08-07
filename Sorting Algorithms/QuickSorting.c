#include <stdio.h>

void swap(float arr[], int i, int j);
int partition(float arr[], int low, int high);
void quicksort(float arr[], int low, int high);

int main() {
    int n,choice;
    while (1) {  
      printf("Enter number of elements (greater than 1): ");
      scanf("%d", &n);
    
      if (n <= 1) 
        printf("\nINVALID INPUT! Please enter a number greater than 1\n\n");
      else 
        break; 
    }
    printf("Enter %d elements to be sorted:\n", n);

    float arr[n];
    for (int i = 0; i < n; i++) 
      scanf("%f", &arr[i]);
      
    // Display array
    printf("\nQuick Sorting Process: \n");
    quicksort(arr, 0, n - 1);
    printf("[1] Ascending\n[2] Descending\nEnter choice: ");
    scanf("%d",&choice);
    printf("\nSorted array in %s order:\n",(choice == 1)?"ascending":"descending");

    if  (choice == 1){
      for (int i = 0; i < n; i++) 
          printf("%g%s", arr[i], (i == n-1) ? "\n" : " ");
    }else{
      for (int i = n-1; i >= 0; i--) 
          printf("%g%s", arr[i], (i == 0) ? "\n" : " ");
    }
        
    printf("\nThank you for using our program!\n");
    
    return 0;
}

// Function to swap two elements
void swap(float arr[], int i, int j) {
    float temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to partition the array
int partition(float arr[], int low, int high) {
    float pivot = arr[high];                  
    int i = low - 1;                          
    for (int j = low; j <= high - 1; j++) {   
        if (arr[j] < pivot) {                
            i++;                              
            swap(arr, i, j);                  
        }
    }
    swap(arr, i + 1, high);                
    return i + 1;                            
}

// Function to perform quicksort
void quicksort(float arr[], int low, int high) {
    if (low < high) {
        int pathIndex = partition(arr, low, high);    // First partition
        quicksort(arr, low, pathIndex - 1);           // Quicksort for left side
        quicksort(arr, pathIndex + 1, high);          // Quicksort for right side
    }
}

