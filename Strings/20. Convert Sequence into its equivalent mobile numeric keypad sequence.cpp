// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string Seq(string input,string str[]){
    string output="";
    int n=input.length();
    
    for(int i=0;i<n;i++){
        if(input[i]==' '){
            output+="0";
        }
        else{
            int index=input[i]-'A';
            output+=str[index];
        }
    }
    return output;
}
int main() {
    string str[]={"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666","7","77","777","7777","8","88","888","9","99","999","9999"};
    string input="NANDINI";
    cout<<Seq(input,str);
    
    return 0;
}
