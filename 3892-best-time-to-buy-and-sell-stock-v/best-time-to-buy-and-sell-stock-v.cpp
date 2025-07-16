typedef long long ll;
class Solution {
public:
    ll maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n < 2 || k == 0) return 0;

        vector<ll> dp_prev(n, 0), dp_cur(n, 0);

        for (int t = 1; t <= k; t++) {
            ll best_buy = -prices[0];   // Max profit if we buy on day i
            ll best_short = prices[0];      // Max profit if we short sell on day i
            dp_cur[0] = 0;

            for (int i = 1; i < n; i++) {
                ll a = dp_cur[i - 1];                // No action on day i
                ll b = best_buy + prices[i];         // Sell after buying
                ll c = best_short - prices[i];           // Buy back after shorting

                dp_cur[i] = max({a, b, c});

                best_buy = max(best_buy, dp_prev[i - 1] - prices[i]);
                best_short = max(best_short, dp_prev[i - 1] + prices[i]);
            }

            swap(dp_prev, dp_cur);
        }

        return dp_prev[n - 1];
    }
};