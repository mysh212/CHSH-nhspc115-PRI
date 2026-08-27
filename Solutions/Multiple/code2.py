# Author : ysh
# 2026/08/21 Fri 10:30:46
print((lambda x, y: x * y)(*[(lambda x, y: int(str(x) * y))(*j) for j in (lambda a, b, c, d: [[a, c], [b, d]])(*[int(i) for i in input().split()])]))