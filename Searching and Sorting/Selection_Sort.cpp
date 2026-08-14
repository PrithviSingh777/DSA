/*
Selection sort(Select the smallest element and place it at start)
Time Complexity:
Best Case: O(n²)
Average Case: O(n²)
Worst Case: O(n²)

Space Complexity:
O(1)

Stable:
No

In-place:
Yes
*/
#include <iostream>
using namespace std;
void selection_sort(int arr[],int len){
    int temp;
    
    
    for(int i=0;i<len-1;i++){
        int min=i;
        for(int j=1+i;j<len;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    for (int i=0;i<len;i++){
        cout<<arr[i]<<" ";}
    
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
    selection_sort(arr,n);
    


    return 0;
}