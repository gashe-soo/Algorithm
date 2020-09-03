// 프로그래머스 level4_자동완성

// 트라이 이용

#include <string>
#include <vector>
#include <cstring>
#include <iostream>

#define ALPHA 26
using namespace std;

struct Trie {
    bool end;
    Trie* child[ALPHA];
    int cnt;
    Trie() : end(false), cnt(0) {
        memset(child, 0, sizeof(child));
    }

    ~Trie() {
        for (int i = 0; i < ALPHA; i++) {
            if (child[i])
                delete child[i];
        }
    }

    void insert(const char* key) {
        
        if (*key == 0)
            this->end = true;
        else {
            int next = *key - 'a';
            if (child[next] == NULL) {
                child[next] = new Trie();
            }
            child[next]->cnt++;
            child[next]->insert(key+1);
        }
    }

    int find(const char* key, int idx) {
        int next = *key - 'a';
        if (*key == 0) 
            return idx;
        
        if (child[next]->cnt == 1)
            return idx + 1;
        
        return child[next]->find(key+1, idx + 1);
    }
};

int solution(vector<string> words) {
    int answer = 0;
    Trie* root = new Trie();
    for (string word : words) {
        auto cword =word.c_str();
        root->insert(cword);
    }
    for (string word : words) {
        auto cword =word.c_str();
        answer += root->find(cword, 0);
    }
    delete root;
    return answer;
}