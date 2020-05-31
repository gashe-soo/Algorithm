#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 프로그래머스 level3 여행경로

bool visit[10001];
vector<string> answer;

// 도시 방문 
bool dfs(string depart, int cnt, vector<vector<string>> tickets, vector<string> ret){
    if(cnt == tickets.size()){ // 모든 도시 방문
        for(string str : ret)
            answer.push_back(str);
        return true;
    }
    for(int i = 0;i<tickets.size();i++){
        if(tickets[i][0] == depart && !visit[i]){
            visit[i] = true;
            ret.push_back(tickets[i][1]);
            if(dfs(tickets[i][1],cnt+1,tickets,ret)) // 도시 방문 재귀
                return true;
            ret.pop_back();
            visit[i] = false;
        }
    }
    return false;
}



vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(),tickets.end());
    
    string depart = "ICN";
    answer.push_back(depart);
    int cnt = 0;
    vector<string> ret;
    
    dfs(depart,cnt,tickets,ret);
    
    return answer;
}