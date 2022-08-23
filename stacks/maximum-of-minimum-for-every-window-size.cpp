vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        // vector<int> res(n,0);
        // for(int k = 1 ; k <= n ;k++){
        //     int mx = INT_MIN;
        //     for(int i = 0;i<=n-k;i++){
        //         int mn = arr[i];
        //         for(int j = 1;j<k;j++){
        //             mn = min(mn,arr[i+j]);
        //         }
        //         mx = max(mx,mn);
        //     }
        //     res[k-1] = mx;
        // }
        // return res;
        //TLE
        stack<int> st;
        vector<int> right(n,n);
        vector<int> left(n,-1);
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()){
                left[i] = st.top();   
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
         for(int i = n-1 ; i >=0 ; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()){
                right[i] = st.top();   
            }
            st.push(i);
        }
        vector<int> res(n+1,0);
        for(int i = 0 ; i<n;i++){
            int indx = right[i] - left[i] - 1;
            res[indx] = max(res[indx],arr[i]);
           
        }
        
        for(int i = n-1;i>0;i--){
            res[i] = max(res[i+1],res[i]);
        }
        res.erase(res.begin());
        return res;
    }
