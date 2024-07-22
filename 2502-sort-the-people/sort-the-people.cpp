class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> mpp;
        int n = heights.size();

        for(int i=0;i<n;i++){
            mpp[heights[i]] = names[i];
        }

        sort(heights.begin(),heights.end());

        for(int i=0;i<n;i++){
            names[n-i-1] = mpp[heights[i]];
        }

        return names;
    }
};