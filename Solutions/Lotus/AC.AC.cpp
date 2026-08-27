#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> s;
    string str;

    while (getline(cin, str))
        s.push_back(str);

    int n = s.size();
    int mx = 0;

    for (const string &x : s)
        mx = max(mx, (int)x.size());

    for (int i = 0; i < mx; ++i) {
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