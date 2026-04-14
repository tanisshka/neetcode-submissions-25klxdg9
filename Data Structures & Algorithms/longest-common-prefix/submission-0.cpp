class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        string first=strs[0];
        for(int i=0;i<first.length();i++){
            char ch=first[i];
            bool match=true;
            for(int j=1;j<strs.size();j++){
                if(strs[j].size()<i || ch!=strs[j][i] ){
                    match=false;
                    break;
                }
            }
            if(match){
                ans.push_back(ch);
            }else{
                break;
            }
        }
        return ans;
    }
};