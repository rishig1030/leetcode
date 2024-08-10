class Solution {
private:
    void dfs(int i,int j,vector<vector<int>> &scaled,vector<vector<int>> &visited,int n){
        visited[i][j] = 1;
        int row[] = {-1,0,1,0};
        int col[] = {0,-1,0,1};

        for(int k=0;k<4;k++){
            if((row[k]+i)<n && (j+col[k])<n && (i+row[k])>=0 && (j+col[k])>=0 && visited[i+row[k]][j+col[k]]!=1 && scaled[i+row[k]][j+col[k]]==0){
                dfs(i+row[k],j+col[k],scaled,visited,n);
            }
        }
        
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        // in this question we need scale each 1x1 square to 3x3 matrix
        // and then perform dfs ,each dfs will count as one region
        int n = grid.size();
        vector<vector<int>> scaled(n*3,vector<int> (n*3,0));
        vector<vector<int>> visited(n*3,vector<int> (n*3,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '/' || grid[i][j] == '\\'){
                    int three = 3;
                    int a = i*3;
                    int b = j*3;
                    if(grid[i][j] == '/') a= a+2;
                    while(three--){
                        if(grid[i][j] == '\\'){
                            scaled[a++][b++] = 1;
                        }
                        else if(grid[i][j] == '/'){
                            scaled[a--][b++] = 1;
                        }
                    }
                }
            }
        }

        int count = 0;

        for(int i=0;i<n*3;i++){
            for(int j=0;j<n*3;j++){
                if(scaled[i][j] == 0 && visited[i][j]==0){
                    dfs(i,j,scaled,visited,n*3);
                    count++;
                }
            }
        }
        return count;
    }
};