#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;

// 모든 조합 포함 배열.
vector<int> ans;

// 소수 판별
bool isPrime(int n) {
    if (n == 0 || n == 1)return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n%i == 0)return false;
    }
    return true;
}

// now: 현재 문자열 ,numbers: 입력받은 문자열, end: 목표 길이, check:추가여부
void count(string now, string numbers, int end,vector<bool> check){
    int len = now.length();
    // 만약 현재 문자열이 목표 길이와 같다면 배열 추가.
    if(len==end){
        ans.push_back(stoi(now));
        return;
    }
    
    // 만약 추가안했다면 추가하고 다시 재귀 호출.
    for(int i=0;i<numbers.length();i++){
        if(!check[i]){
            check[i] = true;
            count(now+numbers[i],numbers,end,check);
            check[i] = false;
        }
    }
    return;
    
}


int solution(string numbers) {
    int answer = 0;
    
    vector<bool> check(numbers.length(),0);
    
    for(int i=1;i<=numbers.length();i++){
        count("",numbers,i,check);
    }
    // 모든 조합에서 중복 제거
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    
    // 소수 판별.
    for(int x : ans){
        if(isPrime(x))
            answer++;
    }
    return answer;
}