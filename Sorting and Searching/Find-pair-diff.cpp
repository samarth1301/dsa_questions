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
}
