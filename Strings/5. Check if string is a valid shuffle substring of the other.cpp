#include<bits/stdc++.h>
using namespace std;
bool comp(int arr1[],int arr2[]){
    for(int i=0;i<26;i++){
        if(arr1[i]!=arr2[i]){
            return false;
        }
    }
    return true;
}

bool check(string s1,string s2){
    //base case
    if(s1.length()>s2.length()){
        return false;
    }
    
    int arr[26]={0};
    for(int i=0;i<s1.length();i++){
        int index=s1[i]-'a';
        arr[index]++;
    }
    bool ans;
    int window_size=s1.length();
    int i=0;
    int arr1[26]={0};
    //traversing the first window
    while(i<window_size &&i<s2.length()){
        int index=s2[i]-'a';
        arr1[index]++;
        i++;
    }
    if(comp(arr,arr1)){
        return true;
    }
    while(i<s2.length()){
        char newChar=s2[i];
        int index=newChar-'a';
        arr1[index]++;
        
        char oldChar=s2[i-window_size];
        int index2=oldChar-'a';
        arr1[index2]--;
        i++;
        if(comp(arr,arr1)){
            return true;
        }
    }
    return false;
}

int main(){
    string s2="eidbaooo";
    string s1="ab";
    
    if(check(s1,s2)){
        cout<<"It is present"<<endl;
    }
    else{
        cout<<"It is not"<<endl;
    }
    return 0;
}
