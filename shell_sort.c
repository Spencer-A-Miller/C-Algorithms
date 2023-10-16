// Step 1 - Initialize the value of the gap size.
// Step 2 - Divide the list into smaller sub-part. Each must have equal intervals to h
// Step 3 - Sort these sub-lists using insertion sort.
// Step 4 - Repeat step 1 until list is sorted

#include <stdio.h>
#include <math.h>

void shellSort(int array[], int len){
   int gap = floor(len/2);
   int j = gap;

   while(gap > 0){
    j = gap;
    // Check the array in from left to right
    // The last possible index of j
    while(j < len){
       int i = j - gap;
       while(i >= 0){
        if (array[i+gap] > array[i])
            break;
        else 
            array[i+gap], array[i] = array[i], array[i+gap];
        i = i - gap;
      }
      j += 1;
    }
   }
   gap = floor(gap/2);
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
    displayArray(array, len);
    shellSort(array, len);
    displayArray(array, len);

    return 0;
}