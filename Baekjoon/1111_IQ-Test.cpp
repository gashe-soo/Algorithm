// 백준 1111번 IQ-Test

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int n, a, b;
int arr[51];
unordered_map<int, int> m;

const int INF = 1e9;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n == 1) {
        cout << "A";
    } else if (n == 2) {
        if (arr[0] == arr[1]) {
            cout << arr[0];
        } else {
            cout << "A";
        }
    } else {

        if (arr[0] == arr[1]) {
            bool flag = true;

            for (int i = 0; i < n; i++) {
                if (arr[i] != arr[0]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << arr[0];
            } else {
                cout << "B";
            }
        } else {
            if ((arr[2] - arr[1]) % (arr[1] - arr[0]) != 0) {
                cout << "B";
                return 0;
            }

            int a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
            int b = arr[1] - arr[0] * a;

            for (int i = 0; i < n - 1; i++) {
                if (arr[i] * a + b != arr[i + 1]) {
                    cout << "B";
                    return 0;
                }
            }
            cout << arr[n - 1] * a + b;
        }
    }

    return 0;
}