/******************************************************************************

   O(N+K)

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int> &arr,int n){
    int min= *min_element(arr.begin(),arr.end());
    int max = *max_element(arr.begin(),arr.end());
    int range = max-min+1;
    vector<int> hmap(range,0);
    for(int i=0;i<n;i++){
        hmap[arr[i]-min]++;
    }
    for(int i=1;i<range;i++){
        hmap[i] += hmap[i-1];
    }
    vector<int> res(n,0);
    for(int i=0;i<n;i++){
        res[--hmap[arr[i]-min]] = arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=res[i];
    }
}


// Driver  code
int main()
{
    vector<int> arr = {1,3,2,6,11,15,4,-1};
 
    countSort(arr,8);
 
    cout << "Sorted character array is " << endl;
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
