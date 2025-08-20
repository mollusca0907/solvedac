arr = []
max = 0
index = 0
for i in range(9):
    num = int(input())
    arr.append(num)
    if num > max:
        max = num
        index = i

print(max)
print(index + 1)
