// 백준 16236번 아기상어
/*
풀이: 
1. 물고기 위치 저장
2. 현재 위치에서 먹을 수 있는 물고기 찾기
2-1. 다익스트라로 현재 지점부터 거리 구하기
2-2. 거리가 무한이 아니면서, 물고기 값이 상어 크기보다 작은 경우만 확인하기
2-3. 2-2에서 구한 물고기들 중 거리가 가장 가까운 물고기 잡기
3. 현재 위치를 물고기 잡은 지점으로 바꾸기
4. 2-3번 반복.


처음에 이동할 때 제한이 있다는 것을 빼먹고 풀이해서 틀림
=> 다익스트라로 거리 확인하고 잡기 가능한 경우만 확인해서 solve.

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pi> pp;

int n, shark_size;
int map[20][20];

bool v[20][20];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<pp> fish;
pi pos;
const int INF = 987654321;

pp dji(pi from) {
	priority_queue<pp,vector<pp>,greater<pp>> pq;
	vector<vector<int>> dist(n, vector<int>(n, INF));

	dist[from.first][from.second] = 0;
	pq.push({ 0,from });

	while (!pq.empty()) {
		int d = pq.top().first;
		int x = pq.top().second.first, y = pq.top().second.second;
		pq.pop();

		if (dist[x][y] < d) continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny<0 || ny >= n || map[nx][ny]>shark_size)
				continue;
			if (dist[nx][ny] > d + 1) {
				dist[nx][ny] = d + 1;
				pq.push({ d + 1,{nx,ny} });
			}
		}
	}
	vector<pp> arr;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] < shark_size && map[i][j] != 0 && dist[i][j] !=INF) {
				arr.push_back({ dist[i][j],{i,j} });
			}
		}
	}
	if (arr.size() == 0)
		return { -1,{-1,-1} };

	sort(arr.begin(), arr.end());

	return arr[0];
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	shark_size = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				pos = { i,j };
			}
			else if (map[i][j] >= 1 && map[i][j] <= 6) {
				fish.push_back({ map[i][j],{i,j} });
			}
		}
	}
	
	sort(fish.begin(), fish.end());
	int time = 0;
	int cnt = 0;
	pp ret = dji(pos);
	map[pos.first][pos.second] = 0;

	while (ret.first != -1) {
		map[ret.second.first][ret.second.second] = 0;
		time += ret.first;
		cnt++;
		if (cnt == shark_size) {
			shark_size++;
			cnt = 0;
		}
		pos = ret.second;
		ret = dji(pos);
		
	}


	cout << time;

	return 0;
}