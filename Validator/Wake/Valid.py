# Author : ysh
# 2026/08/19 Wed 17:38:15
n = int(input())
assert 2 <= n <= 4 * (10 ** 5)

for _ in range(n):
    a, b = [int(i) for i in input().split()]
    assert 1 <= a <= n
    assert b in [0, 1]

quit()