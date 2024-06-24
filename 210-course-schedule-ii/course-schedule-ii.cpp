class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(!indegree[i]) q.push(i);
        }
        vector<int> v;
        while(!q.empty()){
            v.push_back(q.front());
            for(int i=0;i<adj[q.front()].size();i++){
                indegree[adj[q.front()][i]]--;
                if(indegree[adj[q.front()][i]] == 0){
                    q.push(adj[q.front()][i]);
                }
            }
            q.pop();
        }
        vector<int> ans;
        if(v.size() == numCourses) return v;
        else return ans;
    }
};