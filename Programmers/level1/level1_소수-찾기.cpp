#include <string>
#include <vector>

//프로그래머스 level1_소수-찾기

using namespace std;

int solution(int n) {
    int answer = 0;
    bool* board = new bool[n + 1];
    
    //에라토스테네스의 체
    for (int i = 2; i <= n; i++)
	    board[i] = true;
    for (int i = 2; i * i <= n; i++)
	{
		if (board[i])
			for (int j = i * i; j <= n; j += i)
			    board[j] = false;
	}
    
    for(int i = 2;i<=n;i++){
        if(board[i])
            answer++;
    }
    
    return answer;
}