l=[0]*42
d=0
for i in range(10):
    x=int(input())
    if l[x%42]==0:
        d+=1
    l[x%42]+=1
print(d)