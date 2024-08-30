class Solution {
private:

long long DijkstraAlgo(vector<vector<int>> &edges,int n,int source,int destination){
    unordered_map<long long,vector<pair<long long,long long>>> adj;
    for(vector<int> &edge:edges){
        if(edge[2]!=-1){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
    }
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
    vector<long long> result(n,INT_MAX);
    vector<bool> visited(n,false);
    result[source] = 0;
    pq.push({0,source});
    while(!pq.empty()){
        long long cn = pq.top().second;
        long long cd = pq.top().first;
        pq.pop();
        if(visited[cn] == false){
            visited[cn] = true;
            for(auto&[nb,wt]:adj[cn]){
                if(result[nb] > cd+wt){
                    result[nb] = cd+wt;
                    pq.push({result[nb],nb});
                }
            }
        }

    }
    return result[destination];
}

public:
    const int Large_val = 2e9;
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        long long currShortestDist = DijkstraAlgo(edges,n,source,destination);
        if(currShortestDist==target){
            for(int i=0;i<edges.size();i++){
                if(edges[i][2] == -1) 
                edges[i][2] = Large_val;
            }
            return edges;
        }    
        else if(currShortestDist<target) return {};
        else{
            for(vector<int> &edge:edges){
                if(edge[2] == -1){
                    edge[2] = (currShortestDist == target)?Large_val:1;
                    if(currShortestDist != target){
                        long long newShortest = DijkstraAlgo(edges,n,source,destination);
                        if(newShortest <= target){
                            edge[2]+=(target-newShortest);
                            currShortestDist = target;
                        }
                    }
                }
            }
            if(currShortestDist!=target) return {};
            else return edges;
        }

    }
};