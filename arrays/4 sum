//just like 3 sum with and additional loop and condition for chekcing duplicates

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size(),indx=-1;
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<n-3;i++){
            if(i!=0 && nums[i-1]==nums[i]){
                continue;
            }
            for(int j=i+1;j<n-2;j++){
                if(j!=i+1 && nums[j]==nums[j-1] ){
                    continue;
                }
                int rqrd = target-(nums[i]+nums[j]);
                int k= j+1, l = n-1;
                while(k<l){
                    if(nums[k]+nums[l]>rqrd){
                        l--;
                    }
                    else if(nums[k]+nums[l]<rqrd){
                        k++;
                    }
                    else{
                       // cout<<i<<endl;
                        vector<int> arr;
                        arr.push_back(nums[i]);
                        arr.push_back(nums[j]);
                        arr.push_back(nums[k]);
                        arr.push_back(nums[l]);
                        
                        if(indx==-1 || res[indx][0]!=arr[0] || res[indx][1]!=arr[1]|| res[indx][2]!=arr[2]|| res[indx][3]!=arr[3]){
                            res.push_back(arr);
                            indx++;
                        }
                        k++; l--;
                    }
                }
            }
        }
        return res;
    }
};
