#include <string>
using namespace std;

//프로그래머스 level3 방문 길이

//각 점의 아래,오른쪽 길만 체크
bool v[11][11][2];

// 상하좌우
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int count(char c){
    switch(c){
        case 'U':return 0;
        case 'D':return 1;
        case 'L':return 2;
        case 'R':return 3;
    }
}

// 좌표평면 안의 좌표인지 확인
bool check(int x, int y){
    if(x>10 || x<0)
        return false;
    if(y>10 || y<0)
        return false;
    return true;
}

int solution(string dirs) {
    int answer = 0;
    
    // 좌상단을 원점으로 놔둠(0,0)
    int x = 5;
    int y = 5;
    
    
    for(char c : dirs){
        int idx = count(c);
        int nx = x + dx[idx];
        int ny = y + dy[idx];
        if(!check(nx,ny)){
            continue;
        }
        if(c=='U'){ // 업
            if(!v[ny][nx][0]){ // U일 경우 이동 점의 하단 길을 확인
                v[ny][nx][0] = true;
                answer++;
            }
        }else if(c=='D'){
            if(!v[y][x][0]){ // D일 경우 기존 점의 하단 길을 확인
                v[y][x][0] = true;
                answer++;
            }
        }else if(c=='L'){
            if(!v[ny][nx][1]){ // left일 경우 이동 점의 우측 길 확인
                v[ny][nx][1] = true;
                answer++;
            }
        }else{
            if(!v[y][x][1]){ // R일경우 기존 점의 우측 길 확인
                v[y][x][1] = true;
                answer++;
            }
        }
        x = nx;
        y = ny;
    }
    
    
    
    return answer;
}