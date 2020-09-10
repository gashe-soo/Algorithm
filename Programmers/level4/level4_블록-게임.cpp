//프로그래머스 level4_블록-게임

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> pi;
typedef pair<bool,vector<pi>> pp;

int n, answer;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool v[51][51];
pp can(vector<pi> arr){
    if(arr[2].first == arr[3].first){
        pp ret = {true,{}};
        if(arr[1].first == arr[2].first){
            int y = arr[0].second;
            int x = arr[0].first;
            if(y == arr[1].second){
                ret.second = {{x,y+1},{x,y+2}};
            }else if(y==arr[2].second){
                ret.second = {{x,y-1},{x,y+1}};
            }else{
                ret.second = {{x,y-2},{x,y-1}};
            }
        }else{
            int x =arr[3].first;
            int y = arr[3].second;
            if(y==arr[0].second){
                ret.second = {{x-2,y-1},{x-1,y-1}};
            }else{
                ret.second = {{x-2,y},{x-1,y}};
            }
        }
        return ret;
    }
    return {false,{}};
}

vector<pi> bfs(int x,int y, vector<vector<int>>& board){
    vector<pi> ret;
    int val = board[x][y];
    queue<pi> q;
    vector<vector<bool>> v(n,vector<bool>(n,0));
    
    q.push({x,y});
    v[x][y] = 1;
    
    while(!q.empty()){
        pi p = q.front();
        q.pop();
        ret.push_back(p);
        
        for(int i=0;i<4;i++){
            int nx =p.first+dx[i], ny = p.second+dy[i];
            if(nx<0 || ny<0 || nx>=n||ny>=n||v[nx][ny] || board[nx][ny]!=val) continue;
            q.push({nx,ny});
            v[nx][ny] = 1;
        }
    }
    sort(ret.begin(),ret.end());
    return ret;
}

bool check(vector<vector<int>>& board, int x, int y){
    for(int i=0;i<=x;i++){
        if(board[i][y]!=0)
            return false;
    }
    return true;
}

void go(vector<vector<int>>& board, int x, int y){
    vector<pi> arr = bfs(x,y,board);
    
    pp ans = can(arr);
    if(ans.first){
        pi a = ans.second[0];
        pi b = ans.second[1];
        if(check(board,a.first,a.second) && check(board,b.first,b.second)){
            answer++;
            for(pi p : arr){
                board[p.first][p.second] = 0;
            }
        }
    }
    
    return;
}

int solution(vector<vector<int>> board) {
    answer = 0;
    n = board.size();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]!=0){
                go(board,i,j);
            }
        }
    }
    
    return answer;
}