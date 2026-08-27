# Author : ysh
# 2026/08/21 Fri 10:27:23
a, b, c, d = [int(i) for i in input().split()]

check = lambda x, y: int(str(x) * y)

print(check(a, c) * check(b, d))
quit()