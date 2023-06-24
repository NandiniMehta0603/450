class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int startRow=0;
        int endRow=matrix.size()-1;
        int startCol=0;
        int endCol=matrix[0].size()-1;
        vector<int> ans;

        int total_count=matrix.size()*matrix[0].size();
        int count=0;

        while(count<total_count){
            //starting row
            for(int j=startCol;j<=endCol && count<total_count;j++){
                ans.push_back(matrix[startRow][j]);
                count++;
            }
            startRow++;

            for(int i=startRow;i<=endRow && count<total_count;i++){
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;

            for(int j=endCol;j>=startCol && count<total_count;j--){
                ans.push_back(matrix[endRow][j]);
                count++;
            }
            endRow--;

            for(int i=endRow;i>=startRow && count<total_count;i--){
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};
