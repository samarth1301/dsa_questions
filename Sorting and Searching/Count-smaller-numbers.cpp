// bottt teekha question
//link : https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class Solution {
public:
    vector<int> count;

    vector<int> indx;
    vector<int> countSmaller(vector<int>& nums) {
        count.resize(nums.size(),0);
        indx.resize(nums.size());
        for(int i=0;i<nums.size();i++){
            indx[i]=i;
        }
      
        mergeSort(nums,0,nums.size()-1);
        
        return count;
    }
    
    void mergeSort(vector<int>& nums, int l, int r){
        if(l>=r) {
            return;
        }
        
        int mid = (l+r)/2;
        
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
         merge(nums,l,r,mid);
    }
    //sort in descending order
    //in place of sorting value, we are just keepin in record index
    void merge(vector<int>& nums, int l, int r, int mid){
        vector<int> tempIndx;
        int i=l,j=mid+1;
        while(i<=mid && j<=r){
            if(nums[indx[i]]<=nums[indx[j]]){
                tempIndx.push_back(indx[j++]);
            }
            else{
                //if left is greater than right, than all elements
                //to the right of j are also less
                count[indx[i]] += r-j+1;
                tempIndx.push_back(indx[i++]);
                
            }
        }
        
        while(i<=mid){
            tempIndx.push_back(indx[i++]);
        }
        while(j<=r){
            tempIndx.push_back(indx[j++]);
        }
        
        for(int i=l;i<=r;i++){
            indx[i]=tempIndx[i-l];
        }
        
    }
};
