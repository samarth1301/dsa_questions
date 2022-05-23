class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0=0,count1=0,count2=0;
        for(int i : nums){
            if(i==0){
                count0++;
            }
            if(i==1){
                count1++;
            }
            if(i==2){
                count2++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(i<count0){
               
                nums[i]=0;
            }
           else if(i>=count0 && i<count0+count1){
                nums[i]=1;
            }
             // if(i>=count0+count1 && i<count0+count1+count2){
             else{   
                nums[i]=2;
            }
        }
    }
};

//or


 int n = nums.size();
        int i =0, j =n-1, k = n-1;
        while(i<=j&&i<=k){
            if(nums[i]==0){
                i++;
                continue;
            }
            else if(nums[i]==2){
                if(j<=k){
                    j=k-1;
                }
                swap(nums[i],nums[k--]);
            }
            else{
                swap(nums[i],nums[j--]);
            }
        }
