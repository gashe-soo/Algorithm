#include <iostream>
#include <string>

 // 백준 2661번 좋은 수열

using namespace std;

// 수열 만들기
// 좋은 수열만 확인

int n;

// 좋은 수열인지 확인
bool isGood(string val) {
	// 1칸부터 n/2칸까지.
	for (int i = 1; i <= val.length() / 2; i++) {
		for (int j = 0; j < val.length()-i; j++) {
			bool flag = true;
			for (int k = j; k < j + i; k++) {
				if (k + i > val.length())
					break;
				if (val[k] != val[k + i]) // 같지 않다면 좋은 수열
					flag = false;
			}
			if (flag) // 나쁜 수열
				return false;
		}
	}
	return true;
}

void count(string val) {
	if (val.length() == n) {
		// 처음 도착하는 수가 제일 작은 수.
		cout << val;
		exit(0);
	}
	for (int i = 1; i <= 3; i++)
		if (isGood(val + to_string(i)))
			count(val + to_string(i));
	
	return;
}


int main() {
	cin >> n;
	count("");
	return 0;
}