#include <string>
#include <vector>
#include <algorithm>

//프로그래머스 level3_숫자-게임

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    int a=0;
    for(int b=0;b<B.size();b++){
        if(A[a]<B[b]){
            a++;
            answer++;
        }
    }
    
    return answer;
}