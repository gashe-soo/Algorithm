// ¾Ë°í½ºÆÌ quadtree

#include <iostream>
#include <string>

using namespace std;

string reverse(string::iterator& it) {
	char head = *it;
	++it;
	
	if (head == 'b' || head == 'w')
		return string(1, head);
	
	string upperleft = reverse(it);
	string upperright = reverse(it);
	string lowerleft = reverse(it);
	string lowerright = reverse(it);
	
	return "x" + lowerleft + lowerright + upperleft + upperright;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		string str;
		cin >> str;
		string::iterator it = str.begin();
		cout << reverse(it) << "\n";
	}

	return 0;
}