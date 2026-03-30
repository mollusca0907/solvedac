t = int(input())

for i in range(t):
    s = input()
    string = list(s.split(" "))
    for i in string:
        print(i[::-1], end=" ")
    print()