class Solution {
public:
    void compute(string &temp){
        for(int i=0;i<temp.length();i++){
            if(temp[i]<='Z' && temp[i]>='A'){
                temp[i]=temp[i]-'A'+'a';
            }
        }
    }
    bool isPalindrome(string s) {
        string temp="";
        //push all the characters in the temp string

        for(int i=0;i<s.length();i++){
            if(s[i]<='Z' && s[i]>='A' || s[i]<='z' && s[i]>='a' || s[i]<='9' && s[i]>='0'){
                temp.push_back(s[i]);
            }
        }
        //convert all the uppercases to lower cases
        compute(temp);

        //check for the palindrome
        int start=0;
        int end=temp.length()-1;
        while(start<=end){
            if(temp[start]!=temp[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
