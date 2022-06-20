// question - https://leetcode.com/problems/valid-square/
class Solution {
public:
    
    // comparator to sort a 2d array such that x value is maintained
    // and if x is equal then sorting is done on the basis of y 
    
    static bool comp(vector<int> a, vector<int> b){
        if(a[0]<b[0]){
            return true;
        }
        if(a[0]==b[0] && a[1]<b[1]){
            return true;
        }
        return false;
    }
    
    //helper function to get distance between two points
    
    int getDist(vector<int> a, vector<int> b){
        return ((b[0]-a[0])*(b[0]-a[0]))+((b[1]-a[1])*(b[1]-a[1]));
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        //2d array which wil store 4 coordinates
        vector<vector<int>> arr;
        //if any point is equal return false, coz than it cant be square
        if(p1 == p2 || p2 == p3 || p3==p4 || p4==p1){
            return false;
        }
        arr.push_back(p1);
        arr.push_back(p2);
        arr.push_back(p3);
        arr.push_back(p4);
        //add all coordinates in 2d array and sort it
        sort(arr.begin(),arr.end(),comp);
       //now just return if all the sides are equal to each other and diagonals are also equal
        //diagonals of a square are equal.
        return (getDist(arr[0],arr[1])==getDist(arr[2],arr[3])) && (getDist(arr[0],arr[1])==getDist(arr[0],arr[2])) &&(getDist(arr[1],arr[3])==getDist(arr[2],arr[0])) && (getDist(arr[0],arr[3])==getDist(arr[2],arr[1]));
       
    }
};
