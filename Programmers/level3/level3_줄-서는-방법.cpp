#include <string>
#include <vector>
// 프로그래머스 level3 줄서는 방법
using namespace std;

/*기본 틀 
첫 숫자가 똑같은 (n-1)!개의 그룹이 n개가 있다.
배열에 1-n 저장.
k번째 첫 숫자는 k가 0일때를 제외하곤 배열의 (k-1)/(n-1)!번째 원소가 된다.
만약 k가 0이라면 사실상 n번째이므로 n-1번째 원소를 가져온다.
해당 인덱스의 값을 추가하고 배열에서 삭제한다.
반복
*/
vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> temp;
    long long fac =1;
    
    // 배열에 저장
    for(int i=1;i<=n;i++){
        temp.push_back(i);
        fac *= i;
    }
    
    while(n){
        fac /=n; // fac = (n-1)!
        int idx = !k ? n-1 : (k-1)/fac;  // 인덱스 추출
        answer.push_back(temp[idx]);
        temp.erase(temp.begin()+idx);
        k %= fac;
        n--;
    }
    return answer;
}