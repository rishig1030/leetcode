class Solution {
private:
    bool check(long long  d,vector<int> & start, vector<int> & end){
        int init = start[0];
        for(int i=0;i<start.size()-1;i++){
            if((init+d)>end[i+1]){
                return false;
            }
            init = init+d;
            if(init<start[i+1]) init = start[i+1];
        }
        return true;
    }

public:
    int maxPossibleScore(vector<int>& start, int d) {


        int n = start.size();
      
        sort(start.begin(),start.end());

        vector<int> end;
        for(int i=0;i<n;i++){
            end.push_back(start[i]+d);
        }

        long long left = 0;
        long long right = end[n-1]-start[0];

        long long mid = (left+right)/2;
        long long ans = 0;
        while(left<=right){
            if(check(mid,start,end)){
                left = mid+1;
                ans = mid;
            }
            else right = mid-1;

            mid=(left+right)/2;
        }
        return ans;
    }
};