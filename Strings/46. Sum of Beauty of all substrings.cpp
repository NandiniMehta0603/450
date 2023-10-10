class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            unordered_map<char,int> mp;
            // int maxi=INT_MIN;
            // int mini=INT_MAX;
            // string temp="";
            for(int j=i;j<s.length();j++){
                mp[s[j]]++;
                // cout<<mp[s[j]]<<" ";
                // temp+=s[j];
                int maxi=INT_MIN;
                int mini=INT_MAX;
                for(auto i:mp){
                    maxi=max(maxi,i.second);
                    mini=min(mini,i.second);
                }
                ans+=(maxi-mini);
                // maxi=max(maxi,mp[s[j]]);
                // mini=min(mini,mp[s[j]]);
                // ans+=(maxi-mini);
                // cout<<"Temp is: "<<temp<<" "<<ans<<endl;
            }
            mp.clear();
        }
        return ans;
    }
};
