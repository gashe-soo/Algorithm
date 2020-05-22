#include <iostream>
#include <vector>
using namespace std;

//프로그래머스 level3 기지국 설치

int count(int range, int cover){
    if(range == 0)
        return 0;
    if(range%cover == 0)
        return range/cover;
    return range/cover + 1;
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int cover= 2*w+1;
    int range = 0; // 기지국 사이간 채워야 할 아파트 개수
    int idx =1;  // range 기준점
    
    
    // 기지국 설치 범위 확인 (기지국의 좌측만 확인)
    for(int i=0;i<stations.size();i++){
        // 기지국 범위 확인
        int low = stations[i] - w;
        int high = stations[i] + w;
        
        // 만약 좌측 범위가 1보다 크거나 같다면
        if(low>=1){
            range = low - idx;  // 개수는 좌측 범위 - 기준점
            idx = high + 1;     // 기준점 변경
        }else if(low<1 && high >n){ // 기지국이 전체 커버할 때
            return 0;           
        }else if(low<1 && high <=n){ //아파트의 개수가 좌측은 X 우측은 아파트 남은 경우
            range = 0;              // 아파트 개수 없음
            idx = high + 1;
        }
        // 만약 기준점이 좌측 범위보다 높은 경우는 생략
        if(range<=0)
            continue;
        
        // 아파트 개수를 커버 범위로 나눔.
        answer += count(range,cover);
    }
    
    // 나머지 확인하지 못한 우측 범위 확인
    if(idx <=n){
        answer += count(n+1-idx,cover);
    }
    

    return answer;
}