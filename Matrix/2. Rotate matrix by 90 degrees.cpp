class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i=0;
        while(i<matrix.size()){
            int j=0;
            while(i!=j && j<i && j<matrix[0].size()){
                swap(matrix[i][j],matrix[j][i]);
                j++;
            }
            i++;
        }

        
        for(int i=0;i<matrix.size();i++){
            int start=0;
            int end=matrix[0].size()-1;
            while(start<=end){
                swap(matrix[i][start],matrix[i][end]);
                start++;
                end--;
            }
        }
    }
};
