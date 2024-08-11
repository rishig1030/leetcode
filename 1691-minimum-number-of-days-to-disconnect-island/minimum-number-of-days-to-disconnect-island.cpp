class Solution {
private:
    void dfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &visited,int n,int m){
        visited[i][j] = 1;
        int row[] = {-1,0,1,0};
        int col[] = {0,1,0,-1};

        for(int k=0;k<4;k++){
            if((i+row[k])>=0 && (i+row[k])<n && (j+col[k])>=0 && (j+col[k])<m && grid[i+row[k]][j+col[k]]==1 && visited[i+row[k]][j+col[k]]==0){
                dfs(i+row[k],j+col[k],grid,visited,n,m);
            }
        }
        
    }

    int countIslands(vector<vector<int>> &grid,vector<vector<int>> &visited){
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    dfs(i,j,grid,visited,grid.size(),grid[0].size());
                    count++;
                }
            }
        }
        return count;
    }

public:
    int minDays(vector<vector<int>>& grid) {
        
        // if island more than one return 0
        // if island equal to one remove all one and check 
        // else return 2;
    
        vector<vector<int>> visited(grid.size(),vector<int> (grid[0].size(),0));

        int count = countIslands(grid,visited);
        if(count == 0 || count>1) return 0;

        else{
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j]==1){
                        grid[i][j] = 0;
                        for(int p=0;p<grid.size();p++){
                            for(int q=0;q<grid[0].size();q++){
                                visited[p][q] = 0;
                            }
                        }
                        int c = countIslands(grid,visited);
                        if(c==0 || c>1){
                            return 1;
                        }
                        grid[i][j] = 1;
                    }
                }
            }
        }
        return 2;
    }
};