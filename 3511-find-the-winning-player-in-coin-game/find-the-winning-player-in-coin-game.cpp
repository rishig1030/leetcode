class Solution {
public:
    string losingPlayer(int x, int y) {
        int move = 0;
        while(true){
            if(x>0 && y>=4) {
                x-=1;
                y-=4;
                move++;
            }
            else break;
        }
        if(move%2 == 0) return "Bob";
        return "Alice";
    }
};