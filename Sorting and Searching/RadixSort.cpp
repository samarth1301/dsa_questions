/******************************************************************************
O(N+(10)+D)

N-number of elements in array,
D-number of digits in max element

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

void countSort(int arr[],int digit,int n){
    vector<int> output(n);
    vector<int> count(10,0);
    for(int i=0;i<n;i++){
        count[(arr[i]/(digit))%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    
    
    
    
    for(int i=n-1;i>=0;i--){
        output[--count[(arr[i]/(digit))%10]]=arr[i];
    }
    
    
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
    
}


void radixsort(int arr[],int n){
    int max = *max_element(arr,arr+n);
    for(int digit=1;max/digit>0;digit*=10){
        countSort(arr,digit, n);
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);
      
      // Function Call
    radixsort(arr, n);
    print(arr, n);
    return 0;
}
