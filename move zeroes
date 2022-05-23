//this method uses count and removes and pushes zero at the same time until size-count og 0 times

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c = count(nums.begin(),nums.end(),0);
        for(int i=0;i<nums.size();i++){
             // cout<<i<<endl;
            if(i==nums.size()-c){
                break;
            }
            if(nums[i]==0){
                nums.erase(nums.begin()+i);
                nums.push_back(0);
               
                 i--;
            }
            // else{
            //     i++;
            // }
        }
    }
};

//or
//first remove all zeroes and count number of zeroes
//then push each zero count number of times
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        vector<int>::iterator it;
 
    it = nums.begin();
        for(int i=0; i <nums.size();i++){
            if(nums[i]==0){
                count++;
                nums.erase(it+i);
                i--;
            }
        }
        // remove(nums.begin(),nums.end(),0);
        while(count){
            nums.push_back(0);
            count--;
        }
    }
    
    
    
//or

//best method

//use one temp variable to store the index of last non zero number
// keep adding all the non zero elements and incrementing the temp variable
// then fill remaining values as zero.

 int temp =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[temp++]=nums[i];
            }
        }
        for(int i=temp;i<nums.size();i++){
            nums[i]=0;
        }
};
