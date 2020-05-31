#include <string>
#include <vector>
#include <string.h>
#include <utility>
#include <algorithm>
using namespace std;

//프로그래머스_ level2 [1차]프렌즈 4블록

/*문제를 크게 3개로 분할해서 풂
1. 2*2 형태로 사라지는 블록 체크
2. 2*2 형태로 사라지면서 겹치는 블록 제거
3. 지워진 후 블록이 내려오도록 만듦.
*/

char pan[30][30]; 
vector<pair<int,int>> block; 

// 블록이 사라지는지 확인
bool isBox(int x, int y,int m, int n){
    if(x+1>=m || y+1 >=n)
        return false;
    if(pan[x][y] == 0)
        return false;
    if(pan[x][y] != pan[x+1][y])
        return false;
    if(pan[x][y] != pan[x][y+1])
        return false;
    if(pan[x][y] != pan[x+1][y+1])
        return false;
    // 사라진다면 사라지는 블록의 좌표를 배열에 추가
    block.push_back(make_pair(x,y));
    block.push_back(make_pair(x+1,y));
    block.push_back(make_pair(x,y+1));
    block.push_back(make_pair(x+1,y+1));
    return true;
}

// 사라진 블록 자리 채워넣기
void cover(int m, int n){
    // 한 줄씩 반복
    for(int y=0;y<n;y++){
        for(int x=m-1;x>=0;x--){
            if(pan[x][y]!=0)
                continue;
            // 만약 블록이 제거되었다면
            int dx =x;
            while(dx>=0 && pan[dx][y] ==0){ //위에 남아있는 블록을 찾는다.
                dx--;
            }
            if(dx<0)
                break;
            else{// 찾았다면 스와프
                int temp;
                temp = pan[dx][y];
                pan[dx][y] = pan[x][y];
                pan[x][y] = temp;
            }
        }
    }
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    memset(pan,0,sizeof(pan));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            pan[i][j] = board[i][j];
        }
    }
    //사라지는 블록이 없을 때까지 반복.
    while(true){
        block.clear();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                isBox(i,j,m,n);
            }
        }
        // 블록 좌표의 중복 제거
        sort(block.begin(),block.end());
        block.erase(unique(block.begin(),block.end()),block.end()); 
        answer +=block.size(); 
        // 더 이상 사라질 블록이 없다면 break.
        if(block.size()==0)
            break;
        for(auto p: block){
            pan[p.first][p.second] = 0;
        }
        cover(m,n);
    }

    return answer;
}