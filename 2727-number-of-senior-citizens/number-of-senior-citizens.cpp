class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;

        for(int i=0;i<details.size();i++){
            int a = details[i][11] - '0';
            int b = details[i][12] - '0';

            if((a*10 + b) > 60) count++;
        }
        return count;
    }
};