/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

bool checkReverse(int arr[],int n){
    //O(nln(n))
    // vector<int> arr2(arr,arr+n);
    // //create a duplicate sorted array to get the st and end index of array that need to be rotated
    // sort(arr2.begin(),arr2.end());
    // int i;
    // for(i=0;i<n && arr[i]==arr2[i];){
    //     i++;
    // }
   
    // int j=0;
    // for(j=n-1;j>=0 && arr[j]==arr2[j];){
    //     j--;
    // }
    // //in case i>=j ,we have a sorted array, so return true. 
    //  if(i>=j)
    //     return true;
    // // otherwise iterate in the original array and check if all the elements in range st and end are 
    // //decreaing or not
    // for(int k=i+1;k<=j;k++){
    //     if(arr[k-1]<arr[k]){
    //         return false;
    //     }
    // }
    // // cout<<i<<" "<<j<<endl;
    // return true;
    
    
    // O(N)
    int i,j,k;
    for(i=1;i<n && arr[i]>arr[i-1];) i++;
    
    if(i==n) return true;
    
    
    for(int j=i;j<n && arr[j]<arr[j-1];j++){
        if(arr[j]<arr[i-2]){
            return false;
        }
    }
    if(j==n) return true;
    
    if(arr[j]<arr[i-1]){
        return false;
    }
    
    for(k=j;k<n;k++){
        if(arr[k]<arr[k-1])
        return false;
    }
    
    return true;
    
    
}

int main()
{
    int arr[] = {1,2,3,4,20,9,16,17};
    // int arr[] = { 1, 2, 5, 4, 3,6 };
    // int arr[] = { 1, 2, 4, 5, 3 };
    int n = sizeof(arr)/sizeof(arr[0]);
 
    checkReverse(arr, n)? (cout << "Yes" << endl):
                          (cout << "No" << endl);
    return 0;
}
