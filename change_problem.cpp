#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    int coin[n];

    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    cout << "Enter amount: ";
    cin >> amount;

    int dp[amount + 1];

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
    }

    for (int i = 1; i <= amount; i++) {

        for (int j = 0; j < n; j++) {

            if (coin[j] <= i && dp[i - coin[j]] != INT_MAX) {
                dp[i] = min(dp[i],
                            1 + dp[i - coin[j]]);
            }
        }
    }

    if (dp[amount] == INT_MAX) {
        cout << "\nChange cannot be made." << endl;
    }
    else {
        cout << "\nMinimum number of coins = "
             << dp[amount] << endl;
    }

    return 0;
}