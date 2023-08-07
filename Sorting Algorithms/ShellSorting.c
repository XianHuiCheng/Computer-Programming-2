#include <stdio.h>
#include <ctype.h>
void shell_sort(int arr[], int n);

int main() {
    int n, i, choice;
    char datatype, response;
    
    while (1) {  
      printf("Enter number of elements (greater than 1): ");
      scanf("%d", &n);
    
      if (n <= 1) 
        printf("\nINVALID INPUT! Please enter a number greater than 1\n\n");
      else 
        break; 
    }
    
    int arr[n];
    printf("\nEnter %d elements to be sorted: \n", n);
    for (i = 0; i < n; i++) 
        scanf("%d", &arr[i]); 

    printf("Shell Sorting Process:\n");
    shell_sort(arr, n);
    printf("[1] Ascending\n[2] Descending\nEnter choice: ");
    scanf("%d",&choice);
    printf("\nSorted array in %s order:\n",(choice == 1)?"ascending":"descending");
    if (choice == 1){
      for(int i=0; i < n; i++)
          printf("%d ",arr[i]);
    }else{
      for(int i=n-1; i >= 0; i--)
      printf("%d ",arr[i]);
    }

    return 0;
}

void shell_sort(int arr[], int n) {
    int i,j, interval,moves = 0, swaps = 0;
    // sort the array using Knuth's formula
    int h = 1;
    while (h <= n / 3) {
        h = h * 3 + 1;
    }

    for (interval = h; interval > 0; interval = (interval - 1) / 3) {
        for (i = interval; i < n; i++) {
            int temp = arr[i];
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                // move elements
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }
}

