t=int(input())
for _ in range(0,t):
    s=input()
    p=1
    r=0
    for i in s:
        if i == 'O':
            r+=p
            p+=1
        else:
            p=1
    print(r)