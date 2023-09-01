class Solution {
public:
    int myAtoi(string s) {
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='+' || s[i]=='-' || s[i]>='0' && s[i]<='9'){
                temp+=s[i];
            }
            else if(s[i]>='a' && s[i]<='z' && temp.size()==0|| s[i]>='A' && s[i]<='Z' && temp.size()==0){
                return 0;
            }
            else if(s[i]=='.' || s[i]>='a' && s[i]<='z' && temp.size()>0|| s[i]>='A' && s[i]<='Z' && temp.size()>0 || s[i]==' ' && temp.size()>0){
                break;
            }
        }
        bool neg=false;
        int index=0;
        if(temp[0]=='-'){
            neg=true;
            index++;
        }
        else if(temp[0]=='+'){
            neg=false;
            index++;
        }
        long sum=0;
        while(index<temp.length()){
            // if(sum<-1e9){
            //     sum=-1e9;
            // }
            if(temp[index]=='+' && sum==0|| temp[index]=='-' && sum==0){
                return 0;
            }
            if(temp[index]=='+' && sum>0|| temp[index]=='-' && sum>0){
                break;
            }
            // if(sum*10>INT_MAX){
            //     sum=INT_MAX;
            //     break;
            // }
            // else{
            //     sum=sum*10+(temp[index]-'0');
            //     index++;
            // }
            sum=sum*10+(temp[index]-'0');
            if(sum>=INT_MAX && neg==false){
                return INT_MAX;
            }
            else if(sum==INT_MAX && neg==true){
                return INT_MIN+1;
            }
            else if(sum>INT_MAX && neg==true){
                return INT_MIN;
            }
            index++;
        }
        if(neg==true){
            sum= -sum;
        }
        return sum;
    }
};
