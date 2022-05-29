class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        //using extra space
//         int i=0,j=0;
//         vector<int> temp;
//         while(i<m && j<n){
           
//             if(nums1[i]<=nums2[j]){
//                                temp.push_back(nums1[i]);

//                 i++;
//             }
//             else if(nums1[i]>nums2[j]){
                
//                temp.push_back(nums2[j]);
//                 j++;
//             }
         
//         }
//         while(j<n){
          
//             temp.push_back(nums2[j]);
//             j++;
//         }
//         while(i<m){
//             temp.push_back(nums1[i++]);
//         }
//         // for(int i=0;i<temp.size();i++){
//         //     nums1[i]=temp[i];
//         // }
//         nums1=temp;
        
        
        
        
        
        
        
        
        
        //without using extra space
        
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                i++;
            }
            else{
                int k = m;
                while(k>i){
                    nums1[k]=nums1[k-1];
                    k--;
                }
                nums1[i]=nums2[j];
                i++;
                j++;
                m++;
            }
        }
        while(j<n){
            nums1[i++]=nums2[j++];
        }
        
    }
};
