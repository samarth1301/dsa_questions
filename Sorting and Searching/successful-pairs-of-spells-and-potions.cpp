class Solution {
public:

    int helper(long long m, vector<int>& p, long long s){
        int low = 0, high = p.size()-1;
        int i=-1;
        while(low<=high){
            int mid = (low) + (high-low)/2;
            if(p[mid] * m>=s){
                high = mid-1;
                i=mid;
            }
            else{
                low = mid+1;
            }
        }
        return i==-1 ? 0 : p.size()-i;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res(spells.size(),0);
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size(); i++){
            int x = helper(spells[i],potions, success);
            res[i] = x;
        }
        return res;
    }
};
