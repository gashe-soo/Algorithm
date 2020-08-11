// 백준 9202번 BOGGLE

/*
브루트포스 + 백트래킹으로 가능한 문자열 만들어서 확인
Boggle 보드마다 단어 사전의 포함 여부 확인
1. 단어 사전의 하나를 선택한다.
2. 해당 보드에서 모든 경우를 확인하여 단어가 들어있는지 확인한다.
2-1. 해당 보드에서 dfs로 단어를 형성하며 사전의 단어와 일치하는 지 확인
2-2. 일치하고 사전의 단어와 길이가 같다면 찾은 개수 확인, 제일 긴 단어인지 판별
2-3. 일치하고 길이가 같지 않다면 추가로 8방향 확인

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int w, b;
string str[300001];
string boggle[30][4];
bool v[4][4];

int sc, cnt;
string longString;
bool check[300001];

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
int score[9] = { 0,0,0,1,1,2,3,5,11 };


void go(string word, int now, int c, int x, int y, int idx) {
	if (check[idx]) return;
	if (boggle[c][x][y] != word[now])
		return;
	
	if (now == word.length() - 1) {
		check[idx] = 1;
		sc += score[word.length()];
		cnt++;
		if (longString.length() < word.length()) 
			longString = word;
		else if (longString.length() == word.length() && longString > word)
			longString = word;
		return;
	}
	if (now == 7) return;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || v[nx][ny]) continue;

		v[nx][ny] = true;
		go(word, now + 1, c, nx, ny,idx);
		v[nx][ny] = false;
	}
	return;

}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> w;
	for (int i = 0; i < w; i++)
		cin >> str[i];
	
	cin >> b;
	for (int i = 0; i < b; i++)
		for (int j = 0; j < 4; j++)
			cin >> boggle[i][j];
	
	for (int i = 0; i < b; i++) {
		memset(check, 0, sizeof(check));
		sc = 0, cnt = 0;
		longString.clear();
		for (int x = 0; x < w; x++) {
			memset(v, 0, sizeof(v));
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					v[j][k] = true;
					go(str[x], 0, i, j, k, x);
					v[j][k] = false;
				}
			}
		}
		
		cout << sc << " " << longString << " " << cnt << "\n";
	}
	return 0;
}