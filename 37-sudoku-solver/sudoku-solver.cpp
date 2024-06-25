class Solution {

private:
    bool isValid(char c,int row,int col,vector<vector<char>> &v){
        for(int i=0;i<v.size();i++){
            if(v[i][col] == c) return false;
            if(v[row][i] == c) return false;
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(v[row-row%3 + i][col-col%3 + j] ==c) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j] == '.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(c,i,j,board)){
                            board[i][j] = c;
                            if(solve(board)){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};