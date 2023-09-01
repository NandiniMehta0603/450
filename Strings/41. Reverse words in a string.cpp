class Solution {
public:
    void reve(string &temp,int start,int end){
        int temp_end=end-1;
        while(start<=temp_end){
            swap(temp[start],temp[temp_end]);
            start++;
            temp_end--;
        }
    }
    string reverseWords(string s) {
        string temp="";
        if(s[0]!=' '){
            temp+=s[0];
        }
        for(int i=1;i<s.length();i++){
            if(s[i]==' ' && s[i-1]!=' ' && s[i-1]!='@'){
                temp+="@";
            }
            else if(s[i]!=' '){
                temp+=s[i];
            }
            // else{
            //     temp+=s[i];
            // }
        }
        // if(s[s.length()-1]!=' '){
        //     temp+=s[s.length()-1];
        // }
        int start=0;
        int end=0;
        while(end<temp.length()){
            while(temp[end]!='@' && end!=temp.length()){
                end++;
            }
            reve(temp,start,end);
            start=end+1;
            end=start;
        }
        start=0;
        end=temp.length()-1;
        while(start<=end){
            swap(temp[start],temp[end]);
            start++;
            end--;
        }
        int index=0;
        while(temp[index]=='@'){
            index++;
        }
        s="";
        for(;index<temp.length();index++){
            if(temp[index]=='@'){
                s+=' ';
            }
            else{
                s+=temp[index];
            }
        }
        return s;
    }
};
