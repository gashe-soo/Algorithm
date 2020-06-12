#include <string>
#include <vector>
#include <iostream>

// 프로그래머스 level3_자물쇠와-열쇠

using namespace std;

// 1. 키를 4방향 돌리기
// 2. 키를 lock과 겹치는 좌표에서 확인.

vector<vector<vector<int>>> key_list;
int board[70][70];
int key_size, lock_size;

// 1. 회전
void rotate(vector<vector<int>> key){
    for(int i=0;i<4;i++){
        vector<vector<int>> v(key_size,vector<int>(key_size,0));
        key_list.push_back(v);
    }
    key_list[0] = key;
    
    // 반시계방향으로 회전.
    for(int i=1;i<4;i++){
        for(int j = 0;j<key_size;j++){
            for(int k=0;k<key_size;k++){
                 key_list[i][k][key_size-1-j] = key_list[i-1][j][k];
            }
        }
    }
    return;
}

// 키를 자물쇠에 넣기.
void push(vector<vector<int>> key, int x, int y){
    int size = key.size();
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            board[i+x][j+y] += key[i][j];
        }
    }
    return;
}

// 자물쇠 초기화
void set(vector<vector<int>> lock){
    for(int i=0;i<lock_size;i++){
        for(int j = 0;j<lock_size;j++){
            board[i+key_size][j+key_size] = lock[i][j];
        }
    }
    return;
}

// 키가 맞는 지 확인
bool check(){
    for(int i=0;i<lock_size;i++){
        for(int j=0;j<lock_size;j++){
            if(board[i+key_size][j+key_size] != 1)
                return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    key_size = key.size(), lock_size = lock.size();
    
    rotate(key);
    set(lock);
    if(check())
        return true;
    
    for(int i=0;i<4;i++){
        for(int x=0;x<key_size+lock_size;x++){
            for(int y=0;y<key_size+lock_size;y++){
                set(lock);
                push(key_list[i],x,y);
                if(check())
                    return true;
            }
        }
        
    }
    
    return false;
}