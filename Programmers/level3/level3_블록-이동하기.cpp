// 프로그래머스 level3_블록-이동하기

/*
코테에서 만나면 포기하고 빨리 다른 걸 풀어야 하는 문제

접근 : bfs
중요한 건 다음 좌표로 움직일 수 있는지 확인해야 한다.
=> 두 개의 좌표를 무조건 좌상단에 있는 것을 첫 번째 좌표로 한다.
=> 첫 번째 좌표를 기준으로 오른쪽/아래를 방문했는지 확인

풀이 : 
1. bfs를 돈다.
2. bfs를 돌 때 상하좌우 + 시계,반시계 방향으로 회전해서 가능하면 큐에 push
2-1. 방문좌표를 수평,수직으로 나누어 체크.
2-2. 회전이 가능한 지 확인 + 가능하다면 회전한 좌표 배열 return.

*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
typedef pair<int, int> pi;
typedef pair<int, vector<int>> pp;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool v[101][101][2];


// 회전 가능한지 판별 - 수평 => return 수직 // 수직=> return 수평
vector<vector<int>> rotate(int dir, vector<int> a, vector<vector<int>> board){
    int fx = a[0], fy = a[1], sx = a[2], sy = a[3];
    int n = board.size();
    vector<vector<int>> ret;
    
    if(dir == 0){   // 수평
        if(fx-1 >=0 && board[fx-1][fy] == 0 && board[sx-1][sy] == 0){   // 상
            ret.push_back({fx-1,fy,fx,fy}); 
            ret.push_back({sx-1,sy,sx,sy});
        }
        if(fx+1<n && board[fx+1][fy] == 0 && board[sx+1][sy] == 0){     // 하
            ret.push_back({fx,fy,fx+1,fy});
            ret.push_back({sx,sy,sx+1,sy});
        }
    }else{  // 수직
        if(fy-1 >=0 && board[fx][fy-1] == 0 && board[sx][sy-1] == 0){   // 좌
            ret.push_back({fx,fy-1,fx,fy}); 
            ret.push_back({sx,sy-1,sx,sy});
        }
        if(fy+1<n && board[fx][fy+1] == 0 && board[sx][sy+1] == 0){     // 우
            ret.push_back({fx,fy,fx,fy+1});
            ret.push_back({sx,sy,sx,sy+1});
        }
    }
    return ret;
}

int solution(vector<vector<int>> board) {
    
    int n = board.size();
    queue<vector<int>> q;
    
    //bfs
    // 시작은 수평
    v[0][0][0] = true;
    
    // cost, 방향, 첫번째 좌표 x,y 두 번째 좌표 x,y
    q.push( {0,0,0,0,0,1} );

    
    while (!q.empty()) {
        int cost = q.front()[0];
        int dir = q.front()[1];
        int fx = q.front()[2], fy = q.front()[3];
        int sx = q.front()[4], sy = q.front()[5];
        q.pop();
        // 도착
        if ((fx == n - 1 && fy == n - 1) || (sx == n - 1 && sy == n - 1))
            return cost;

        // 상하좌우
        for (int i = 0; i < 4; i++) {
            int nfx = fx + dx[i], nfy = fy + dy[i];
            int nsx = sx + dx[i], nsy = sy + dy[i];
            
            if (nfx < 0 || nfx >= n || nfy < 0 || nfy >= n || nsx < 0 || nsx >= n || nsy < 0 || nsy >= n) continue;
            if (board[nfx][nfy] || board[nsx][nsy] || v[nfx][nfy][dir]) continue;
            
            q.push({ cost + 1,dir, nfx,nfy,nsx,nsy} );
            v[nfx][nfy][dir] = true;
        }
        // 회전 후 좌표 배열
        vector<vector<int>> ret = rotate(dir, {fx,fy,sx,sy}, board);
        // 회전하면 방향도 달라진다.
        dir = dir==1?0:1;
        for(int i=0;i<ret.size();i++){
            int nfx = ret[i][0], nfy = ret[i][1], nsx = ret[i][2], nsy = ret[i][3];  
            if(v[nfx][nfy][dir]) continue;
            q.push({cost+1, dir, nfx,nfy, nsx,nsy});
            v[nfx][nfy][dir] = true;
        }
    }
    
}