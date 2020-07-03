#include <string>
#include <vector>
#include <queue>

// 프로그래머스 level3_디스크-컨트롤러

// 1. 모든 요청을 (소요, 요청시간)으로 min heap에 넣는다.
// 2. 우선순위 큐를 돌면서 제일 적은 소요시간 가져와 처리
// 2-1. 작업을 수행하는 지 여부 확인. 이전 작업 종료 시점보다 요청시간이 작아야 한다.
// 2-2. 만약 이전 작업 종료 시점보다 요청 시간이 크다면 작은 요청 시간을 가져올 때까지 pop, pop한 작업은 나중에 다시 push
// 2-3. 만약 이전 작업 종료 시점보다 요청 시간이 큰 것이 없다면 첫 번째로 pop한 것을 가져와 시간을 새로 업데이트한다.
// 3. 시간 계산
// 4. pop한 작업을 다시 큐에 push

using namespace std;

typedef pair<int,int> pi;

int solution(vector<vector<int>> jobs) {
    int answer = 0, sum =0, time = 1001;
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    vector<pi> arr;
    
    for(vector<int> v : jobs){
        pq.push({v[1],v[0]});
        time = time>v[0]? v[0]:time;
    }
    
    while(!pq.empty()){
        int cnt =pq.size();
        pi p = pq.top();
        pq.pop();
        
        while(p.second > time){
            arr.push_back(p);
            if(pq.empty())
                break;
            p = pq.top();
            pq.pop();
        }
        
        if(arr.size()==cnt){
            p = arr[0];
            arr.erase(arr.begin());
            time = p.second;
        }
        
        time += p.first;
        sum += time -p.second;
        
        for(pi v : arr)
            pq.push(v);
        arr.clear();
    }
    answer = sum/jobs.size();
    return answer;
}