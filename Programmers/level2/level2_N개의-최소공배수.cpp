#include <string>
#include <vector>
#include <algorithm>

//프로그래머스 level2_N개의-최소공배수

using namespace std;

int lcm(int a,int b){
    int x = a*b;
    while(b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    return x/a;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    for(int i =1;i<arr.size();i++){
        answer = lcm(answer,arr[i]);
    }

    return answer;
}