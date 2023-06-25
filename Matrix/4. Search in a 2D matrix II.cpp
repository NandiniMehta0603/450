class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int r=0;
        int c=col-1;

        while(r<row && c>=0){
            int ele=matrix[r][c];
            if(target==ele){
                return true;
            }
            else if(target>ele){
                r++;
            }
            else if(target<ele){
                c--;
            }
        }
        return false;
    }
};
