class Solution {
private:
    void dfs(int i,vector<vector<int>> &adj,vector<int> &visited){
        visited[i]=1;
        for(int j=0;j<adj[i].size();j++){
            if(visited[adj[i][j]]==0){
                dfs(adj[i][j],adj,visited);
            }
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        vector<vector<int>> adj(stones.size());
        for(int i=0;i<stones.size();i++){
            for(int j=i;j<stones.size();j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<int> visited(stones.size(),0);
        for(int i=0;i<stones.size();i++){
            if(visited[i]==0){
                dfs(i,adj,visited);
                count++;
            }
        }
        return stones.size()-count;
    }
};