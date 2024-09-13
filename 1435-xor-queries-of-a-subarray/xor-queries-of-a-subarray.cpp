class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> v;
        vector<int> prefixXOR;
        prefixXOR.push_back(0);
        for(int i=0;i<arr.size();i++){
            prefixXOR.push_back(arr[i]^prefixXOR[i]);
        }

        for(int i=0;i<queries.size();i++){
            v.push_back(prefixXOR[queries[i][0]]^prefixXOR[queries[i][1]+1]);
        }
        return v;
    }
};