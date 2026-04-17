class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();

        for(int i=0;i<n;i++){
            int maxR=-1;
            for(int j=i+1;j<n;j++){
                maxR=max(maxR,arr[j]);
            }
            arr[i]=maxR;
        }
        return arr;
    }
};