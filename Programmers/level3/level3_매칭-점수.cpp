#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cctype>

//프로그래머스 level3_매칭-점수

using namespace std;

// 0. 모든 문자열 소문자화
// 1. 각 페이지의 url를 확인 => content ="https://" ~ "/>" 찾아서 저장.
// 2. 페이지의 내용 확인 <body> ~ </body>
// 3. 외부링크 파악하기 a href 찾기
// 4. 점수 확인


int solution(string word, vector<string> pages) {
    int answer = 0;
    int size = pages.size();
    map<string,int> basic;
    map<string, vector<string>> link;
    map<string,double> match;
    vector<string> u;
    // 0.
    for(int i =0;i<size;i++){
        ::transform(pages[i].begin(),pages[i].end(),pages[i].begin(),::tolower);
    }
    ::transform(word.begin(),word.end(),word.begin(),::tolower);
    
    for(string page : pages){
        // 1.    
        string tag ="<meta property=\"og:url\"";
        if(page.find(tag)==string::npos) continue;
        int meta = page.find(tag);
        string url_start = "\"https://";
        string url_end = "\"/>";
        if(page.find(url_start,meta)==string::npos)
            continue;
        int start = page.find(url_start,meta)+url_start.length();
        int end = page.find(url_end,start);
        string url = page.substr(start, end-start);
        u.push_back(url);
        basic[url] = 0;
        
        // 2.
        string body_start = "<body>";
        string body_end ="</body>";
        int b_start = page.find(body_start)+ body_start.length();
        int b_end = page.find(body_end);
        string body = page.substr(b_start,b_end-b_start);
        string temp;
        for(int k = 0;k<body.length();k++){
            if(!isalpha(body[k])){
                if(temp == word)
                    basic[url]++;
                temp.clear();
            }else{
                temp +=body[k];
            }
        }
        // 3. 링크는 없을 때까지 확인
        string link_start = "<a href=\"https://";
        string link_end = "\">";
        int idx = b_start;
        while(page.find(link_start,idx)!=string::npos){
            int l_s = page.find(link_start,idx) + link_start.length();
            int l_e = page.find(link_end,l_s);
            string link_a = page.substr(l_s,l_e-l_s);
            link[url].push_back(link_a);
            idx = l_e;
        }
        
    }
    
    for(string url : u){
        match[url] = basic[url];
    }
    
    for(string url : u){
        double link_point = 0;
        if(link[url].size()!=0)
            link_point = (double)basic[url] / (double)link[url].size();
        for(string other : link[url]){
            if(match.find(other) != match.end())
                match[other] +=link_point;
        }
    }
    
    // 제일 높은 매칭 점수 찾기
    double val = 0;
    string web;
    for(auto it = match.begin();it!=match.end();it++){
        if(it->second > val){
            val = it->second;
            web = it->first;
        }else if(it->second == val){ // 값이 같다면 더 작은 index을 가진 url 저장
            int i,j;
            // index 값 확인
            for(int k = 0;k<u.size();k++){
                if(u[k] == web)
                    i= k;
                else if(u[k] == it->first)
                    j = k;
            }
            if(j<i)
                web = it->first;
        }
    }
    
    // 값 확인
    for(int i = 0;i<u.size();i++){
        if(web == u[i])
            return i;
    }
    return answer;
}