#include <iostream>
#include <stack>
#include <utility>

 // 백준 2504번 괄호의 값

using namespace std;

// 1. 괄호는 스택 사용에 기반 
// 2. 괄호 안에 괄호에 대한 계산 필요.
// 2-1. 기본적인 계산 = ()이면 2점 []이면 3점 계산. 괄호가 완성될 경우 2,3점 계산
// 2-2. 괄호 안 괄호일 경우 스택에 하나 이상 쌓여져있다. => 괄호 완성된 후 스택이 empty가 아니라면 완성된 점수 더하기(쌓여져있는 괄호의 점수가 1점이라면 완성된 점수를 할당)
// 3. pair를 이용해 스택 쌓기.
// 4. 만약 모든 과정 후 스택이 비어있지 않다면 괄호 불완전.

int main() {
	string p;
	cin >> p;

	// 1 + 3.
	stack<pair<char, int>> st;
	int answer = 0;
	for (int i = 0; i < p.length(); i++) {
		// 1.
		if (p[i] == '(' || p[i] == '[') {
			st.push({ p[i],1 });
		}
		else {
			// 1.
			if (st.empty()) {
				answer = 0;
				break;
			}
			char open = st.top().first;
			if (p[i] == ')' && open == '[') {
				answer = 0;
				break;
			}
			else if (p[i] == ']' && open == '(') {
				answer = 0;
				break;
			}
			// 2.
			else {
				int val = st.top().second;
				st.pop();
				// 2-1.
				if (p[i] == ')' && open == '(') {
					val *= 2;
				}
				else {
					val *= 3;
				}
				// 2-2. 괄호 안 괄호
				if (!st.empty()) {
					pair<char, int> pi = st.top();
					if (pi.second == 1)
						pi.second = val;
					else
						pi.second += val;
					st.pop();
					st.push(pi);
				}
				// 2-2. 괄호 안 괄호가 아니라면 
				else
					answer += val;
			}

		}
	}

	// 4.
	if (!st.empty())
		answer = 0;
	cout << answer << endl;
	
	return 0;
}