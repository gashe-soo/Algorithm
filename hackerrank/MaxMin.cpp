#include <bits/stdc++.h>

using namespace std;

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr)
{
    sort(arr.begin(), arr.end());

    int answer = INT_MAX;
    for (int i = 0; i <= arr.size() - k; i++) {
        int start = i, end = i + k - 1;
        int val = arr[end] - arr[start];

        answer = min(val, answer);
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
