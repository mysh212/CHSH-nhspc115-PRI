#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Skill {
    int d, c;
    ll nxt;
};

struct Node {
    ll t;
    int id;

    bool operator<(const Node& other) const {
        return t > other.t;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll h1, h2;
    cin >> h1 >> h2;

    int n;
    cin >> n;

    vector<Skill> A(n);

    for (int i = 0; i < n; ++i) {
        cin >> A[i].d >> A[i].c;
        A[i].nxt = 1;
    }

    int m;
    cin >> m;

    vector<Skill> B(m);

    for (int i = 0; i < m; ++i) {
        cin >> B[i].d >> B[i].c;
        B[i].nxt = B[i].c;
    }

    priority_queue<Node> pqA, pqB;

    for (int i = 0; i < n; ++i)
        pqA.push({1, i});

    for (int i = 0; i < m; ++i)
        pqB.push({B[i].c, i});

    while (true) {
        ll ta = pqA.top().t;
        ll tb = pqB.top().t;

        ll t = min(ta, tb);

        if (ta == t) {
            ll damage = 0;

            while (!pqA.empty() && pqA.top().t == t) {
                int id = pqA.top().id;
                pqA.pop();

                damage += A[id].d;

                A[id].nxt += A[id].c;
                pqA.push({A[id].nxt, id});
            }

            h2 -= damage;

            if (h2 <= 0) {
                cout << t << '\n';
                cout << "Doloris\n";
                return 0;
            }
        }

        if (tb == t) {
            ll damage = 0;

            while (!pqB.empty() && pqB.top().t == t) {
                int id = pqB.top().id;
                pqB.pop();

                damage += B[id].d;

                B[id].nxt += B[id].c;
                pqB.push({B[id].nxt, id});
            }

            h1 -= damage;

            if (h1 <= 0) {
                cout << t << '\n';
                cout << "Mortis\n";
                return 0;
            }
        }
    }
}