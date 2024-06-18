class Solution {
    private:

    void dfs(int i,int j ,vector<vector<char>> board,vector<vector<int>> &visited){
        vector<int> rows = {-1,0,1,0};
        vector<int> column = {0,-1,0,1};
        if(visited[i][j]!=1 && board[i][j] == 'O'){
            visited[i][j] = 1;
            for(int k=0;k<4;k++){
                int ri = i + rows[k];
                int ci = j + column[k];
                if(ri>=0 && ri<board.size() && ci>=0 && ci<board[0].size()){
                    dfs(ri,ci,board,visited);
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n,vector<int> (m,0));
        for(int j=0;j<m;j++){
            // first row
            if(!visited[0][j] && board[0][j] == 'O'){
                
                dfs(0,j,board,visited);
            }
            // last row
            if(!visited[n-1][j] && board[n-1][j] == 'O'){
                
                dfs(n-1,j,board,visited);
            }
        }
        for(int i=0;i<n;i++){
            // first column
            if(!visited[i][0] && board[i][0] == 'O'){
                
                dfs(i,0,board,visited);
            }

            if(!visited[i][m-1] && board[i][m-1] == 'O'){
                
                dfs(i,m-1,board,visited);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]!=1 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                    visited[i][j] = 1;
                }
            }
        }
    }
};