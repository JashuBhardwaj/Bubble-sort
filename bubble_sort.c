// program for binary search and find the time taken in sorting 
// Author name - Jashu Bhardwaj
// Date : 27/07/2021

#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>

// function for swapping the adjucent elements of the array
// it takes the array name and indexs of the elements to be swapped
int swap(int arr[], int i, int j) {

    int temp=0;

    // swapping using temp
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return 0;
}

// function for executing bubble sort 
// it takes array and size of the array 
void bubble_sort(int arr[], int n) {

    int i, j;
    
    for(i = 0; i < n; i++) {
        
        // boolean for checking is the elements are swapped or not
        
        int swapping = 0;        

        for(j = 0; j < n-i-1; j++) {

            if(arr[j] > arr[j+1]) {
                swap(arr, j, j+1);
		        swapping = 1;
            }
        }

    // if there is no swapping in the array that means the array is sorted
    // no need to run the loop further so break the loop
	if(!swapping) {
    
	    break;
        }

    }
}

// function for generating random elements in array
void random_inputs(int arr[], int n) {
    
    for(int i = 0; i < n; i++) {
        
        arr[i] = rand();
    }
    
    // for calculating the time taken for sorting 
    struct timeval ti;
    gettimeofday(&ti , NULL);
    long starttime = ti.tv_sec *1000LL + ti.tv_usec/1000;

    bubble_sort(arr , n);
    
    gettimeofday(&ti , NULL);
    long endtime=ti.tv_sec *1000LL + ti.tv_usec/1000;
    
    printf("Time Taken for sorting random %d elements is : %ld\n", n, endtime - starttime);
    
}

// function for generating inputs in sorted order
void sorted_inputs(int arr[], int n) {
    
    for(int i = 0; i < n; i++) {
        
        arr[i] = i;
    }
    
    struct timeval ti;
    gettimeofday(&ti , NULL);
    long starttime = ti.tv_sec *1000LL + ti.tv_usec/1000;

    bubble_sort(arr , n);
    
    gettimeofday(&ti , NULL);
    long endtime=ti.tv_sec *1000LL + ti.tv_usec/1000;
    
    printf("Time Taken for sorting sorted %d elements is : %ld\n", n, endtime - starttime);
    
}

// function for generating inputs in reversed order
void reverse_inputs(int arr[], int n) {
    
    for(int i = 0; i < n; i++) {
        
        arr[i] = n - i;
    }
    
    struct timeval ti;
    gettimeofday(&ti , NULL);
    long starttime = ti.tv_sec *1000LL + ti.tv_usec/1000;

    bubble_sort(arr , n);
    
    gettimeofday(&ti , NULL);
    long endtime=ti.tv_sec *1000LL + ti.tv_usec/1000;
    
    printf("Time Taken for sorting reversed %d elements is : %ld\n", n, endtime - starttime);
    
}

// main function
int main() {

    int n = 0;
    
    // asking the user for the size of the array
    printf("Enter the no of elements\n");
    scanf("%d", &n);
    int arr[n];
    
    // calling the function for generating random inputs
    random_inputs( arr, n);
    
    // calling the function for generating inputs in sorted order
    sorted_inputs( arr, n);
	
    // calling the function for generating inputs in reversed order
    reverse_inputs( arr, n);

    return 0;
}

