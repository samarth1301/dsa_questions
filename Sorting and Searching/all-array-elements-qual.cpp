/******************************************************************************
O(N)

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
//only consition here is the array should be sorted
int minCostToMakeElementEqual(int arr[],int n){
    int y;
    if(n%2==1){
        y=arr[n/2];
    }
    else{
        y=(arr[n/2]+(arr[(n/2)-1]))/2;
    }
    int s=0;
    for(int i=0;i<n;i++){
        s+=abs(y-arr[i]);
    }
    return s;
}

int main()
{
    int a[] = { 1,4 , 6, 100, 101 };
    int n = sizeof(a) / sizeof(a[0]);
     
    cout << (minCostToMakeElementEqual(a, n));
}
