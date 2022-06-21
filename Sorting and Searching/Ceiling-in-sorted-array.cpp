/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int binarySearch(int arr[],int st,int end, int x){
    // if(st>=end){
    //     return -1;
    // }
    
    
    if(x<=arr[st]){
        return st;
    }
    if(x>arr[end]){
        return -1;
    }
    
    int mid = (st+end)/2;
    
    if(arr[mid]==x){
        return mid;
    }
    
    if(arr[mid]>x){
        if(mid-1>=st && arr[mid-1]<x){
            return mid;
        }
        return binarySearch(arr,st,mid-1,x);
    }
    else{
        if(mid+1<=end && arr[mid+1]>x){
            return mid+1;
        }
        return binarySearch(arr,mid+1,end,x);
    }
    
    
}

int ceilSearch(int arr[],int st,int end,int x){
    return binarySearch(arr,st,end,x);
    
    
    
    
    
    
    
    ///O(N) approach
    // for(int i=st;i<=end;i++){
    //     if(arr[i]>=x){
    //         return i;
    //     }
    // }
    // return -1;
}

int main()
{
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 15;
    int index = ceilSearch(arr, 0, n-1, x);
    if(index == -1)
        cout << "Ceiling of " << x << " doesn't exist in array ";
    else
        cout << "ceiling of " << x << " is " << arr[index];
     
    return 0;
}
