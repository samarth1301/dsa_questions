class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hmap={{0,0}};
        
        int sum=0;
        for(int i=0 ; i<nums.size();i++){
            sum+=nums[i];
            
            // cout<<sum<<endl;
            if(!hmap.count(sum%k)){
                hmap[sum%k] = i+1;
            }
            else if(hmap[sum%k]<i){
                return true;
            }
            // if((s.find(sum%k)!=s.end()) || sum == 0) return true;
            // s.insert(sum%k);
        }
        return false;
    }
};
