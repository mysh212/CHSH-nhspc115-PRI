#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node {
    long long sum;
    long long max_val;
};

vector<long long> a;
vector<Node> tree;

void build(int node, int l, int r) {
    if (l == r) {
        tree[node].sum = a[l];
        tree[node].max_val = a[l];
        return;
    }

    int mid = (l + r) / 2;

    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);

    tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
    tree[node].max_val = max(tree[node * 2].max_val,
                             tree[node * 2 + 1].max_val);
}

void update(int node, int l, int r, int ql, int qr) {
    if (r < ql || qr < l || tree[node].max_val <= 1)
        return;

    if (l == r) {
        tree[node].sum = sqrt(tree[node].sum);
        tree[node].max_val = tree[node].sum;
        return;
    }

    int mid = (l + r) / 2;

    if (ql <= mid)
        update(node * 2, l, mid, ql, qr);

    if (qr > mid)
        update(node * 2 + 1, mid + 1, r, ql, qr);

    tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
    tree[node].max_val = max(tree[node * 2].max_val,
                             tree[node * 2 + 1].max_val);
}

long long query(int node, int l, int r, int ql, int qr) {
    if (r < ql || qr < l)
        return 0;

    if (ql <= l && r <= qr)
        return tree[node].sum;

    int mid = (l + r) / 2;

    return query(node * 2, l, mid, ql, qr) +
           query(node * 2 + 1, mid + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    a.resize(N + 1);
    tree.resize(4 * N + 5);

    for (int i = 1; i <= N; ++i)
        cin >> a[i];

    build(1, 1, N);

    while (Q--) {
        string type;
        int L, R;

        cin >> type >> L >> R;

        if (type == "ask")
            cout << query(1, 1, N, L, R) << '\n';
        else
            update(1, 1, N, L, R);
    }

    return 0;
}