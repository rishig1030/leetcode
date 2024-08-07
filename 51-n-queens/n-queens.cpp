
class Solution {
private:

    bool check(int row,int col,vector<string> &board,int n){
        for(int i=col;i>=0;i--){
            if(board[row][i] == 'Q') return false;
        }

        int col1 = col;
        int row1 = row;

        while(col1>=0 && row1>=0){
            if(board[row1][col1]=='Q') return false;
            col1--;
            row1--;
        }

        while(col>=0 && row<board.size()){
            if(board[row][col]=='Q') return false;
            col--;
            row++;
        }
        return true;
    }

    void solve(int col,vector<string> &board,int n,vector<vector<string>> &totalboard){
        if(col==n){
            totalboard.push_back(board);
            return ;
        }

        for(int i=0;i<n;i++){
            if(check(i,col,board,n)){
                board[i][col] = 'Q';
                solve(col+1,board,n,totalboard);
                board[i][col] = '.';
            }
        }

    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> totalboard;
        vector<string> board;
        string s(n,'.');

        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        // solve( col,board,n,total_board);
        solve(0,board,n,totalboard);
        return totalboard;
    }
};