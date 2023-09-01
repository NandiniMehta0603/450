class Solution {
public:
    string largestOddNumber(string num) {
        int end=num.length()-1;
        string ans="";
        while(end>=0){
            int n=num[end]-'0';
            if(n%2!=0){
                ans=num.substr(0,end+1);
                break;
            }
            else{
                end--;
            }
        }
        return ans;
    }
};
