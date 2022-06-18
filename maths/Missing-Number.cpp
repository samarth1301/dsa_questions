//question link -https://leetcode.com/problems/missing-number/submissions/
//simply add all the numbers and subtract from the sum you are getting from the sum of array elements;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sumN=0,sum=0;
        for(int i=0;i<=nums.size();i++){
            sumN+=i;
        }
        sum = accumulate(nums.begin(),nums.end(),0);
        return sumN-sum;
    }
};
