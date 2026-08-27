#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007LL;

struct Func {
    long long a, b;
};

int main() {
    // 關閉 I/O 同步以加速輸入輸出
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;

    vector<Func> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i].a >> f[i].b;
    }

    // 貪心排序：依據複合函數 f(g(x)) 與 g(f(x)) 的增長量來決定執行先後
    sort(f.begin(), f.end(), [](const Func& lhs, const Func& rhs) {
        long long val_lhs = lhs.b * (rhs.a - 1);
        long long val_rhs = rhs.b * (lhs.a - 1);
        
        if (val_lhs != val_rhs) {
            return val_lhs > val_rhs;
        }
        // Tie-breaker：若兩函數對結果的貢獻相同，強加絕對順序以滿足「嚴格弱排序」
        if (lhs.a != rhs.a) {
            return lhs.a < rhs.a;
        }
        return lhs.b > rhs.b;
    });

    x %= MOD;
    for (int i = 0; i < n; i++) {
        // 邊乘加邊取模，保證過程中不超過 long long 上限
        x = (x * f[i].a % MOD + f[i].b % MOD) % MOD;
    }

    cout << x << '\n';

    return 0;
}