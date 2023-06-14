class Solution {
public:
    int compress(vector<char>& chars) {
        int ansIndex=0;
        int i=0;
        int n=chars.size();
        while(i<n){
            int j=i+1;
            while(j<n && chars[i]==chars[j]){
                j++;
            }
            int count=j-i;
            chars[ansIndex]=chars[i];
            ansIndex++;
            if(count>1){
                string cnt=to_string(count);
                for(auto m:cnt){
                    chars[ansIndex]=m;
                    ansIndex++;
                }
            }
            i=j;
        }
        return ansIndex;
    }
};
