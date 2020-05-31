#include <string>
#include <vector>

//프로그래머스 level1_최대공약수와-최소공배수

using namespace std;

int gcd(int a, int b){
    while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}
int lcm(int a, int b){
    return a*b/gcd(a,b);
}

vector<int> solution(int a, int b) {
    return {gcd(a,b),lcm(a,b)};
}