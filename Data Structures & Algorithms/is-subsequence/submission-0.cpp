class Solution {
public:
    bool isSubsequence(string s, string t) {
        string checker="";
        int i=0;
        int j=0;
        while(i<t.length() && j<s.length()){
            if(s[j]==t[i]){
                checker+=t[i];
                j++;
            }
            i++;
        }
        return s==checker;
    }
};