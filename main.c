#include <stdio.h>
#include <stdlib.h>


void printArray(int  arr[] , int N);

void printArray2(int  arr[] , int N);

void bubbleSort(int arr[] , int N);

void bubbleSort2(int * arr, int N, void (*Swap) (int* a, int* b) );

void Swap (int *a , int *b);

int main() {

    int arr [] = {12,67,2,-3,58,38,-12,34,12};

    int size = sizeof(arr)/sizeof(arr[0]);

    void (*swap) (int* a, int* b);
    swap = &Swap;

    printf("\n");
    printf( "Printing original array \n");
    printArray2(arr,size);
    printf( "\n Entering bubble sort  \n");
    bubbleSort(arr,size);
    printArray2(arr,size);
    int arr2 [] = {12,67,2,-3,58,38,-12,34,12};
    printf( "\nEntering bubble sort 2 ");
    printf("\n");
    bubbleSort2(arr2,size,swap);

    printArray2(arr2,size);
    printf("\n");
    printf("Hello, World!\n");
    return 0;
}


void bubbleSort(int arr[] , int N){

    //int *p = arr;
    int temp;
int i,j;

    for (i = N-1; i >= 0; i --)
    for (j = 1; j <= i; j++) {
        if (arr[j-1] > arr[j]) {
            temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
        }
    }
}
    //printf("Hello, World!\n");

void bubbleSort2(int arr[] , int N, void (*Swap) (int* a, int* b)){

    int *p = arr;
    int temp;
    int i, j;
    for (i = N-1; i >= 0; i --)
        for (j = 1; j <= i; j++) {
            if (arr[j-1] > arr[j]) {
                (*Swap)(&arr[j], &arr[j-1]);
            }
        }
    }

// free (p);


void printArray(int  arr[] , int N){

  for(int  i = 0; i < N ; i++) {
      printf("%d ", arr[i]);
  }

}

void printArray2(int  arr[] , int N){

      int *p = arr;
    for(int  i = 0; i < N ; i++) {
        printf("%d ", *(p+i));
    }

     free (p);
}
void Swap (int *a , int *b){

    int temp = *a ;
    *a = *b;
    *b = temp;
}