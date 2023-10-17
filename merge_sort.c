// Merge Sort Algorithm

#include <stdio.h>


/* 
merge_sorted_arrays
PURPOSE:
    This function takes the array portions as input when called by merge_sorted_arrays
 INPUTS: 
    arr: array portion passed by merge_sorted_arrays (int array)
    left: The index of the left side array when split. Starts out as 0 but will increase until the middle is reached. (int)
    middle: The middle index of the array portion (int)
    right: The index of the right side array when split. Starts out as length - 1 but will decrease until the middle is reached. (int)
RETURNS: 
   None 
*/
void merge_sorted_arrays(int arr[], int left, int middle, int right){
    // Find the length of the left & right portion of passed array.
    int left_length = middle - left + 1;
    int right_length = right - middle;

    // Copy the left & right portions of the array into temp array for each.

    int temp_left[left_length];
    int temp_right[right_length];

    int l, r, k;

    for (int i = 0; i < left_length; i++)  // Left side starts at the left side + 1
        temp_left[i] = arr[left + i];

    for (int i = 0; i < right_length; i++) // Right side starts at middle + 1
        temp_right[i] = arr[middle + 1 + i];

    // Merge the Sub arrays
    // Example:
    //             l
    // temp_left:  4, 9, 12
    //             
    //             r
    // temp_right: 5, 8, 14
    //
    //             k
    //        arr: 4, 5, 


    // l: counter variable indexing into sorted temp_left array
    // r: counter variable indexing into sorted temp_right array
    // k: counter variable indexing into the array portion. 

    // iterate over the index length of arr to determine the value of what will be merged into that index.
    // We check which array will have the next smallest element with the comparison temp_left[l] <= temp_right[r]. If true, we move
    // temp_left[l] into arr[k], increment l, and do another comparison. r is not incremented until the temp_right is less than temp_left
    for (l = 0, r = 0, k = left; k <= right; k++){
        if ((l < left_length) && (r >= right_length || temp_left[l] <= temp_right[r])){
            arr[k] = temp_left[l];
            l++;
        }
        else{
            arr[k] = temp_right[r];
            r++;
        }
    }   
}

/* 
merge_sort_recursion
PURPOSE:
    This function will calculate the middle index of the array passed to it. If the array has an even number of elements, the middle 
    index will be the floor of the computatation and stored as am integer.
 INPUTS: 
    arr: The orginal unsorted array (int array)
    left: The index of the left side array when split. Starts out as 0 but will increase until the middle is reached. (int)
    right: The index of the right side array when split. Starts out as length - 1 but will decrease until the middle is reached. (int)
RETURNS: 
   None 
*/

void merge_sort_recursion(int arr[], int left, int right){
    int middle = left + (right - left) / 2;

    // Continually divide the unsorted array into smaller and smaller sub portions until the left index is equal to the right index,
    //  indicating we have divided the array into all portions.

    if (left < right){    
        merge_sort_recursion(arr, left, middle);
        merge_sort_recursion(arr, middle + 1, right);
        merge_sorted_arrays(arr, left, middle, right);

    }
}
/* 
merge_sort
PURPOSE:
    This function split the orginal array into a left and right side to be passed to the
    merge_sort_recursion function.
 INPUTS: 
    arr: The orginal unsorted array (int array)
    arrSize: The number of elements in the original unsorted array (int)
RETURNS: 
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
    
    printf("sorted array: ");
    display_result(arr, arrSize);   
    //print original array
    // Call merge sort function(pass array, arraySize, left index, right index)
    // Print sorted array

    return 0;
}