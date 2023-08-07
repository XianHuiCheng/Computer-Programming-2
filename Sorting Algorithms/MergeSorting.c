#include <stdio.h>

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

int main (){

    printf("Welcome! This is Group 1's Merge Sort Program.\n\n");
    int n, arr[n];
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter %d elements to be sorted: ", n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
  
    mergesort(arr, 0, n-1);

    printf("Sorted array: ");
    for(int i=0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n\nThank you for using our program! :)\n");
    return 0;
}

