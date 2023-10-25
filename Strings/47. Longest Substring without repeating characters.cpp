class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0;
        int n=s.length();
        int end=0;
        unordered_map<char,int> mp;
        int ans=INT_MIN;
        while(end<n){
            mp[s[end]]++;
            if(mp[s[end]]>1){
                while(start<=end){
                    if(s[start]==s[end] && mp[s[start]]-1==1){
                        mp[s[start]]--;
                        start++;
                        break;
                    }
                    else{
                        mp[s[start]]--;
                        start++;
                    }
                }
            }
            else{
                ans=max(ans,end-start+1);
            }
            end++;
        }
        if(ans==INT_MIN){
            ans=0;
        }
        return ans;
    }
};
