//brute fore is O(N^3)
//this is O(NlnN)
//simply sort the array and in case of positive numbers
//last three number will give the max produxt
//but in case of negative as well as positive numbers
//product of last element with first two element(which will become positve if they are negative)
//can be max too

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        return max(nums[0]*nums[1]*nums[n-1], nums[n-1]*nums[n-2]*nums[n-3]);
    }
};
