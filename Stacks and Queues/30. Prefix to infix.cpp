// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
// #include<bits/stdc++.h>
using namespace std;
string infix(string str){
    stack<string> st;
    int i=str.length()-1;
    for(;i>=0;i--){
        if(str[i]>='A' && str[i]<='Z' || str[i]<='z' && str[i]>='a' || str[i]<='9' && str[i]>='0'){
            st.push(string(1,str[i]));
        }
        else{
            string temp="";
            string first=st.top();
            st.pop();
            temp+="(";
            temp+=first;
            temp+=str[i];
            string second=st.top();
            st.pop();
            temp+=second;
            temp+=")";
            st.push(temp);
        }
    }
    return st.top();
}

int main() {
    string pre="*-A/BC-/AKL";
    string ans=infix(pre);
    cout<<"the string output is: "<<ans<<endl;

    return 0;
}
