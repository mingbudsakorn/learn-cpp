#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Read the energy table W (2n x 2n grid)
    vector<vector<int>> W(2 * n + 1, vector<int>(2 * n + 1, 0));
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++) {
            cin >> W[i][j];
        }
    }

    // DP table to store the minimum energy needed to reach each cell
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

    // Starting point, no energy needed at (n, n)
    dp[n][n] = 0;

    // Process from bottom-right to top-left by decreasing sum r + c
    for (int sum = 2 * n; sum >= 2; sum--) {  // sum = r + c
        for (int r = 1; r <= n; r++) {
            int c = sum - r; // Calculate column based on sum and row
            if (c < 1 || c > n) continue;  // Skip invalid positions

            // Check all valid previous positions (r', c') where r' + c' < r + c
            for (int r_prime = 1; r_prime < r; r_prime++) {
                for (int c_prime = 1; c_prime < c; c_prime++) {
                    // Update dp[r][c] with the minimum energy found
                    dp[r][c] = min(dp[r][c], dp[r_prime][c_prime] + W[r + c][r_prime + c_prime]);
                }
            }
        }
    }

    // The answer is the minimum energy to reach (1, 1)
    cout << dp[1][1] << endl;

    return 0;
}
