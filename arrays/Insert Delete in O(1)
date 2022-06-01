class RandomizedCollection {
public:
    //insert and get random can be done in O(1) time but for remove, we need a map
    //this map will tell all the indices of a particular element.
    vector <int> arr;
    unordered_map <int,unordered_set<int>> hmap;
    RandomizedCollection() {
        srand(10);//for random number
    }
    
    bool insert(int val) {
        bool res=true;
        if(hmap.find(val)!=hmap.end()){
            res=false;
        }
        arr.push_back(val);
        hmap[val].insert(arr.size()-1);// as element is addded at the last
        return res;
    }
    
    bool remove(int val) {
        bool res=false;
        //initially false 
        //if val found in hmap then true
          auto itr = hmap.find(val);
          if(itr!=hmap.end()){
             res=true;
              //lets find the index of the first occurence of our val in the set of hmap.
              // another way of writing the below line
                //hmap[val].begin()               
              int indx =*(itr->second.begin());
              hmap[val].erase(hmap[val].begin());
             //this number is going to be removed, so we will remove it from the hmap too
              
              // now we will swap the val with the last index in order to remove it in O(1)
              //but for that, first we need to change the value in hmap for last index
              //so first we add this new index in hmap
              
              hmap[arr[arr.size()-1]].insert(indx);
              
              
              //now we will erase the previous value at which the element was previously
              hmap[arr[arr.size()-1]].erase(arr.size()-1);
              //if after removing the number, there is no other occurence, remove it from the hmap
              if(hmap[val].size()==0){
                   hmap.erase(itr);
              }
              
              //swap the last element with the val
                arr[indx]=arr[arr.size()-1];
              //pop the new last element
              arr.pop_back();
         }
        
        return res;
    }
    
    int getRandom() {
        int x = rand()%arr.size();
        //returning a random index value
        return arr[x];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
