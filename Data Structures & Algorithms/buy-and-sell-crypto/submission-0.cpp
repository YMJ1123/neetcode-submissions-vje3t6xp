class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min = prices[0];
        for (int i=1; i<prices.size(); i++){
            if (prices[i]<min){
                min = prices[i];
                continue;
            }
            max_profit = max(max_profit, prices[i]-min);
        }
        return max(max_profit, 0);
    }
};
