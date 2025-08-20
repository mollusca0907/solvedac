import math
n = int(input())
a = list(map(int, input().split()))
b, c = map(int, input().split())
t = 0
for x in a:
    t += 1 
    x -= b
    if x > 0:
        t += math.ceil(x / c)
print(t)