class Solution {
private:
    bool dfs(int i,int j,vector<vector<int>>& grid1,vector<vector<int>>& grid2,int n,int m,vector<vector<int>> &visited){
        visited[i][j] = 1;
        
        int row[] = {0,-1,0,1};
        int col[] = {1,0,-1,0};

        bool flag = true;
        for(int k=0;k<4;k++){
            if((i+row[k]>=0) && (i+row[k]<n) && (j+col[k]>=0) && (j+col[k]<m) && grid2[i+row[k]][j+col[k]]==1 && visited[i+row[k]][j+col[k]]==0) {
                if((grid1[i+row[k]][j+col[k]])!=(grid2[i+row[k]][j+col[k]])) flag = false;
                else flag = dfs(i+row[k],j+col[k],grid1,grid2,n,m,visited) && flag;
            }
        } 
        return flag;

    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int count = 0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && grid1[i][j]==grid2[i][j] && visited[i][j]==0){
                    if(dfs(i,j,grid1,grid2,n,m,visited))
                        count++;
                }
            }
        }
        return count;
    }
};