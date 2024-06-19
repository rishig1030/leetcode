class Solution {
private:
    bool check(int start,vector<vector<int>> graph,vector<int> &isColor){
        
        queue<int> q;
        q.push(start);
        
        isColor[start] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0;i<graph[node].size();i++){
                if(isColor[graph[node][i]] == -1){
                    isColor[graph[node][i]] = !isColor[node];
                    q.push(graph[node][i]);
                }
                else if(isColor[graph[node][i]] == isColor[node]) return false;
            }
            
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> isColor(n,-1);
        for(int i=0;i<n;i++){
            if(isColor[i] == -1){
                if(!check(i,graph,isColor)) return false;
            }
        }
        return true;
    }
};