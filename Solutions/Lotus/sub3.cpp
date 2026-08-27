#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> s;
    string x;

    while (cin >> x)
        s.push_back(x);

    int n = s.size();
    int m = 0;

    for (auto &x : s)
        m = max(m, (int)x.size());

    for (int i = 0; i < m; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            if (i < (int)s[j].size())
                cout << s[j][i];
            else
                cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}