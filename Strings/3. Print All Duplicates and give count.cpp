//Approach 1:
//use a char array of 256 size and traverse the list in O(n) time and keep updating the frequency of each character
//O(n) time and O(no_char) space

//Approach 2:
//use a map to store the occurances of each character
//O(nlogn) time-->use of balanced tree and O(K) space, K-> no of unqiue characters

//Approach 3:
//use of unordered_map to store the occurance of each character
//O(n) time and O(K) space, K->no of unique characters

//Approach 4:
//Using sorting--> O(logn) time
//sort the characters
//take pointers and count variable to calculate the occurance of each character, if freq>1, count variable calculates
//O(1) space

//Approach 5:
//bit manipulation


//using approach 4:
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void printDuplicates(string str){
    int len=str.length();
    
    sort(str.begin(),str.end());
    for(int i=0;i<len;i++){
        int count=1;
        while(i<len-1 && str[i]==str[i+1]){
            count++;
            i++;
        }
        if(count>1){
            cout<<str[i]<<", count is: "<<count<<endl;
        }
    }
}

int main() {
    string str="test string";
    printDuplicates(str);
    return 0;
}
