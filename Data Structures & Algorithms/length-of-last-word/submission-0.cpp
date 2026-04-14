class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int i=n-1;
        int length=0;
        while(i>=0 && s[i]==' ') i--;
        while(s[i]!=' ' && i>=0){
            i--;
            length++;
        }
        return length;
    }
};