/*
Name:Linear Search
Date: 31/7/26
Description:Iterate over the array once and check if the current element is the required element

Time Complexity
Best Case: (O(1)) — The target element is found at the very first position of the array.
Average Case: (O(n)) — The target element is located near the middle, requiring roughly (n/2) comparisons.
Worst Case: (O(n)) — The target element is at the very end of the array or does not exist in the collection at all

Space Complexity: (O(1)) — It uses constant extra memory because it only tracks a few loop variables.

Suitable for:
- Small arrays
- Unsorted data

Not suitable for:
- Large datasets where repeated searching is required

*/

using namespace std;
void linear_search(int arr[],int len){
    int key;
    cout<<"Which element to find?";
    cin>>key;
    for(int i=0;i<len;i++){
        if(arr[i]==key){
            cout<<"Element "<<key<<" is at index "<<i;
            return;
        }
        
    }
    cout<<"Couldnt find "<<key<<" in the array ";
    
}



int main(){
    int n;
    cout<<"How many elements?";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element for index "<<i<<":";
        cin>>arr[i];
    }
    linear_search(arr,n);
    return 0;
}