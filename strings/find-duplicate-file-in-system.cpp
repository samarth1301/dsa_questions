class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> mp;
        for(auto s: paths){
          //simply split the string and store it in a map
            string temp,path;
                unordered_map<string,vector<string>> temp_mp;
                int i=0;
            while(s[i]!=' '){
                path+=s[i++];
            }
            i++;
            string key,value;
            for(i;i<s.size();){
                while(s[i]!='('){
                    value+=s[i++];    
                }
                i++;
                while(s[i]!=')'){
                    key+=s[i++];
                }
                i++;
                temp_mp[key].push_back(value);
                if(i<s.size() && s[i]==' '){
                    key="";
                    value="";
                    i++;
                }
            }
          //all files in one string are added in a temp map where key is content of file 
          //and values are file path
            for(auto itr:temp_mp){
                for(auto itr2: itr.second){
                     mp[itr.first].push_back(path+'/'+itr2);
                }
               
            }

        }
      
      //at last simply add all values in a matrix
        vector<vector<string>> res;
        for(auto itr: mp){
            vector<string> temp;
            // cout<<itr.first<<endl;
            for(auto itr2: itr.second){
                temp.push_back(itr2);
            }
          //no need to add a keyh with only one path , its own
            if(temp.size()==1) continue;
            // cout<<itr.second.size()<<endl;
            res.push_back(temp);
        }
        return res;
    }
};
