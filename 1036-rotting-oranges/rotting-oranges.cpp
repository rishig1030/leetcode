class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int> (m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
            }
        }
        int count = 0;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            for(int e=-1;e<=1;e++){
                for(int f=-1;f<=1;f++){
                    if(abs(e)!=abs(f) && (i+e)>=0 && (i+e)<n && (j+f)>=0 && (j+f)<m && visited[i+e][j+f] != 1 && grid[i+e][j+f] == 1){
                        visited[i+e][j+f] = 1;
                        grid[i+e][j+f] = 2;
                        q.push({{i+e,j+f},q.front().second + 1});
                        if((q.front().second + 1 ) > count) count = q.front().second + 1 ;
                    }
                }
            }
            q.pop();
        }
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1) return -1;
        }
    }
    return count;
    }
    
};