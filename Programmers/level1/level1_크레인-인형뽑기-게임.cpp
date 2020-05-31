#include <string>
#include <vector>
#include <stack>

//프로그래머스 level1_크레인-인형뽑기-게임

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    //스택이용
    for(int move : moves){
        move -=1;
        for(int i=0;i<board.size();i++){
            if(board[i][move]==0)  
                continue;
            else{ //인형 있으면
                if(st.empty() || st.top()!=board[i][move]){ // 같은 인형이 아니면 push
                    st.push(board[i][move]);
                }else{  // 같은 인형이면 사라짐
                    st.pop();
                    answer +=2;
                }
                board[i][move]=0;
                break;
            }
        }
    }   
    return answer;
}