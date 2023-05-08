#include <stdio.h>
#include <stdlib.h>

void printArray(float array[], int size) {
  for (int i = 0; i < size; i++) {
    // use %g to remove succeeding 0 when printing float
    printf("%g  ", array[i]);
  }
  printf("\n");
}

void heapify(float data[], int type, int size, int i) {
  float temp;
  // Initialize largest as root, left and right index as its children
  int root = i;
  // add 1 since array starts at 0
  int leftChild = 2 * i + 1;
  int rightChild = 2 * i + 2;

  // ASCENDING: look for the largest child/value
  if (type == 1) {
    // if left child is larger than root
    if (leftChild < size && data[leftChild] > data[root])
      root = leftChild;

    // if right child is larger than root
    if (rightChild < size && data[rightChild] > data[root])
      root = rightChild;
  } // DESCENDING: look for the smallest child/value
  else {
    // if left child is smaller than root
    if (leftChild < size && data[leftChild] < data[root])
      root = leftChild;

    // if right child is smaller than root
    if (rightChild < size && data[rightChild] < data[root])
      root = rightChild;
  }

  // if root is not the largest/smallest value
  if (root != i) {
    //it swaps it to the largest/smallest
    temp = data[i];
    data[i] = data[root];
    data[root] = temp;
    // fix the heap from the root to the last element, to ensure that heap is maintained
    heapify(data, type, size, root);
  }
}

// SORT ARRAY USING HEAP SORT
void sort(float data[], int type, int size) {
  // CREATING MAX/MIN HEAP
  // iterate over node in reverse order (rearrange array)
  for (int i = size / 2 - 1; i >= 0;i--) { // Note: size / 2 - 1 = index of last node
    heapify(data, type, size, i);
  }
  // SORT HEAP
  // extract elements one by one from heap and put them at the end of array
  for (int i = size - 1; i >= 1; i--) { // used 1 in sentinel instead of 0 so it won't print the last iteration
    // swap root to the last element
    float temp = data[0];
    data[0] = data[i];
    data[i] = temp;

    // restore heap property on the remaining elements
    heapify(data, type, i, 0);

    // print each process of sorting
    printf("Pass %d: ", size - i);
    printArray(data, size);
  }
}

int main() {
  int size, i, sortType, choice = 1;
  char exit;
  do { // Prompt user to enter the size of array
    printf("\nEnter size of array: ");
    scanf("%d", &size);

    // Prompt user to enter the elements of the array
    float array[size];
    for (i = 0; i < size; i++) {
      printf("Array Element # %d: ", i + 1);
      scanf("%g", &array[i]);
    }

    // Determines the way of sorting
    printf("\nHow would you like to sort it?\n");
    printf("[1]Ascending\n[2]Descending\nInput choice: ");
    scanf("%d", &sortType);

    // printing the array the user created
    printf("\nCurrent Array: ");
    printArray(array, size);

    printf("\nHeap Sorting Process:\n");
    sort(array, sortType, size);

    // printing sorted array
    if (sortType == 1) {
      printf("\nSorted Array in Ascending order:\n");
    } else
      printf("\nSorted Array in Descending order:\n");
    printArray(array, size);

    printf("\nWould you like to sort again?\n");
    printf("[1] Yes\n[2] Exit\nInput choice: ");
    scanf("%d", &choice);
    if (choice == 2) {
      printf("\nAre you sure you want to exit?\n");
      printf("Press 'Y' for Yes\nPress 'N' for No\nInput choice: ");
      scanf(" %c", &exit);
      if (exit == 'Y' || exit == 'y')
        break;
      else
        choice = 1;
    }
    printf("======================================");
  } while (choice == 1);

  printf("\nThank you for using our program!");

  return 0;
}
