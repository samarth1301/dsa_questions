class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(),idx=-1;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        //one loop for iteration
        for(int i=0;i<n-2;i++){
        //to check for duplicate numbers as the array is already sorted, if same number found again, just continue to next iteration
           if(i!=0 && nums[i-1]==nums[i]){
                continue;
           }
                 int rqrd = -nums[i];
             //   cout<<i<<endl;
            int j=i+1,k= n-1;
            //two pointers for 2 sum like problem
            while(j<k){
               //cout<<"j: "<<j<<" k: "<<k<<endl;
                int sum = nums[j]+nums[k];
                //cout<<"sum: "<<sum<<endl;
                if(sum==rqrd){
                    vector<int> arr;
                    arr.push_back(nums[i]);
                    arr.push_back(nums[j]);                                                                         arr.push_back(nums[k]);
                    //check for preventing duplicates again and again, sorted, thus, if any one value is diff, add in the res array.
                    if(idx==-1 || (res[idx][0]!=arr[0] || res[idx][1]!=arr[1] ||  res[idx][2]!=arr[2])){
                            res.push_back(arr);
                        idx++;
                    }
                    //if 3 sum found move both pointere closer
                j++;k--;
                    
                }
                //reduce the sum.
                else if(sum>rqrd){
                    k--;
                }
                //increase the sum
                else{
                    j++;
                }
           
            
        }
            }
          //vector<vector<int> temp(res.begin(),res.end());
        return res;
    }
};
