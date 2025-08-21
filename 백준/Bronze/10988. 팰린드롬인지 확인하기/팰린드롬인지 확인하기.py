s = input()
length = len(s)
is_p = 1
for i in range(length // 2):
    if s[i] != s[length - i - 1]:
        is_p = 0
        break
print(is_p)
