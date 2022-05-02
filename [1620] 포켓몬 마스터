import sys

        
N, M=map(int,input().split())
d={}
for i in range(N):
    name=str(sys.stdin.readline().strip('\n'))
    d[name]=i+1
    d[i+1]=name
L2=[]
for i in range(M):
    a=sys.stdin.readline().strip('\n')
    if a.isnumeric()==True:
        L2.append(int(a))
    else:
        L2.append(a)

for i in range(M):
    print(d[L2[i]])
