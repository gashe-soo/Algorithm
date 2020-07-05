#include <string>
#include <vector>
#include <cmath>

//프로그래머스 level1_키패드-누르기

using namespace std;

pair<int,int> left;
pair<int,int> right;

int dx[10] = {3,0,0,0,1,1,1,2,2,2};
int dy[10] = {1,0,1,2,0,1,2,0,1,2};

char check(int num, string hand){
    if(num%3 ==1){
        left = {dx[num],dy[num]};
        return 'L';
    }
    if(num !=0 && num%3 ==0){
        right = {dx[num],dy[num]};
        return 'R';
    }
    
    int l = abs(left.first - dx[num])+abs(left.second -dy[num]);
    int r = abs(right.first -dx[num]) +abs(right.second-dy[num]);
    if(l>r){
        right = {dx[num],dy[num]};
        return 'R';
    }
    if(l<r) {
        left = {dx[num],dy[num]};
        return 'L';
    }
    if(hand =="right"){
        right = {dx[num],dy[num]};
        return 'R';
    }
    if(hand == "left"){
        left = {dx[num],dy[num]};
        return 'L';
    }
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    left ={3,0}, right= {3,2};
    
    for(int num: numbers){
        answer += check(num,hand);
    }
    
    return answer;
}