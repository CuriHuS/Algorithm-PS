from collections import deque
import sys
M=int(input())
S=deque()
L=[ 0  for _ in range(21) ]
for i in range(M):
    a=sys.stdin.readline().rstrip().split()
    if len(a)>=2:
        a[1]=int(a[1])
        if a[0]=="add":
            if L[a[1]]==0:
                L[a[1]]=1
                S.append(a[1])
        elif a[0]=="remove":
            if L[a[1]]==1:
                L[a[1]]=0
                S.remove(a[1])
        elif a[0]=="check":
            if L[a[1]]==1:
                print(1)
            else:
                print(0)
        elif a[0]=="toggle":
            if L[a[1]]==1:
                L[a[1]]=0
                S.remove(a[1])
            else:
                L[a[1]]=1
                S.append(a[1])
    else:
        if a[0]=="all":
            S=deque([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20])
            L=[ 1 for _ in range(21) ]
        else:
            S=deque([])
            L=[ 0 for _ in range(21) ]
