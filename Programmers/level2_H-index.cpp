#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//프로그래머스 level2 H-Index

int solution(vector<int> c) {
    int answer = 0;
    // 오름차순 정렬
    sort(c.begin(),c.end());
    int len = c.size();
    
    // 만약 i번째 값이 남은 개수보다 커지거나 같으면 최대 h-index
    for(int x : c){
        if(x>=len)
            return len;
        len--;
    }
    
    return answer;
}