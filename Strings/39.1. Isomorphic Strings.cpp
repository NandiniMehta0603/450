class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,int> visited;
        if(s.length()!=t.length()){
            return false;
        }
        int index=0;
        while(index!=s.length()){
            
            if(mp.find(s[index])!=mp.end() && mp[s[index]]==t[index]){
                index++;
            }
            else if(mp.find(s[index])==mp.end()){
                if(visited[t[index]]==true){
                    return false;
                }
                else{
                    mp[s[index]]=t[index];
                    visited[t[index]]=true;
                    index++;
                }
                
            }
            else{
                return false;
            }
        }
        return true;
    }
};
