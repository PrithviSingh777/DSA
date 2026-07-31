//bubble sort 


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
