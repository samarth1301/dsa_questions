class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        unordered_set<string> seen;
        q.push(start);
        seen.insert(start);
        int steps = 0;
        while(!q.empty()){
            int x = q.size();
            for(int j=0;j<x;j++){
                string node = q.front();
                q.pop();
                if(node==end) return steps;
                int s = node.size();
                for(char c:"ACGT"){
                    for(int i=0;i<s;i++){
                        string temp = node;
                        temp[i] = c;
                        if(!seen.count(temp) && find(bank.begin(),bank.end(),temp)!=bank.end()){
                            q.push(temp);
                            seen.insert(temp);
                        }
                    }
                }
            }
           
           steps++;
        }
        return -1;
      
    }
};
