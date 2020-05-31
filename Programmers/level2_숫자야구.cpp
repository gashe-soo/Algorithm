#include <string>
#include <vector>

using namespace std;

// 프로그래머스 level2 숫자야구

// 볼카운트
vector<int> basecount(string answer, string guess){
    vector<int> ret(2,0);
    for(int i=0;i<3;i++){
        if(answer[i] == guess[i])
            ret[0]++; // 스트라이크
        for(int j =0;j<3;j++){
            if(guess[i]==answer[j])
                ret[1]++; // 볼+스트라이크
        } 
    }
    ret[1] -= ret[0]; // 볼만 세기
    return ret;
}



int solution(vector<vector<int>> baseball) {
    int answer = 0;
    
    for(int i=123;i<=987;i++){
        string num = to_string(i);
        if(num[0] == num[1] || num[1] == num[2] || num[2] == num[0])
            continue; // 중복 제거
        if(num[0] == '0' || num[1] == '0' || num[2] == '0')
            continue; // 0 포함 제거
        bool flag =true;
        for(vector<int> result : baseball){
            string guess  = to_string(result[0]);
            vector<int> count = basecount(num,guess);
            
            if(count[0] != result[1] || count[1] !=result[2]) {
                flag =false; // 볼카운트 다르면 다음 숫자 확인
                break;
            }
        }
        if(flag)
            answer++; // baseball의 모든 경우 만족시 가능한 답++
        
        
    }
    
    
    return answer;
}