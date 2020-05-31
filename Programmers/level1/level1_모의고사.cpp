#include <string>
#include <vector>
#include <algorithm>

//프로그래머스 level1_모의고사

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> p ={{1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}};
    vector<int> val(3,0);
    
    //채점
    for(int i =0;i<answers.size();i++){
        for(int j=0;j<3;j++){
            int idx = i% p[j].size();
            if(p[j][idx] == answers[i])
                val[j]++;
        }
    }
    
    // 높은 점수 가려내기
    int max = *max_element(val.begin(),val.end());
    for(int i = 0; i<val.size();i++){
        if(val[i] ==  max)
            answer.push_back(i+1);
    }
    
    return answer;
}