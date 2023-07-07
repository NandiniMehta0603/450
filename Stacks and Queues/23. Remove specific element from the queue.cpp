// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout<<"Enter the no of numbers "<<endl;
    cin>> n;
    cout<<"enter the numbers now "<<endl;
    queue<int> q;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        q.push(k);
    }
    
    cout<<"Which index no you want to delete? "<<endl;
    int index;
    cin>>index;
    
    //delete the index element from the queue
    int count=1;
    if(index==1){
        q.pop();
    }
    else{
        while(count<index){
            int ele=q.front();
            q.pop();
            q.push(ele);
            count++;
        }
        q.pop();
        count++;
        while(count<=n){
            int ele=q.front();
            q.pop();
            q.push(ele);
            count++;
        }
    }
    // cout<<q.front();
    
    for(int i=0;i<q.size();i++){
        cout<<q.front()<<" ";
        int ele=q.front();
        q.pop();
        q.push(ele);
    }

    return 0;
}
