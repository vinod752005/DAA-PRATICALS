#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    int p[n + 1];

    cout << "Enter dimensions:\n";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    int dp[n + 1][n + 1];

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    for (int length = 2; length <= n; length++) {

        for (int i = 1; i <= n - length + 1; i++) {

            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {

                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    cout << "\nDP Table:\n";

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            if (j < i)
                cout << "-\t";
            else
                cout << dp[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nMinimum number of multiplications = "
         << dp[1][n] << endl;

    return 0;
}