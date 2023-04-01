from collections import deque
import sys
m,n, h= map(int,input().split())
graph = [[[0 for col in range(m)] for row in range(n)] for depth in range(h)]
a=3
S=deque() #익은 토마토가 들어있는 좌표
for u in range(h):
    for k in range(n):
        _ = list(map(int,sys.stdin.readline().split()))
        if 0 in _:
            a=0
        if 1 in _:
            for i in range(m):
                if _[i]==1:
                    S.append((u,k,i))
        graph[u][k] = _


dx=[-1,1,0,0,0,0]
dy=[0,0,1,-1,0,0]
dz=[0,0,0,0,1,-1]
result=0
#너비 우선 탐색 함수
def bfs(L):
    global result
    while L:
        k, v, i = L.popleft()
        for  a in range(6):
            if 0<= v+dx[a] <n and 0<=i+dy[a] < m and 0<=k+dz[a] < h:
                if graph[k+dz[a]][v+dx[a]][i+dy[a]] == 0:
                    maximum=graph[k][v][i]+1
                    graph[k+dz[a]][v+dx[a]][i+dy[a]] = maximum
                    if maximum > result:
                        result=maximum
                    L.append((k+dz[a],v+dx[a],i+dy[a]))
                else:
                    continue

S_long=len(S)
if S_long ==m*n:
    a=2
else:
    for i in range(S_long):
        bfs(S)

def check_tomato():
    global a
    for u in range(h):
        for i in range(n):
            if 0 in graph[u][i]:
                a=1
                return 1
check_tomato()

if a == 1:
    print(-1)
elif a==0:
    print(result-1)
elif a==2 or a==3:
    print(0)
