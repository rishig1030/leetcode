class Solution {
    private:
    void bfs(vector<vector<char>> grid,vector<vector<int>> &visited,int i,int j){
        visited[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            for(int i1 =-1 ;i1<=1;i1++){
                for(int j1=-1;j1<=1;j1++){
                    if(abs(i1)!=abs(j1) && (i+i1)>=0 && (i+i1)<grid.size() && (j+j1)>=0 && (j+j1)<grid[0].size() && visited[i+i1][j+j1]!=1 && grid[i+i1][j+j1]=='1' ){
                        visited[i+i1][j+j1]=1;
                        q.push({i+i1,j+j1});
                    }
                }
            }
            q.pop();
            i = q.front().first ; 
            j= q.front().second;
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); int m = grid[0].size(); 
        vector<vector<int>> visited(n,vector<int> (m,0));
        
        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && visited[i][j] !=1){
                    count++;
                    bfs(grid,visited,i,j);
                }
            }
        }
        return count;
    }   
};