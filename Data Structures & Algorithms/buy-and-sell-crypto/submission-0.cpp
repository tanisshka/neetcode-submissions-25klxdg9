class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int totMax=INT_MIN;
        for(int i=0;i<n;i++){
            int buy=prices[i];
            int maxP=INT_MIN;
            for(int j=i;j<n;j++){
                if(prices[j]-buy>maxP){
                    maxP=prices[j]-buy;
                }
            }
            if(maxP>totMax){
                totMax=maxP;
            }

        }
        return totMax;
    }
    
};
