class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0;
        int j=0;

        while(j<s.length() && i<t.length()){
            if(t[i]==s[j]){
                i++;
            }
            j++;
        }

        return t.length()-i;
    }
};