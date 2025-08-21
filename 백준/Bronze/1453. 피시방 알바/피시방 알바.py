n=int(input())
l=[0 for i in range(101)]
a=list(map(int,input().split()))
p=0
for i in a:
    if(l[i]!=0):
        p+=1 
    l[i]+=1
print(p)
