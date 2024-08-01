class Solution {
public:
    bool isPowerOfTwo(int n) {
        int a = n;
        int count = 0;
        while(a>>1){
            if(a&1) return false;
            a = a>>1;
        }
        if(a) return true;
        return false;
    }
};