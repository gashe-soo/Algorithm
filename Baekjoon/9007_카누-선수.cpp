// 백준 9007번 카누 선수

// 1+2, 3+4 해서 이분탐색으로 찾기
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int tc, n, k, answer;

int arr[4][1001];

void compare(int v)
{
    if (abs(answer - k) >= abs(v - k)) {
        if (abs(answer - k) == abs(v - k)) {
            answer = min(answer, v);
        } else
            answer = v;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {

        cin >> k >> n;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        vector<int> num[2];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                num[0].push_back(arr[0][i] + arr[1][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                num[1].push_back(arr[2][i] + arr[3][j]);
            }
        }

        sort(num[1].begin(), num[1].end());
        num[1].erase(unique(num[1].begin(), num[1].end()), num[1].end());
        answer = num[0][0] + num[1][0];
        for (int i = 0; i < num[0].size(); i++) {
            int val = k - num[0][i];
            int idx = lower_bound(num[1].begin(), num[1].end(), val) - num[1].begin();

            if (val == num[1][idx]) {
                answer = k;
                break;
            }

            int ret1 = num[1][idx] + num[0][i];
            compare(ret1);
            if (idx > 0) {
                int ret2 = num[1][idx - 1] + num[0][i];
                compare(ret2);
            }
        }
        cout << answer << "\n";
    }
    return 0;
}