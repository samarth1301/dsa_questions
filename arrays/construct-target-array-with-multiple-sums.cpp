// Basic Understanding from given question and approch to solve the problem.

// Step 1:
// Given that the sum is strictly increasing, the largest element in the target must be formed in the last step by adding the total sum in the previous step. Thus, we can simulate the process in a reversed way.

// Step 2:
// Subtract the largest with the rest of the array, and put the new element into the array. Repeat until all elements become one

class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n= target.size();
       priority_queue<long long> pq;
        long long int sum=0;
        for(auto i:target){
            sum+=i;
            pq.push(i);
        }
        while(pq.top()!=1){
            long long int x = pq.top();
            sum-=x;
            pq.pop();
            if(sum<=0 || sum>=x) return false;
            x = x%sum;
            sum+=x;
            pq.push(x?x:sum);
            
        }
        return true;
    }
};
