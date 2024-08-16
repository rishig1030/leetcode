class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int dist = INT_MIN;
        int minimum = arrays[0][0];
        int maximum = arrays[0][arrays[0].size()-1];

        for(int i=1;i<arrays.size();i++){
            int a = abs(arrays[i][0]-maximum);
            int b = abs(arrays[i][arrays[i].size()-1]-minimum);
            dist = max(dist,max(a,b));
            maximum = max(maximum,arrays[i][arrays[i].size()-1]);
            minimum = min(minimum,arrays[i][0]);
        }
        return dist;
    }
};