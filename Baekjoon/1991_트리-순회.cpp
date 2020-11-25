// 백준 1991번 트리 순회

#include <iostream>
#include <string>
using namespace std;

int n;
char tree[26][2];

void preorder(char v)
{
    if (v == '.')
        return;
    cout << v;
    preorder(tree[v - 'A'][0]);
    preorder(tree[v - 'A'][1]);
}

void inorder(char v)
{
    if (v == '.')
        return;

    inorder(tree[v - 'A'][0]);
    cout << v;
    inorder(tree[v - 'A'][1]);
}

void postorder(char v)
{
    if (v == '.')
        return;

    postorder(tree[v - 'A'][0]);
    postorder(tree[v - 'A'][1]);
    cout << v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    char v, l, r;
    for (int i = 0; i < n; i++) {
        cin >> v >> l >> r;

        tree[v - 'A'][0] = l;
        tree[v - 'A'][1] = r;
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');

    return 0;
}