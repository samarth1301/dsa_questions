#include <bits/stdc++.h>
using namespace std;
  
class LRUCache {
    // store keys of cache
    list<int> dq;
  
    // store references of key in cache so we dont need to find any element using O(n) operation
    unordered_map<int, list<int>::iterator> ma;
    int csize; // maximum capacity of cache
  
public:
    LRUCache(int);
    void refer(int);
    void display();
};
  
// Declare the size
LRUCache::LRUCache(int n)
{
    csize = n;
}
  void LRUCache::refer(int x)
{
  if(ma.find(x)==ma.end()){
      if(dq.size()==csize){
          int x  = dq.back(); 
          dq.pop_back();
          
          ma.erase(x);
      }
  }
  else{
    //   int x = 
    dq.erase(ma[x]);
  }
  dq.push_front(x);
  ma[x] = dq.begin();
}
  
// Function to display contents of cache
void LRUCache::display()
{
  for(auto itr= dq.begin();itr!= dq.end();itr++){
      cout<<*itr<<" ";
  }
  cout<<endl;
    
}
int main()
{
    LRUCache ca(4);
  
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();
  
    return 0;
}
