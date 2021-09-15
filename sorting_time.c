/*	Author : Anikait Singh
Creation Date : 08 Sep, 2021
Purpose :  A C program to compare the running times (in milliseconds) of Bubble Sort and Merge Sort.*/ 

#include<stdio.h>	//Pre processor directive to include standard input and output function header file.
#include<time.h>	//Pre processor directive to include time function.

int bubble();	//Prototype.
int merge();
int mergeSort();
int printArray();

int main(){	//Start of the main function body.
    int max_size = 10;	//Integer variables decleration.
    int A_Bubble[10] = {1,3,42,2,41,66,66,33,98,0}, A_Merge[10] = {1,3,42,2,41,66,66,33,98,0};
 	printf("\nGiven Array :\n\n");
 	printArray(A_Bubble, max_size);

    // Calculate the time taken by fun()
    clock_t t;
    t = clock();
    bubble(A_Bubble,max_size);
    printf("\nSorted array through 'Bubble Sorting' :\n\n");
    printArray(A_Bubble, max_size);
    sleep(1);
    t = clock() - t;
    double time_taken_by_bubble_sorting = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("\nBubble sorting took %f seconds to execute \n", time_taken_by_bubble_sorting);
    printf("\n\n-----------------------------------------\n\n");
    t = clock();
    mergeSort(A_Merge, 0, ( max_size- 1));
    printf("Sorted array through 'Merge Sorting' :\n\n");
    printArray(A_Merge , max_size);
    sleep(1);
    t = clock() - t;
    double time_taken_by_merge_sorting = ((double)t) / CLOCKS_PER_SEC;
    printf("\nMerge sorting took %f seconds to execute \n", time_taken_by_merge_sorting);
    return 0;	//Return statement.
}	//End of the main function body.

int bubble(int a[], int size)
{

    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - (i + 1); j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return 0;
} 

int merge(int a[], int left, int m, int right)
{
    int i, j, k;
    int n1 = m - left + 1;
    int n2 = right - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    /* Merge the temp arrays back into a[left..right]*/
    i = 0;    // Initial index of first subarray
    j = 0;    // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if thereare any */
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
    return 0;
}

/* left is for left index and right is right index of the sub-array of a to be sorted */
int mergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        // Same as (left+right)/2, but avoids overflow for large left and h
        int m = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(a, left, m);
        mergeSort(a, m + 1, right);

        merge(a, left, m, right);
    }
    return 0;
}

int printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  \n", arr[i]);
    }
    return 0;
}


/*Which algorithm is faster Bubble Sort and why? 

Bubble Sort Alogrithm is a sorting Alogrithm used to loop through elements in array

Here’s how it works: given an unsorted array, for the full length of that array, we pass over each element; comparing it with the element next to it. If the first element is larger than the second, we swap the two elements.

Merge Sort Alogrithm is a Recursive sorting ALogrithm
 
Here’s how it works: which takes a divide-and-conquer approach to sorting; recursively breaking the input array down until we have sorted tuple-sized subarrays that we can then merge back together at the end.

Comparing Bubble Sort and Merge Sort: Time-Complexity Analysis:-

Bubble Sort becomes less efficient when it comes to sorting larger data sets (or ‘big data’). Where as, Merge Sort becomes more efficient as data sets grow.
And this is due to time complexicity 
bubble sort has O(n), and worst case scenario, it has O(n²) time complexity (which is pretty bad).
On the other hand, merge sort performs pretty consistently, with a time complexity of O(n log(n)). The time complexity of our helper functions for merge sort make this possible.*/