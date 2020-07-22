//프로그래머스 level2_가장-큰-정사각형-찾기

// dp문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int row,col;
int dp[1000][1000];

int solution(vector<vector<int>> board)
{
	row = board.size();
	col = board[0].size();
    int answer = board[0][0];
    
	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			if (board[i][j] != 1) continue;
            
			board[i][j] = min({ board[i - 1][j - 1], board[i - 1][j] ,board[i][j - 1] }) + 1;
			answer = answer>board[i][j]? answer:board[i][j];
			
		}
	}

	return answer*answer;
}