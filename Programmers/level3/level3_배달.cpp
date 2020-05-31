#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// 프로그래머스 level3 배달

using namespace std;

//road & dist
int v[51][51];
int dist[51];

// 다익스트라 이용
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    priority_queue<pair<int,int>> pq;  //우선순위 큐 이용
    
    // 여러 길의 시간 중 가장 작은 값만 저장.
    for(int i =0;i<road.size();i++){
        int x = road[i][0], y = road[i][1], t = road[i][2];
        if(v[x][y])
            v[x][y] = v[y][x] =  min(v[x][y],t);
        else
            v[x][y] = v[y][x] = t;
    }
    
    for(int i =1;i<=N;i++){
        dist[i] = 987654321;
    }
    pq.push({0,1});
    dist[1] = 0;
    
    while(!pq.empty()){
        int time = pq.top().first,  now = pq.top().second;
        
        pq.pop();
        for(int i=1;i<=N;i++){
            if(v[now][i]){ // 길이 있다면
                if(dist[i]>dist[now]+v[now][i]){ // 기존 길보다 짧다면 추가
                    dist[i] = dist[now] +v[now][i];
                    pq.push({dist[i],i});
                }
                
            }
        }
    
    }
    for(int i=1;i<=N;i++){
        if(dist[i]<=K)
            answer++;
    }
    

    return answer;
}