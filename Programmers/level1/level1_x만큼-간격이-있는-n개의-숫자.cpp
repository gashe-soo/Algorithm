#include <string>
#include <vector>

//프로그래머스 level1_x만큼-간격이-있는-n개의-숫자

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    long long p =x;
    while(n--){
        answer.push_back(p);
        p += x;
    }
    return answer;
}