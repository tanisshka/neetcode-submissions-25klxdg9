class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        int H[26] {0};
        for(int i=0;i<s.length();i++){
            H[s[i]-'a']++;
            H[t[i]-'a']--;
        }

        for(int i=0;i<26;i++){
            if(H[i]>0) return false;
        }
        return true;
    }

};
