class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start=0;
        int end=0;
        int n=fruits.size();
        unordered_map<int,int> mp;
        int ans=INT_MIN;
        int sum=0;
        while(end<n){
            mp[fruits[end]]++;
            sum+=1;
            if(mp.size()>2){
                // cout<<"This: "<<endl;
                while(mp[fruits[start]]>0){
                    mp[fruits[start]]--;
                    sum-=1;
                    if(mp[fruits[start]]==0){
                        mp.erase(fruits[start]);
                        start++;
                        break;
                    }
                    else{
                        start++;
                    }
                }
            }
            // cout<<"Now this: "<<sum<<endl;
            ans=max(ans,sum);
            end++;
        }
        if(ans==INT_MIN){
            ans=0;
        }
        return ans;
    }
};
