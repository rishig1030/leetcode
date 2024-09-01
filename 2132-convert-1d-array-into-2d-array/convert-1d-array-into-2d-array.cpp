class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size()!=(m*n)) return {};
        vector<vector<int>> TwoD(m,vector<int> (n));
        int i=0;
        while(i<m){
            for(int j=0;j<n;j++){
                TwoD[i][j] = original[n*i + j];
            }
            i++;
        }    

        return TwoD;
    }
};