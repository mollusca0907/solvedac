PI = 3.14159
n = int(input())
max_volume = 0

for _ in range(n):
    data = input().split()
    shape = data[0]

    if shape == 'S':
        r = float(data[1])
        volume = (4/3) * PI * r**3
    elif shape == 'L':
        r, h = map(float, data[1:])
        volume = PI * r**2 * h
    elif shape == 'C':
        r, h = map(float, data[1:])
        volume = (1/3) * PI * r**2 * h

    max_volume = max(max_volume, volume)

print(f"{max_volume:.3f}")