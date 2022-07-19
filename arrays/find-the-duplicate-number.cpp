class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int duplicate =-1;
        for(int x: nums){
            int temp = abs(x);
            if(nums[temp]<0){
                return temp;
            }
            nums[temp]*=-1;
        }
        return -1;
    }
};

//or 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     
        unordered_set <int> bucket;
        for( int x: nums){
            
           
            if(bucket.find(x)!=bucket.end()){
                return x;
            }
            bucket.insert(x);
           
            
            
        }
        return 0;
    }
};
