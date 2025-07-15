import sys
N=int(sys.stdin.readline())
a=list(map(int,sys.stdin.readline().split()))
dy=[1]*N
for i in range(1, N):
    for j in range(0, i):
        if a[i]>a[j] and dy[i]<dy[j]+1:
            dy[i]=dy[j]+1
print(max(dy))