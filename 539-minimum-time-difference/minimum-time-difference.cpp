    bool custComp(string a,string b){
        return a<b;
    }
class Solution {
private:

public:
    int findMinDifference(vector<string>& timePoints) {
        long long minTime = 24*60+60;

        sort(timePoints.begin(),timePoints.end(),custComp);
        int n = timePoints.size();
        for(int i=0;i<timePoints.size();i++){
            long long prev;
            if(i==0){
                prev = (timePoints[n-1][0]*10 + timePoints[n-1][1])*60 + timePoints[n-1][3]*10 + timePoints[n-1][4];    
            }

            else{
                prev = (timePoints[i-1][0]*10 + timePoints[i-1][1])*60 + timePoints[i-1][3]*10 + timePoints[i-1][4];
            }

            long long curr = (timePoints[i][0]*10 + timePoints[i][1])*60 + timePoints[i][3]*10 + timePoints[i][4];
            
            long long diff = abs(curr-prev);
            if((diff)>12*60){
                diff = abs(24*60-diff);
            }

            minTime = min(minTime,diff);
        }

        return minTime;
    }
};