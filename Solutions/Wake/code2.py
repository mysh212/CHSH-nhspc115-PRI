# Author : ysh
# 2026/08/19 Wed 17:26:12
n = int(input())

color = [i for i in range(n << 1)]

def ff(x: int) -> int:
    # print(x, color[x])
    color[x] = ff(color[x]) if color[x] != x else x
    return color[x]

def mg(a: int, b: int):
    color[ff(a)] = ff(b)
    return

for i in range(n):
    a, b = [int(i) for i in input().split()]
    a = a - 1
    if b == 0:
        mg(i, a)
        mg(i + n, a + n)
    else:
        mg(i + n, a)
        mg(a + n, i)

for i in range(n):
    if ff(i) == ff(i + n):
        print('No')
        quit()

print('Yes')
quit()