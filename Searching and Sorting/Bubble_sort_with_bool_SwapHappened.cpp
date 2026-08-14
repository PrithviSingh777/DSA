/*
Algorithm: Bubble Sort
Date: 31/07/2026

Description:
Repeatedly compares adjacent elements and swaps them if they are in the wrong order.
After each pass, the largest unsorted element moves to its correct position at the end of the array.
The optimized version stops early if a complete pass occurs without any swaps.

Time Complexity:
Best Case: O(n)   - The array is already sorted (optimized version).
Average Case: O(n²)
Worst Case: O(n²) - The array is sorted in reverse order.

Space Complexity:
O(1) - Uses only a constant amount of extra memory.

Stable:
Yes - Equal elements retain their relative order.

In-place:
Yes - Sorting is performed within the original array.

Advantage:
Simple to understand and implement.
The optimized version can terminate early if the array is already sorted.

Disadvantage:
Performs poorly on large datasets due to its O(n²) time complexity.
*/


#include <iostream>
using namespace std;
void bubble_sort(int arr[],int len){
    
   
    int temp;
    for (int i=0;i<len-1;i++ ){
         bool SwapHappened=false;
        for(int j=0;j<len-1-i;j++){
            if (arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                SwapHappened=true;
                
                
            }
        }
        if(!SwapHappened){
            break;
        }
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
    bubble_sort(arr,n);
    

    return 0;
}
