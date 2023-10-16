// Merge Sort Algorithm

#include <stdio.h>

void merge_sorted_arrays(int arr[], int left, int middle, int right);{

}

void merge_sort_recursion(int arr[], int left, int right);{
    
}

/* 
merge_sort
PURPOSE:
    This function split the orginal array into a left and right side to be passed to the
    merge_sort_recursion function.
 INPUTS: 
    arr: The orginal unsorted array (int array)
    arrSize: The number of elements in the original unsorted array (int)
OUTPUTS: 
    None. Will sort the orginal unsorted array.
*/
void merge_sort(int arr[], int arrSize){
    merge_sort_recursion(arr, 0, arrSize - 1);
}

void display_result(int arr[], int arrSize){
     //Print the sorted array to console
    for (int i = 0; i < arrSize; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[] = {70, 50, 60, 90, 10, 30, 40, 60, 80, 20};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    
    printf("Unsorted array: ");
    display_result(arr, arrSize);
    
    merge_sort(arr, arrSize);
    
    printf("sorted array: ")
    display_result(arr, arrSize);

   
    
    //print original array
    // Call merge sort function(pass array, arraySize, left index, right index)
    // Print sorted array

    return 0;
}