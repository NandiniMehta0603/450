class Solution {
public:
    bool check(int arr1[],int arr2[]){
        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int arr1[26]={0};
        for(int i=0;i<s1.length();i++){
            int index=s1[i]-'a';
            arr1[index]++;
        }

        //first window
        int arr2[26]={0};
        for(int i=0;i<s1.length() && i<s2.length();i++){
            int index=s2[i]-'a';
            arr2[index]++;
        }
        bool ans;
        if(check(arr1,arr2)){
            return true;
        }
        for(int i=s1.length();i<s2.length();i++){
            int index1=s2[i]-'a';
            arr2[index1]++;

            int index2=s2[i-s1.length()]-'a';
            arr2[index2]--;

            if(check(arr1,arr2)){
                return true;
            }
        }
        return false;
    }
};
