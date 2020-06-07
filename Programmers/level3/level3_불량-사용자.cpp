#include <string>
#include <vector>
#include <set>
#include <algorithm>

//프로그래머스 level3_불량-사용자

using namespace std;

// 1. ban 아이디에 맞는 사용자 걸러내기
// 2. 걸러진 사용자 아이디를 모두 조합
// 3. 중복 제거.
// 4. ban id의 사이즈에 맞는거만 확인

int size;
vector<vector<string>> ex(8,vector<string>(8)); // 제재 아이디마다 해당하는 유저 아이디를 가지고 있는 배열.
set<set<string>> ss;

// 2.
void count(int cnt, vector<string> val){
    if(cnt == size){
        set<string> s;
        for(string a : val)
            s.insert(a);
        // 3 + 4.
        if(s.size()==size)
            ss.insert(s);
        return;    
    }
    for(int i=0;i<ex[cnt].size();i++){
        // 만약 이미 아이디가 들어가 있다면 패스
        if(ex[cnt][i]=="" || find(val.begin(),val.end(),ex[cnt][i])!=val.end())
            continue;
        // 재귀 호출
        val.push_back(ex[cnt][i]);
        count(cnt+1,val);
        val.pop_back();
    }
}

// 유저 아이디가 제재 아이디에 속해 있는 지 확인
bool contain(string a, string b){
    if(a.length()!=b.length())
        return false;
    for(int i=0;i<a.length();i++){
        if(b[i] =='*')
            continue;
        if(a[i] != b[i])
            return false;
    }
    return true;
}

int solution(vector<string> u, vector<string> b) {
    size = b.size();
    // 1.
    for(int k = 0;k<u.size();k++)
        for(int i=0;i<size;i++)
            if(contain(u[k],b[i]))
                ex[i].push_back(u[k]);
    
    // 2.
    count(0,{});

    return ss.size();
}