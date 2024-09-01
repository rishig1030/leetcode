class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int color = 0; // 0 for white 1 for black
        int color2 = 0;
        if(((coordinate1[0]-'0')%2 == 0 && (coordinate1[1]-'a'+1)%2 == 0) || ((coordinate1[0]-'0')%2 != 0 && (coordinate1[1]-'a'+1)%2 != 0)){
            color = 1;
        }
        if(((coordinate2[0]-'0')%2 == 0 && (coordinate2[1]-'a'+1)%2 == 0) || ((coordinate2[0]-'0')%2 != 0 && (coordinate2[1]-'a'+1)%2 != 0)){
            color2 = 1;
        }

        return color==color2;
    }
};