class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i =0 ;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
    }
};

//or


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	int len = nums.size(), i=0, j; // two pointer, i slow, j fast

	for(j = 1; j < len; ++j) {
		if(nums[i] != nums[j])
			nums[++i] = nums[j]; // move i only if you find a unique element
	}
	return i + 1; 
    }
};
