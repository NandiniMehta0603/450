class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //base case
        int n=strs.size();
        if(n==1){
            return strs[0];
        }
        string ans="";
        //comparing the first 2 words
        string first=strs[0];
        string second=strs[1];
        for(int i=0;i<first.length() && i<second.length();i++){
            if(first[i]==second[i]){
                ans+=first[i];
            }else{
                break;
            }
        }
        if(ans.length()>0){
            //keep comparing the string 
            for(int i=2;i<n;i++){
                string temp=strs[i];
                string res="";
                for(int j=0;j<ans.length() && j<temp.length();j++){
                    if(ans[j]==temp[j]){
                        res+=ans[j];
                    }
                }
                ans=res;
            }
        }
        return ans;
    }
};
