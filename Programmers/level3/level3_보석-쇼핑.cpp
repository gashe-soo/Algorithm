// 프로그래머스 level3_보석-쇼핑

// 투 포인터 풀이

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string,int> m;
    unordered_set<string> s;
    
    // set에 넣어 보석의 종류의 총 개수 파악
    for(string gem: gems){
        s.insert(gem);
    }
    int size = s.size();
    
    
    int start = 0, end = 0, cnt = 0;
    int d = 100001;
    // end가 gems 크기 안에 들어와야 한다.
    while(end <gems.size()){
        m[gems[end]]++;     // 보석 새로 추가.
        
        if(m.size()==size){ // 현재 구간의 보석 종류가 종류의 총 개수와 같다면
            while(m[gems[start]]>1){    // 시작점을 최대한 당겨 짧게 만들기.
                m[gems[start]]--;
                start++;
            }
            if(d > end-start){
                d = end-start;      // 제일 짧은 구간이라면 저장.
                answer ={start+1,end+1};
            }
            m.erase(gems[start]);   // 시작점에 해당하는 보석 지우고 
            start++;                // 시작점 구간을 증가시킴.
        }
        end++;
    }
    
    return answer;
}