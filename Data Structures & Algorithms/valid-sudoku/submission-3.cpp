class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& mat) {
        vector<vector<int>> row(10, vector<int>(10, 0));
        vector<vector<int>> col(10, vector<int>(10, 0));
        vector<vector<int>> grid(10, vector<int>(10, 0));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if( mat[i][j]=='.')
                continue;
                int val= mat[i][j]-'0';
                if(row[i][val]==1){ 
                    return false;
                }
                row[i][val]=1;
                if (col[j][val]==1){
                    return false;
                }
                col[j][val]=1;
                int idx=(i/3)*3+j/3;
                if(grid[idx][val]==1){
                    return false;
                }
                grid[idx][val]=1;
            }
            
        }
        return true;
        
    }
};
