class Solution {
private:
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ros = {-1,0,1,0};
        vector<int> col = {0,-1,0,1};
        vector<vector<int>> visited(n,vector<int> (m,0));
        queue<pair<int,int>> q;

        for(int j=0;j<m;j++){
            // 1st rows;
            if(!visited[0][j] && grid[0][j] == 1){
                q.push({0,j});
                visited[0][j]=1;
            }

            // last row
            if(!visited[n-1][j] && grid[n-1][j] == 1){
                q.push({n-1,j});
                visited[n-1][j] =1 ;
            }
        }

        for(int i=0;i<n;i++){
            // 1st column
            if(!visited[i][0] && grid[i][0] == 1){
                visited[i][0] = 1;
                q.push({i,0});
            }

            // last column
            if(!visited[i][m-1] && grid[i][m-1]==1){
                visited[i][m-1] = 1;
                q.push({i,m-1});
            }
        }
        
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int ri = a+ros[i];
                int ci = b+col[i];
                if(ci>=0 && ci<m && ri>=0 && ri<n && grid[ri][ci]== 1 && visited[ri][ci] !=1){
                    visited[ri][ci] = 1;
                    q.push({ri,ci});
                }
            }
        }


        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && visited[i][j]!=1){
                    count++;
                }
            }
        }
        return   count;
    }
};