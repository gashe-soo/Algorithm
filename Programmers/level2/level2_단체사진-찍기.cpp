#include <string>
#include <vector>

// 프로그래머스 level2_단체사진-찍기

using namespace std;

// 0. 배열 순서는 최대 8! * n이 최대 100이므로 완전 탐색 가능
// 1. 가능한 배열 만들기
// 2. 조건을 확인하면서 되는 경우만 체크

string name;
vector<string> arr;
int answer;
vector<bool> v(8,0);

void check(string str){
    for(string condition : arr){
        char one = condition[0];
        char two = condition[2];
        char type = condition[3];
        int dist = condition[4]-'0';
        int d = str.find(two) - str.find(one);
        d = d>0? d: -d;
        d -=1;
        if(type =='=' && !(d == dist)) return;
        if(type =='>' && !(d > dist)) return;
        if(type =='<' && !(d <dist)) return;
        
    }
    answer++;
    return;
}

void make(int cnt, string val){
    if(cnt==8){
        check(val);
        return;
    }
    for(int i=0;i<8;i++){
        if(!v[i]){
            v[i] = true;
            make(cnt+1, val+name[i]);
            v[i] = false;
        }
    }
    return;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    answer = 0;
    arr = data;
    name = "ACFJMNRT";
    for(int i=0;i<8;i++) v[i] =false;
    make(0,"");
    return answer;
}