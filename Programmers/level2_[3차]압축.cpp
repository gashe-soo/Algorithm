#include <string>
#include <vector>
#include <map>

using namespace std;

//프로그래머스 level2_[3차]압축

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    
    // 사전 넣기
    for(int i=1;i<=26;i++){
        string key(1,'A'+i-1);
        m[key] = i;
    }
    
    // 글자가 있는지 확인하면서 사전 등록
    int idx = 27;
    int i=0;
    
    // msg 길이만큼 반복
    while(i<msg.length()){
        //가장 긴 문자열 w 찾기    
        string key(1,msg[i]);
        while(m.find(key) !=m.end()){ // 만약 가장 긴 문자열이 아니라면
            key +=msg[++i];     // 하나 추가해서 확인
        }
        // 가장 긴 문자열+c 등록
        m[key] = idx++;
        
        //가장 긴 문자열 w
        key = key.substr(0,key.length()-1);
        answer.push_back(m[key]); // 색인번호 확인
        
    }
    return answer;
}