//프로그래머스 level4_가사-검색

#include <string>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#define NUM 26

using namespace std;

int cnt;
const char wild = '?';

struct Node {
    unordered_map<int, int> m;
    bool end;
    Node* child[NUM];

    Node() : end(false) {
        memset(child, 0, sizeof(child));
    }

    ~Node() {
        for (int i = 0; i < NUM; i++) {
            if (child[i])
                delete child[i];
        }
        m.clear();
    }


    void insert(const char* key, int size) {
        if (*key == 0)
            end = true;
        else {
            int next = *key - 'a';
            if (!child[next])
                child[next] = new Node();
            child[next]->m[size]++;
            child[next]->insert(key + 1, size);
        }
    }

    void find(const char* key, int size) {

        if (*key == 0)
            cnt++;
        else if (*key == wild) {
            cnt +=m[size];
        }
        else {
            int next = *key - 'a';
            if (!child[next] || !child[next]->m[size])
                return;
            child[next]->find(key + 1, size);
        }
    }
};


vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Node* root = new Node();
    Node* rroot = new Node();
    unordered_map<int,int> len;
    
    for (string word : words) {
        int size = word.size();
        len[size]++;
        root->insert(&word[0], size);
        reverse(word.begin(),word.end());
        rroot->insert(&word[0],size);
        
    }

    for (string query : queries) {
        int size = query.size();
        cnt = 0;
        if (query[0] == '?' && query[size - 1] == '?')
            cnt = len[size];
        else if(query[0]!='?')
            root->find(&query[0],size);
        else{
            reverse(query.begin(),query.end());
            rroot->find(&query[0],size);
        }
        answer.push_back(cnt);
    }

    return answer;
}