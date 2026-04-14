class Solution {
public:
    int scoreOfString(string s) {
        int score=0;
        for(int i=0;i<s.length()-1;i++){
            int diff=abs(s[i]-s[i+1]);
            score+=diff;
        }
        return score;
    }
};