	#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int N, int W, int val[], int wt[]) {
    int dp[N + 1][W + 1];

    // Initialize dp array
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = 0;
        }
    }

    // Build table dp[][] in bottom-up manner
    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[N][W];
}

int main() {
    int N, W;

    // Read number of items
    scanf("%d", &N);

    int val[N], wt[N];

    // Read values
    for (int i = 0; i < N; i++) {
        scanf("%d", &val[i]);
    }

    // Read weights
    for (int i = 0; i < N; i++) {
        scanf("%d", &wt[i]);
    }

    // Read capacity
    scanf("%d", &W);

    int max_value = knapsack(N, W, val, wt);

    printf("%d\n", max_value);

    return 0;
}
