class Solution {

public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> prob(n,0);
        prob[start_node] = 1.00000;
        
        for(int j=0;j<n-1;j++){
            bool isChange = false;
            for(int i=0;i<edges.size();i++){
                if(prob[edges[i][0]]*succProb[i] > prob[edges[i][1]]){
                    isChange = true;
                    prob[edges[i][1]] = prob[edges[i][0]]*succProb[i];
                }
                if(prob[edges[i][1]]*succProb[i] > prob[edges[i][0]]){
                    isChange = true;

                    prob[edges[i][0]] = prob[edges[i][1]]*succProb[i];
                }
            }
            if(isChange == false) break;
        }
        return prob[end_node];
    }
};