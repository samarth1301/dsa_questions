// question link - https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/submissions/


//find median and return its diff with each elemtent.
class Solution {
public:
   static int findMedian(vector<int> a)
    {
    // First we sort the array
    sort(a.begin(), a.end());
    int n= a.size();
    // check for even case
    if (n % 2 != 0)
        return a[n / 2];
 
    return (a[(n - 1) / 2] + a[n / 2]) / 2.0;
    }
    int minMoves2(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n=nums.size(), avg = sum/n;
        int median = findMedian(nums);
        int res=0;
        for(int i=0;i<n;i++){
            // cout<<abs(nums[i]-median)<<endl;
            res+=abs(nums[i]-median);
        }
        return res;
    }
};
