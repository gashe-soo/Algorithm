#include <string>
#include <vector>

//프로그래머스 level2 피보나치수

using namespace std;

int solution(int n) {
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    
    for(int i=2;i<=n;i++){
        int val = (v[i-1]+v[i-2])%1234567;
        v.push_back(val);
    }
    
    
    return v[n];
}