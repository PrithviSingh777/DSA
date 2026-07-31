/*
Name: Sentinel Linear Search
Date: 31/7/26
Description: Replace the last element of the array with the target value to eliminate array boundary checks within the main loop

Time Complexity
Best Case: (O(1)) The target element is found at the very first position of the array.
Average Case: (O(n)) The target element is located near the middle, traversing linear elements.
Worst Case: (O(n)) The target element does not exist in the collection and is only found at the appended sentinel position.

Space Complexity: (O(1)) It uses a constant amount of extra memory to store the original last element.

Advantage:
The main search loop performs only one comparison (arr[i] != key) per iteration, avoiding an additional boundary check (i < len).
*/
#include <iostream>
using namespace std;
void sentinel_search(int arr[],int len){
    int key;
    cout<<"Element to find:";
    cin>>key;
    int temp;
    temp=arr[len-1];
    arr[len-1]=key;
    int i=0;
    if (len == 0)
{
    cout << "Array is empty.";
    return;
}
    while(arr[i]!=key){
        i++;
    }
    arr[len-1] = temp;
 
       
    
    
     
     if(i<len-1){
         cout<<"Element "<< key <<"found at index "<<i;
     }
     else if(temp==key){
         cout<<"Element "<< key <<"found at index "<<len-1;
     }
     else{
         cout<<"Element "<< key <<" not found ";
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
    sentinel_search(arr,n);

    return 0;
}