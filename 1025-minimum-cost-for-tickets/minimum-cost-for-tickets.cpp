class Solution {
public:
    int index (vector<int>& days, int num) {
        int ind = lower_bound(days.begin(), days.end(), num) - days.begin();
        return ind;
    }
    int solveit(int i, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if (i >= days.size()) {
            return 0;
        }
        if (dp[i] != -1) return dp[i];
        int day1 = costs[0] + solveit(i + 1, days, costs, dp);
        int day7 = costs[1] + solveit(index(days, days[i] + 7), days, costs, dp);
        int day30 = costs[2] + solveit(index(days, days[i] + 30), days, costs, dp);
        return dp[i] = min(day1, min(day7, day30));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp (365 + 1, -1);
        return solveit(0, days, costs, dp);
    }
};