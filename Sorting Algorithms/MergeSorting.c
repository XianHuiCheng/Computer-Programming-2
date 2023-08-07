#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int first, int mid, int last);
void mergesort(int arr[], int first, int last);

int main (){
    int n, choice;
    while (1) {  
      printf("Enter number of elements (greater than 1): ");
      scanf("%d", &n);
    
      if (n <= 1) 
        printf("\nINVALID INPUT! Please enter a number greater than 1\n\n");
      else 
        break; 
    }

    printf("Enter %d elements to be sorted: \n", n);

    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    mergesort(arr, 0, n-1);

    printf("Sorted array: \n");
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
    printf("\n\nThank you for using our program! :)\n");
    return 0;
}

void merge(int arr[], int first, int mid, int last){
    int b[50], i, j, k;
    i = first; j = mid + 1; k = first;

    while (i <= mid && j <= last){
        if (arr[i] <= arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }
    if (i > mid){
        while (j <= last)
            b[k++] = arr[j++];
    }else{
        while (i <= mid)
            b[k++] = arr[i++];
    }

    for (i = first; i <= last; i++)
        arr[i] = b[i];
}

void mergesort(int arr[], int first, int last)
{
    int mid;
    if(first<last){
        mid = (first+last)/2;
        mergesort(arr, first, mid);
        mergesort(arr, mid+1, last);
        merge(arr,first,mid,last);
    }
}