// 백준 5639번 이진-검색-트리

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int _v)
    {
        val = _v;
        left = NULL;
        right = NULL;
    }
};

Node* root;

Node* insert(Node* cur, Node* v)
{
    if (cur == nullptr) {
        cur = v;
        return cur;
    }

    if (cur->val > v->val) {
        cur->left = insert(cur->left, v);
    } else {
        cur->right = insert(cur->right, v);
    }
    return cur;
}

void post(Node* cur)
{
    if (cur == nullptr)
        return;
    post(cur->left);
    post(cur->right);
    cout << cur->val << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        if (n == EOF)
            break;
        root = insert(root, new Node(n));
    }

    post(root);
    return 0;
}
