
//O(n) time and | O(1) space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
         
        int profit = 0,lowestPrice = prices[0];
        for(auto currentPrice : prices){
            if(currentPrice < lowestPrice)
                { lowestPrice = currentPrice; } // need to buy lowest stock
            else { 
                int currentProfit = currentPrice - lowestPrice;
                profit = max(profit, currentProfit);
            }
        }
        return profit;
    }
};
