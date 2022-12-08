class Solution {
public:
  
    int leastInterval(vector<char>& tasks, int n) {



        unordered_map<char,int> hmap;
        int mx=INT_MIN;
        for(auto c : tasks){
            hmap[c]++;
            mx = max(mx,hmap[c]);
        }

        int res = (mx-1)*(n+1);

        for(auto itr:hmap) if(itr.second==mx) res++;

        return res>tasks.size() ? res : tasks.size();



    }
};
