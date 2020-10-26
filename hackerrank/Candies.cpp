#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr)
{
    if (n == 1)
        return 1;
    long dp[100001];

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    if (arr[0] > arr[1]) {
        dp[0] = dp[1] + 1;
    }

    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            dp[i] = max(dp[i - 1], dp[i + 1]) + 1;
        } else if (arr[i] > arr[i - 1] && arr[i] <= arr[i + 1]) {
            dp[i] = dp[i - 1] + 1;
        } else if (arr[i] <= arr[i - 1] && arr[i] > arr[i + 1]) {
            dp[i] = dp[i + 1] + 1;
        }
    }
    if (arr[n - 1] > arr[n - 2]) {
        dp[n - 1] = dp[n - 2] + 1;
    }

    for (int i = n - 2; i >= 1; i--) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            dp[i] = max(dp[i - 1], dp[i + 1]) + 1;
        } else if (arr[i] > arr[i - 1] && arr[i] <= arr[i + 1]) {
            dp[i] = dp[i - 1] + 1;
        } else if (arr[i] <= arr[i - 1] && arr[i] > arr[i + 1]) {
            dp[i] = dp[i + 1] + 1;
        }
    }
    if (arr[0] > arr[1]) {
        dp[0] = dp[1] + 1;
    }
    long answer = 0;
    for (int i = 0; i < n; i++) {
        answer += dp[i];
        //cout<<dp[i]<<" ";
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
