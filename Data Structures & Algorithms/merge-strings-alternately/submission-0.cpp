class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int j=0;
        int n=word1.length();
        int m=word2.length();
        string ans="";
        while(i<n && j<m){
            ans.push_back(word1[i++]);
            ans.push_back(word2[j++]);
        }

        while(i<n){
            ans.push_back(word1[i++]);
        }

        while(j<m){
            ans.push_back(word2[j++]);
        }
        return ans;
    }
};