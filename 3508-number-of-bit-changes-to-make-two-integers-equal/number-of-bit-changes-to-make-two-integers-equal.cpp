class Solution {
public:
    int minChanges(int n, int k) {
        int x = n^k;
        int count = 0;
        while(x){
            if(x&1 == 1){
                if(n&1 == 1) count++;
                else return -1;
            } 
            x = x>>1;
            n = n>>1;
        }
        return count;
    }
};