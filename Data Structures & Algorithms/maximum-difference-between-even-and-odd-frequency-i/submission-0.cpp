class Solution {
public:
    int maxDifference(string s) {
        vector<int> count(26,0);

        for(char c:s){
            count[c-'a']++;
        }

        int oddMax=0;
        int evenMin=s.length();

        for(int c:count){
            if(c & 1){
                oddMax=max(oddMax,c);
            }else if(c>0){
                evenMin=min(evenMin,c);
            }
        }

        return oddMax-evenMin;
    }
};