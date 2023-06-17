// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
string rearrangeString(string str)
    {
        //store the count of repeating and non repeating characters
        int arr[26]={0};
        
        int unique=0;
        int rep=0;
        for(int i=0;i<str.length();i++){
            int index=str[i]-'a';
            if(arr[index]==0){
                arr[index]++;
                unique++;
            }
            else if(arr[index]==1){
                rep++;
            }
        }
        cout<<"no of unique "<<unique<<endl;
        cout<<"no of rep "<<rep<<endl;
        int spaces=unique+1;
        if(rep<=spaces){
            cout<<"ans is 1"<<endl;
            string ans="1";
            return ans;
        }
        else{
            cout<<"ans is 0"<<endl;
            string ans="0";
            return ans;
        }
    }
int main() {
    string str="geeksforgeeks";
    string ans=rearrangeString(str);
    cout<<ans<<endl;
    return 0;
}
