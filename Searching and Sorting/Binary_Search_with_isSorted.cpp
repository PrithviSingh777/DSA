/*
Name: Binary Search
Date: 31/7/26
Description: Divide the search space in half repeatedly by comparing the target to the middle element

Time Complexity
Best Case: (O(1)) The target element is located exactly at the middle position on the first check.
Average Case: (O(log n)) The search space is halved at each step, requiring logarithmic comparisons.
Worst Case: (O(log n)) The target element is found at the final division or does not exist in the collection.

Space Complexity:
Iterative Approach: (O(1)) It uses constant extra memory to store pointers.
Recursive Approach: (O(log n)) It uses logarithmic memory due to the call stack frames.

Suitable for:
 Large datasets where fast lookups are essential
 Sorted arrays or lists with direct index access

Not suitable for:
 Unsorted data unless you sort it first
 Linked lists where accessing the middle element takes linear time
*/


#include <iostream>
using namespace std;
bool isSorted(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

void binary_search(int arr[], int n)
{
    int left = 0;
    int right = n - 1;
    int pivot;
    int key;

    cout << "Which element to find? ";
    cin >> key;

    if (!isSorted(arr, n))
    {
        cout << "Your array is not sorted";
        return;
    }

    while (left <= right)
    {
        pivot = (left + right) / 2;

        if (arr[pivot] == key)
        {
            cout << "Element " << key << " found at index " << pivot;
            return;
        }
        else if (arr[pivot] > key)
        {
            right = pivot - 1;
        }
        else
        {
            left = pivot + 1;
        }
    }

    cout << "Couldn't find " << key << " in the array";
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
    binary_search(arr,n);
    


	return 0;
}