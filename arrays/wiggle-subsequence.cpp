class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        bool high = false;
        int c= 1;
        int n = nums.size();
        if(n==1){
            return 1;
        }
       
        int i=1;
        if(nums[0]==nums[1]){
            
            while(i<n && nums[i]==nums[i-1]){
                i++;
            }
            if(i==n){
                return 1;
            }
           
        }
        if(nums[i-1]>nums[i]){
            high = false;
        }
        if(nums[i-1]<nums[i]){
            high = true;
        }
        for(i;i<n;i++){
            if(high && nums[i]>nums[i-1]){
                c++;
                high = false;
            }
            else if(!high && nums[i]<nums[i-1]){
                c++;
                high = true;
            }
        }
        return c;
    }
};
