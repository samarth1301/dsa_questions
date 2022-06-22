/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int binary(int arr[],int st, int end, int x){
    if(x>=end){
        return end;
    }
    if(x<st){
        return -1;
    }
    
    int mid = (st+end)/2;
    
    if(arr[mid]==x){
        return mid;
    }
    else if(arr[mid]>x){
        if(mid-1>=st && arr[mid-1]<=x){
            return mid-1;
        }
        else{
            return binary(arr,st,mid-1,x);
        }
        
    }
    else if(arr[mid]<x){
        if(mid+1<=end && arr[mid+1]>x){
            return mid;
        }
        else{
            return binary(arr,mid+1,end,x);
        }
    }
    return 0;
}

int floorSearch(int arr[],int st,int end,int x){
    //O(n)
    
    for(int i=end;i>=st;i--){
        if(arr[i]<=x){
            return i;   
        }
    }
    return -1;
    
    
    //O(ln(n))
    return binary(arr,st,end,x);
    
}

int main()
{
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 9;
    int index = floorSearch(arr, 0, n-1, x);
    if(index == -1)
        cout << "Floor of " << x << " doesn't exist in array ";
    else
        cout << "Floor of " << x << " is " << arr[index];
     
    return 0;
}
