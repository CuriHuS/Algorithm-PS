from collections import deque
import sys
m,n= map(int,input().split())
graph=[]
a=3
S=deque()
for k in range(n):
    _ = list(map(int,sys.stdin.readline().split()))
    if 0 in _:
        a=0
    if 1 in _:
        for i in range(m):
            if _[i]==1:
                S.append((k,i))
    graph.append(_)

dx=[-1,1,0,0]
dy=[0,0,1,-1]
result=0
def bfs(L):
    global result
    while L:
        v, i = L.popleft()
        for  a in range(4):
            if 0<= v+dx[a] <n and 0<=i+dy[a] < m:
                if graph[v+dx[a]][i+dy[a]] == 0:
                    maximum=graph[v][i]+1
                    graph[v+dx[a]][i+dy[a]] = maximum
                    if maximum > result:
                        result=maximum
                    L.append((v+dx[a],i+dy[a]))
                else:
                    continue

S_long=len(S)
if S_long ==m*n:
    a=2
else:
    for i in range(S_long):
        bfs(S)

    for i in range(n):
        if 0 in graph[i]:
            print(-1)
            a=1
            break
if a == 0:
    print(result-1)
elif a==2 or a==3:
    print(0)
    
#python, pypy 모두 통과함.
#기존에 copy 모듈의 deepcopy를 이용했을 때는 시간초과.
