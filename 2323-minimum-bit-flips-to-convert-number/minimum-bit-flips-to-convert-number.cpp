class Solution {
private:
    int count(int n){
        int c = 0;
        while(n>0){
            c+= n & 1;
            n = n>>1;
        }
        return c;
    }
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal ;
        return count(n);
    }
};