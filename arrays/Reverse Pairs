class Solution {
public:
    vector<int> nums;
    int reversePairs(vector<int>& nums) {
        int n= nums.size(),count=0;
        //TLE
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         long long int temp = nums[j];
        //         temp*=2;
        //         if(nums[i]>temp){
        //             count++;
        //         }
        //     }
        // }
        
        //O(n ln(n))
//         unordered_map <int,int> hmap;
//         for(int i=0;i<n;i++){
//             hmap[nums[i]]++;
            
//         }
//use merge sort and in each mergin procedure
//check for each elemtent og left subarray if the right subarray's element's double is still less than it 
// in such case move to the next element of the right subarray, and as both the arrays are sorted
// for the next element in the left subarray, the double of the past j values are already less 
//thus we wont bother to reset the value of j and start checking from the present value
// then add in count the diff between j and mid+1 (so that we get the numbers of elemtns whose double is less than specific elemetn in the left subarray). 
        int low = 0,high = n-1;
        this->nums = nums;
        return mergesort(low,high);
    }
    int mergesort( int low, int high){
        if(low>=high){
            return 0;
        }
        int mid = (low+high)/2,count=0;
        count+= mergesort(low,mid);
        count+= mergesort( mid+1, high );
        count+= merge(low,mid,high);
        return count;
    }
    
    int merge(int low, int mid, int high){
        int count=0,j=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && nums[i]>2ll*nums[j]){
                j++;
            }
            count+=j-(mid+1);
        }
        int i=low; j=mid+1;
        vector<int> temp;
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
         while(i<=mid ){
              temp.push_back(nums[i]);
          i++;
        }
          while(j<=high){
              temp.push_back(nums[j]);
          j++;
        }
        
        
        for(int k = low;k<=high;k++){
            nums[k]= temp[k-low];
        }
        return count;
        
    }
};
