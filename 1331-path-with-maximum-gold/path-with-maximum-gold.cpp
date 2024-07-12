class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int maxSum = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    int gold = dfs(i,j,grid,visited,n,m);
                    maxSum = max(maxSum,gold);
                }
            }
        }
        return maxSum;
    }

    int dfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &visited,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 0 || visited[i][j] == 1) return 0;
        else{
            visited[i][j] = 1;
            int left = dfs(i,j-1,grid,visited,n,m);
            int right = dfs(i,j+1,grid,visited,n,m);
            int up = dfs(i-1,j,grid,visited,n,m);
            int down = dfs(i+1,j,grid,visited,n,m);
            visited[i][j] = 0;
            return max(left,max(right,max(up,down))) + grid[i][j];
        }
    }
};