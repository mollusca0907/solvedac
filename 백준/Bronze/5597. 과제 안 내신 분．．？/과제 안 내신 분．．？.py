s=[0 for i in range(30)]

for i in range(28):
    x = int(input())
    s[x-1] = 1

for i in range(30):
    if s[i] == 0:
        print(i+1)