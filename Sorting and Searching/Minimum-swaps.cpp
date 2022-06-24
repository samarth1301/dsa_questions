class Solution 
{
    public:
    void swap(vector<int>& arr, int i, int j){
        int temp = arr[i];
        arr[i]= arr[j];
        arr[j] = temp;
    }
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int res =0;
	    vector<int> arr(nums.begin(),nums.end());
	    //sort duplicate array
	    sort(arr.begin(),arr.end());
	    //store index of each element in hmap, key as element, value as index in original array
	    unordered_map<int,int> hmap;
	    int n = arr.size();
	    for(int i=0;i<n;i++){
	        hmap[nums[i]] = i;
	    }
	    //traverese each element, but if any element is not at its correct place,
	    //increment the swap count and swap the number with the correct number using
	    //hmap and ur duplicate array.
	    //also update the hmap with new indices for ur values.
	    for(int i=0;i<n;i++){
	        if(arr[i]!=nums[i]){
	            res++;
	            int temp = nums[i];
	            swap(nums,i,hmap[arr[i]]);
	            
	            hmap[temp] = hmap[arr[i]];
	            hmap[arr[i]] = i;
	        }
	    }
	    return res;
	}
};
