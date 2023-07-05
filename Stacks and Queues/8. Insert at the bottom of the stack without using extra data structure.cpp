#include <bits/stdc++.h> 
void solve(stack<int> &myStack,int x){
    if(myStack.empty()){
        myStack.push(x);
        return ;
    }

    int ele=myStack.top();
    myStack.pop();
    solve(myStack,x);
    myStack.push(ele);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack,x);
    return myStack;
}
