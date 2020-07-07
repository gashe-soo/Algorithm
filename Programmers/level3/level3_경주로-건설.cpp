#include <string>
#include <vector>
#include <queue>

//프로그래머스 level3_경주로-건설

using namespace std;

typedef pair<int, vector<int>> pi;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int dist[26][26][4];
const int INF = 987654321;

int solution(vector<vector<int>> board) {
    int answer = INF;
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    int n = board.size();
    
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            for(int k =0;k<4;k++) 
                dist[i][j][k] = INF;
    
    for(int i= 0;i<4;i++){
        dist[0][0][i] = 0;
        pq.push({0,{0,0,i}});
    }
    
    while(!pq.empty()){
        int c = pq.top().first;
        int x = pq.top().second[0], y = pq.top().second[1], d = pq.top().second[2];
        pq.pop();
        
        for(int i=0;i<4;i++){
            int nx = x+ dx[i], ny = y+dy[i];
            
            if(nx<0 || nx>=n || ny<0 || ny>=n || board[nx][ny]) continue;
            
            int cost = d ==i? 1 : 6;
            
            if(dist[nx][ny][i] >= c + cost){
                dist[nx][ny][i] = c+ cost;
                pq.push({c+cost,{nx,ny,i}});
            }
        }
    }
    
    for(int i=0;i<4;i++){
        answer = answer>dist[n-1][n-1][i]? dist[n-1][n-1][i] : answer;
    }
    answer *= 100;
    return answer;
}