// 백준 1328번 고층 빌딩

// dp문제
// 1. 문제 접근은 거의 다 맞게 했지만 코드 작성에서 문제.

#include <iostream>
#include <cstring> 

using namespace std;

long long MOD = 1000000007;

int n, l, r;
long long dp[101][101][101];

long long go(int a, int left, int right){

    if ((left == 1 && right == a) || (left == a && right == 1))
        return 1;

    if (a == 0 || left == 0 || right == 0)
        return 0;

    long long& result = dp[a][left][right];
    if (result != -1)
        return result;

    result = 0;

    result = ((go(a - 1, left, right) * (a - 2)) + go(a - 1, left - 1, right) + go(a - 1, left, right - 1)) % MOD;
    return result;
}


int main(void){
    cin >> n >> l >> r;
    memset(dp, -1, sizeof(dp));

    cout << go(n, l, r) % MOD;

    return 0;

}