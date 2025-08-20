arr = []
for i in range(100):
    row = []
    for j in range(100):
        row.append(0)
    arr.append(row)
n = int(input())
cnt = 0
for _ in range(n):
    a, b = map(int, input().split())
    for i in range(10):
        for j in range(10):
            if arr[b+i][a+j] == 0:
                arr[b+i][a+j] = 1
                cnt += 1
print(cnt)