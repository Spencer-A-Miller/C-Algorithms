// Insertion Sort

#include <stdio.h>
#include <math.h>

void insertionSort(int array[], int len){
    int i, key, j;
    for (i=1; i<len; i++){
        key = array[i];
        j = i - 1;

        while(j >= 0 && array[j] > key){
            array[j+1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void displayArray(int array[], int len){
    int i;
    for (i=0; i<len; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main(){
    int array[] = {43, 56, 12, 90, 64, 25, 66, 43, 29, 67};
    int len = sizeof(array)/sizeof(array[0]);
    displayArray(array, len);  // Display Original array
    insertionSort(array, len); // Insertion sort the array
    displayArray(array, len);  // Display sorted array

    return 0;
}
