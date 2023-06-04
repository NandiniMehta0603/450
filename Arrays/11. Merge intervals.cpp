class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //runtime error comes if we have not initialised the size of the result vector
        vector<vector<int>> result;

        if(intervals.empty()){
            return result;
        }

        sort(intervals.begin(),intervals.end());
        vector<int> first_interval=intervals[0];//first row
        
        for(int i=1;i<intervals.size();i++){
            if(first_interval[1]>=intervals[i][0]){
                first_interval[1]=max(first_interval[1],intervals[i][1]);
            }
            else{
                result.push_back(first_interval);
                first_interval=intervals[i];
            }
        }
        result.push_back(first_interval);
        return result;
    }
};
