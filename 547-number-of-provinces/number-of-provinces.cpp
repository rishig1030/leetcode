class Solution {
public:
    void dfs(int visited[],vector<vector<int>> adj,int i){
        for(int j=0;j<adj[i].size();j++){
            if(i != j && adj[i][j]==1 && visited[j]!=1){
                visited[j] = 1;
                dfs(visited,adj,j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        int visited[n];
        for(int i=0;i<n;i++){
            visited[i] = 0;
        }
        
        for(int i=0;i<isConnected.size();i++){
            if(visited[i] != 1){
                visited[i] = 1;
                count++;
                dfs(visited,isConnected,i);
            }
        }
        return count;
    }
};