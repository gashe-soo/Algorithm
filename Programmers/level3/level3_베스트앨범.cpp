#include <string>
#include <vector>
#include <map>
#include <algorithm>
//프로그래머스 level3 베스트앨범

using namespace std;

/*
1. 장르별 총 재생횟수 정렬 => 해시로 총 재생횟수 확인. 벡터로 대입해서 정렬
2. 장르내 재생횟수 정렬 => 장르별 해시 value에 벡터(재생횟수,번호) 정리. 해시 값 정렬
3. 1번의 장르에서 2번찾아가기.
*/

bool cmp_sum(pair<int,string> a, pair<int,string> b){
    return a.first>b.first;
}
bool cmp_gen(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first)
        return a.second < b.second;
    
    return a.first>b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int size = genres.size();
    //1.
    map<string,int> sum;
    vector<pair<int,string>> v;
    //2.
    map<string,vector<pair<int,int>>> g;
    
    //1.
    for(int i=0;i<size;i++){
        string genre = genres[i];
        if(sum[genre]){
            sum[genre] +=plays[i];
        }else{
            sum[genre] = plays[i];
        }
    }
    for(auto it = sum.begin();it!=sum.end();it++){
        v.push_back({it->second,it->first});
    }
    sort(v.begin(),v.end(),cmp_sum);
    
    //2.
    for(int i=0;i<size;i++){
        string genre = genres[i];
        g[genre].push_back({plays[i],i});
    }
    for(auto it = g.begin();it!=g.end();it++){
        string genre = it->first;
        sort(g[genre].begin(),g[genre].end(),cmp_gen);
    }
    
    //3.
    for(int i=0;i<v.size();i++){
        string genre = v[i].second;
        int num = g[genre].size()>1?2:1;
        for(int i=0;i<num;i++){
            answer.push_back(g[genre][i].second);
        }
    }
    
    
    return answer;
}