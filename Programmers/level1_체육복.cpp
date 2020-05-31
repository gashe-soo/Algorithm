#include <string>
#include <vector>
#include <string.h>
using namespace std;

// 프로그래머스 level 1 체육복

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 시간복잡도 O(n)
    int answer = 0;
    int student[31];
    memset(student,0,sizeof(student));
    // 값이 -1이면 체육복이 없음. 0이상이면 입기 가능
    for(int i : reserve) student[i] += 1;
    for(int i : lost) student[i] += -1;
    
    // 체육복 빌려주기
    for(int i = 1; i <= n; i++) {
        if(student[i] == -1) {
            if(student[i-1] == 1) 
                student[i-1] = student[i] = 0;
            else if(student[i+1] == 1) 
                student[i] = student[i+1] = 0;
        }
    }
    // 못 빌린 학생만 제외.
    for(int i  = 1; i <=n; i++)
        if(student[i] != -1) answer++;
    
    
//     // 시간복잡도 O(n^2)
//     int answer = n - lost.size();
//     vector<bool> check_lost(n+1,0);
//     vector<bool> check_reserve(n+1,0);
    
//     int len_lost = lost.size();
//     int len_reserve = reserve.size();
    
//     //lost/reserve에 모두 포함되어 있는 학생
//     for(int i= 0; i<len_lost;i++){
//         for(int j=0;j<len_reserve;j++){
//             if(lost[i] == reserve[j]){
//                 // 본인이 본인 여벌 사용 체크
//                 check_lost[lost[i]] = true;
//                 check_reserve[reserve[j]] = true;
//                 answer++;
//             }
//         }
//     }
//     // 남의 체육복 빌리기
//     for(int i= 0; i<len_lost;i++){
//         if(check_lost[lost[i]]) //이미 빌렸다면 패스
//             continue;
//         for(int j=0;j<len_reserve;j++){
//             //앞 번호 학생이 아직 안 빌려줬다면
//             if(lost[i]-1 == reserve[j] && !check_reserve[reserve[j]]){
//                 check_reserve[reserve[j]] = true;
//                 answer++;
//                 break;
//             }// 뒷 번호 학생이 아직 안 빌려줬다면
//             else if(lost[i]+1 == reserve[j] && !check_reserve[reserve[j]]){
//                 check_reserve[reserve[j]] = true;
//                 answer++;
//                 break;
//             }
//         }
//     }
    return answer;
}