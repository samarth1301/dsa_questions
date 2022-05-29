class Solution {
public:
    int majorityElement(vector<int>& nums) {
    //suing map for counting each number's count
        // unordered_map<int,int> hmap;
        // for(int el : nums){
        //     hmap[el]++;
        //     if(hmap[el]>nums.size()/2){
        //         return el;
        //     }
        // }
        
        // return -1;
        
        //using the fact that if a number exists for more than n/2 times, it will be reapeated at most
        //thus keep counting a new element, in case other elements found, decrement the count, 
        //if count becomes zero, make the element equalt to the present element in the iteration and start counting again.
        
        int element,count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                element = nums[i];
            }
            count+= nums[i]==element ? 1 :-1;
        }
        
        
        return element;
        
    }
};
