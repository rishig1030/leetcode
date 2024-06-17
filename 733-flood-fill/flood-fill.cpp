class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> visited(image.size(),vector<int> (image[0].size(),0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc] = 1;
        int startingcolor = image[sr][sc];
        image[sr][sc] = color;
        while(!q.empty()){
            sr = q.front().first ; 
            sc = q.front().second ;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(abs(i) != abs(j) && (sr+i)>=0 && (sr+i)<image.size() && (sc+j)>=0 && (sc+j)<image[0].size() &&  visited[sr+i][sc+j] != 1 && image[sr+i][sc+j] == startingcolor){
                        visited[sr+i][sc+j] = 1;
                        image[sr+i][sc+j] = color;
                        q.push({sr+i,sc+j});
                    }
                }
            }
            q.pop();
        }
        return image;
    }
};