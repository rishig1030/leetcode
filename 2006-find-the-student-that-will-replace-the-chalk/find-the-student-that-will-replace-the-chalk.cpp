class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total_sum = chalk[0];
        for(int i=1;i<chalk.size();i++){
            total_sum +=chalk[i];
        }
        if(k%total_sum==0) return 0;

        int chalk_left = k%total_sum;
        for(int i=0;i<chalk.size();i++){
            chalk_left-=chalk[i];
            if(chalk_left<0) return i;
        }
        return 0;
    }
};