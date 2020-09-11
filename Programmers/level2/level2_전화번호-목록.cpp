//프로그래머스 level2_전화번호-목록-byTrie
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Trie{
    bool fin;
    Trie* child[10];
    
    Trie() : fin(false){
        memset(child, 0, sizeof(child));
    }
    
    ~Trie(){
        for(int i=0;i<10;i++){
            if(child[i])
                delete child[i];
        }
    }
    
    bool insert(char* key){
        if(fin) return false;
        if(*key==0){
            fin = true;
            for(int i=0;i<10;i++){
                if(child[i])
                    return false;
            }
            return true;
        }
        else{
            int next = *key-'0';
            if(!child[next])
                child[next] = new Trie();
            return child[next]->insert(key+1);
        }
    }
    
};

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    Trie* root =new Trie();
    for(string s : phone_book){
        if(!root->insert(&s[0]))
            return false;
    }
    return answer;
}