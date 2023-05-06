#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int n){
    int low=0;
    int high=n-1;
    while(low<high){
        if(arr[low]>0 && arr[high]<0){
            swap(arr[low],arr[high]);
            low++;
            high--;
        }
        else if(arr[low]<0 && arr[high]<0){
            low++;
        }
        else if(arr[low]>0 && arr[high]>0){
            high--;
        }
        else{
            low++;
            high--;
        }
    }
}
void printSolve(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main() {
    int arr[]={-12,11,-13,-5,6,-7,5,-3,-6};
    int n=sizeof(arr)/sizeof(arr[0]);
    solve(arr,n);
    printSolve(arr,n);
	return 0;
}
