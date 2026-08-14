

/*
Algorithm: Insertion Sort
Date: 31/07/2026

Description:
Builds a sorted portion of the array one element at a time.
Each element from the unsorted portion is inserted into its correct position
by shifting larger elements one position to the right.

Time Complexity:
Best Case: O(n)   - Array is already sorted.
Average Case: O(n²)
Worst Case: O(n²) - Array is sorted in reverse order.

Space Complexity:
O(1) - Uses only constant extra memory.

Stable:
Yes - Equal elements retain their relative order.

In-place:
Yes - Sorting is performed within the original array.

Advantage:
Efficient for small datasets and nearly sorted arrays because it minimizes shifts.

Disadvantage:
Inefficient for large datasets due to its O(n²) time complexity.
*/
#include <iostream>
using namespace std;
void insertion_sort(int arr[],int len){
    for (int i=1;i<len;i++){
        int key=arr[i];
        int j=i-1;
        
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;


    }
     for (int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int n;
    cout<<"How many elements?";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element for index "<<i<<":";
        cin>>arr[i];
    }
    insertion_sort(arr,n);

    return 0;
}