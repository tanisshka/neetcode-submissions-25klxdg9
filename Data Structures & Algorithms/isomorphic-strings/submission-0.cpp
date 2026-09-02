class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mpST;
        unordered_map<char, char> mpTT;

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            if ((mpST.count(c1) && mpST[c1] != c2) || (mpTT.count(c2) && mpTT[c2] != c1)) {
                return false;
            }

            mpST[c1]=c2;
            mpTT[c2]=c1;
        }
        return true;
    }
};