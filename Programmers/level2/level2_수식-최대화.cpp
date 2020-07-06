#include <string>
#include <vector>
#include <deque>

//프로그래머스 level2_수식-최대화

// 1. 가능한 연산자 우선순위 조합 만들기
// 2. 조합마다 우선순위 연산자부터 계산


using namespace std;

vector<string> arr;
string type="+-*";

// 1.
void go(int cnt, string val, vector<bool> v){
    if(cnt == 3){
        arr.push_back(val);
        return;
    }
    for(int i=0;i<3;i++){
        if(!v[i]){
            v[i] = true;
            go(cnt+1,val+type[i], v);
            v[i] = false;
        } 
    }
    return;
}

// 2. 계산
string cal(string a, string b, char op){
    long long x = stoll(a);
    long long y = stoll(b);
    if(op=='+') return to_string(x+y);
    if(op=='-') return to_string(x-y);
    if(op=='*') return to_string(x*y);
}

// 2. 연산자별로 계산
long long check(string str, deque<string> ex){
    deque<string> temp;
    for(char c : str){
        string op;
        op+=c;
        temp.clear();
        while(!ex.empty()){ 
            if(ex.front() !=op){    // 해당 연산자가 아니라면 
                temp.push_back(ex.front()); // 수식의 맨 앞 임시 배열에 넣어주고
                ex.pop_front(); // 팝
            }else{  // 해당 연산자라면
                ex.pop_front();     
                string ret =cal(temp.back(),ex.front(),c);  // 피연산자 두개로 계산
                temp.pop_back();    
                ex.pop_front();
                temp.push_back(ret);    // 계산 결과 넣어주기
            }
        }
        ex = temp;
    }
    
    return abs(stoll(ex.front()));
}



long long solution(string exp) {
    long long answer = 0;
    vector<bool> v(3,0);
    deque<string> ex;
    go(0,"",v);
    
    string temp;
    for(int i=0;i<exp.length();i++){
        if(exp[i] =='*' || exp[i]=='+'||exp[i]=='-'){
            ex.push_back(temp);
            temp.clear();
            temp += exp[i];
            ex.push_back(temp);
            temp.clear();
        }else{
            temp +=exp[i];
        }
    }
    ex.push_back(temp);
    
   
    for(string str: arr){
        
        long long ret = check(str,ex);
        answer = answer>ret? answer:ret;
    }
    
    return answer;
}