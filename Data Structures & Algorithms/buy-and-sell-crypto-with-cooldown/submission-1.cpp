class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int hold = -1*prices[0];
        int sold = 0;
        int rest = 0; 

        for(int i=1;i<n;i++) {

            int prevSold = sold; 
            sold = hold + prices[i];

            hold = max(hold,rest-prices[i]);

            rest = max(rest,prevSold);
        }
        return max(rest,sold);
    }
};
