class Solution {
public:
  string predictPartyVictory(string senate) {
//       //my implementation
//       int c1=0, c2=0;
//       //deque 
//       deque<char> q;
//       for(auto c : senate){
//           if(c=='R') c1++;
//           if(c=='D') c2++;
//           q.push_back(c);
//       }
//     //while both characters are present in the deque
//       while(c1>0 && c2>0){
//           //take out first queue
//           int co = 0;
//           char c = q.front();
//           q.pop_front();
//           cout<<c<<endl;
//           bool isR = c=='R';
//           co++;
//           while(c == q.front()){
//               q.pop_front();
//               co++;
//           }
//           if(!q.empty()){
//               q.pop_front();
//           }
//           //decrease count of other character
//           if(isR){
//               c2--;
//           }
//           else{
//               c1--;
//           }
//           //push back all the other characters back at the front
//           while(co-1){
//               q.push_front(c);
//               co--;
//           }
//           //push back the last character at the end
//           while(co){
//               q.push_back(c);
//               co--;
//           }

//       }
//    //check which character count was left zero

// return c1==0 ? "Dire" : "Radiant";


// from discussion, here we are using two queues
    queue<int> q1, q2;
    for(int i=0;i<senate.size();i++){
        if(senate[i]=='R') q1.push(i);
        else q2.push(i);
    }
    //store the indices of each character
    //until one of the two queue becomes empty, 
    //keep entering the smaller index in the queue again but 
    //in a circular manner
    while(!q1.empty() && !q2.empty()){
        int i = q1.front(), k = q2.front();
        q1.pop();q2.pop();
        (i<k) ? q1.push(i+senate.size()) : q2.push(k+senate.size());
    }

    return q1.empty() ? "Dire" : "Radiant";
    }
};
