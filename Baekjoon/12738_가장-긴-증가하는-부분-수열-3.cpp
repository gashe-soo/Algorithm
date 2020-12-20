// 백준 12738번 가장-긴-증가하는-부분-수열-3

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, arr[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> ret;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (ret.empty()) {
            ret.push_back(arr[i]);
        } else if (ret.back() < arr[i]) {
            ret.push_back(arr[i]);
        } else {
            int idx = lower_bound(ret.begin(), ret.end(), arr[i]) - ret.begin();
            ret[idx] = arr[i];
        }
    }

    cout << ret.size();
    return 0;
}