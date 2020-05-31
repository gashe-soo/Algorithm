#include <string>
#include <vector>
#include <map>
using namespace std;

// 프로그래머스 level2 위장

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> m;
    for(vector<string> c :clothes){
        string type = c[1];
        if(!m[type])
            m[type] =1;
        else
            m[type]++;
    }
    
    for(auto it = m.begin();it!=m.end();it++){
        answer *= ((it->second)+1);
    }
    answer -=1;
    
    return answer;
}