bool findPair(int arr[], int size, int n){
    //code
    //map to store each value of arr and its count
    unordered_map<int,int> hmap;
    for(int i=0;i<size;i++){
        int el = arr[i];
        //if any previous element difference is equal to n
        //return true
        //case when el is the greater number      case when el is the smaller number
        if(hmap.find(el-n)!=hmap.end() || hmap.find(el+n) != hmap.end()){
            return true;
        }
        //keep account of each element;
        hmap[el]++;
    }
    return false;
     //method-2
    //sort array
    sort(arr,arr+size);
    int i=0,j=1;
    //in case n==0, look for duplicate elements
    if(n==0){
        for(int i=1;i<size;i++){
            if(arr[i-1]==arr[i]){
                return true;
            }
        }
        return false;
    }
    //else traverse through the array, in case diff found, return true,
    //else , if diff is greater than n, increment i to lower it down
    //if diff is lesser than n, increment j to increase diff
    while(i<size-1 && j<size){
        
        if(arr[j]-arr[i]==n){
            return true;
        }
        if((arr[j]-arr[i])>n){
            i++;
        }
        else{
            j++;
        }
    }
    return false;
}
