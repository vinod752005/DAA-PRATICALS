#include <iostream>
using namespace std;

int main() {
    int n, M;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter maximum capacity: ";
    cin >> M;

    int profit[n], weight[n];

    cout << "Enter profits of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    int dp[n + 1][M + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= M; w++) {

            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }

            else if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }

            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "\nDP Table:\n";

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= M; w++) {
            cout << dp[i][w] << "\t";
        }
        cout << endl;
    }

    cout << "\nMaximum Profit = " << dp[n][M] << endl;

    return 0;
}