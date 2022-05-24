class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     
        vector<int> arr;
        int n=nums.size(),i=0,j=n-1;
       
        for(int i=0;i<n;i++){
            int reqrd = target-nums[i];
            auto indx = find(nums.begin()+i+1,nums.end(),reqrd);
            if(indx!=nums.end()){
                arr.push_back(i);
                arr.push_back(indx-nums.begin());
                return arr;
            }
        }
        
        return arr;
        
        
        
    }
};


//or

//better solution


//here we are using map to store {element, index} 


 unordered_map<int,int> hmap;
        for(int i=0;i<n;i++){
            int rqrd = target - nums[i];
            if(hmap.find(rqrd)!=hmap.end()){
                arr.push_back(hmap[rqrd]);
                arr.push_back(i);
                return arr;
            }
            hmap.insert({nums[i],i});
            
        }
        return arr;
        
