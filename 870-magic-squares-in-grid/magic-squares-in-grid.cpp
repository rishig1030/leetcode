class Solution {
private:
    bool distinct(int i,int j,vector<vector<int>> &grid){
        vector<int> v(9,0);
        for(int k=i;k<i+3;k++){
            for(int l=j;l<j+3;l++){
                int a = grid[k][l]-1;
                if(a<9 && a>=0)
                v[a] = 1;
                else return false;
            }
        }
        
        for(int k=0;k<9;k++){
            if(v[k]==0) return false;
        }
        return true;
    }

    bool check(int i,int j,vector<vector<int>> &grid){
        int row1sum = 0;
        int row2sum = 0;
        int row3sum = 0;
        int col1sum = 0;
        int col2sum = 0;
        int col3sum = 0;
        int diag1sum = 0;
        int diag2sum = 0;

        for(int k=j;k<j+3;k++){
            row1sum += grid[i][k];
            row2sum += grid[i+1][k];
            row3sum += grid[i+2][k];
        } 
        
        for(int k=i;k<i+3;k++){
            col1sum += grid[k][j];
            col2sum += grid[k][j+1];
            col3sum += grid[k][j+2];
        }

        int row = i; int col = j;
        int three = 3;
        while(three--){
            diag1sum += grid[row++][col++];
        }

        row = i;
        col = j+2;
        three = 3;
        while(three--){
            diag2sum += grid[row++][col--];
        }

        if(row1sum==row2sum && row2sum==row3sum && row3sum==col1sum && col1sum==col2sum && col2sum==col3sum && col3sum==diag1sum && diag1sum==diag2sum) return true;

        return false;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        if(grid.size()<3 || grid[0].size()<3) return 0;

        for(int i=0;i<=grid.size()-3;i++){
            for(int j=0;j<=grid[0].size()-3;j++){
                if(distinct(i,j,grid) && check(i,j,grid)){
                    count++;
                }
            }
        }

        return count;
    }
};