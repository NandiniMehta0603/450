#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(string str1, string str2){
    queue<char> q;
    
    if(str1.size()!=str2.size()){
        return false;
    }
    
    //push the string str2 in the queue
    for(int i=0;i<str2.size();i++){
        q.push(str2[i]);
    }
    
    while(q.front()!=str1[0]){
        char temp=q.front();
        q.pop();
        q.push(temp);
    }
    //now start comparing
    int i=0;
    while(!q.empty() && i<str1.size()){
        if(q.front()==str1[i]){
            i++;
            q.pop();
        }
        else if(q.front()!=str1[i]){
            return false;
        }
    }
    return true;
}
int main() {
    string str1="ABCDE",str2="CDEBA";
    
    if(check(str1,str2)){
        cout<<"Strings are rotations of each other"<<endl;
    }
    else{
        cout<<"Strings are not rotations of each other"<<endl;
    }

    return 0;
}
