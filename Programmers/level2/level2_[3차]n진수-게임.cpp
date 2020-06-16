#include <string>
#include <vector>

// 프로그래머스 level2_[3차]n진수-게임

using namespace std;

// 1. 구해야할 문자열 길이 : t*m
// 2. n진수를 구하여 문자열에 계속 추가. 만약 문자열 길이가 t*m보다 같거나 길어질 때까지 n진수 반복.
// 3. 2번에서 구한 문자열을 t*m에 맞게 자르기
// 4. 인덱스 p-1부터 문자열의 길이까지 m씩 증가하며 추가하기.

// 10이상이면 A~F 
char giveAlpha(int num){
    if(num>=10)
        return num-10+'A';
    return num+'0';
}

// n진수 구하기
string calNum(int n, int number){
    string ret= "";
    if(number==0)
        return "0";
    while(number>0){
        int remain = number % n;
        ret = giveAlpha(remain)+ret;
        number /= n;
    }
    return ret;
}

// t*m에 해당하는 문자열 구하는 함수.
string giveString(int n, int size){
    string ret ="";
    int idx =0;
    while(ret.length()<size){
        ret += calNum(n, idx);
        idx++;
    }
    ret = ret.substr(0,size);   // 문자열 t*m만큼 자르기.
    return ret;
}



string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp = giveString(n, t*m);
    for(int i =p-1;i<temp.length();i+=m){
        answer += temp[i];
    }
    return answer;
}