from collections import deque
import sys
import copy
m,n= map(int,input().split())
graph=[]
a=3
S=deque()
for _ in range(n):
    _ = list(map(int,sys.stdin.readline().split()))
    if 0 in _:
        a=0
    if 1 in _:
        for li in len(_)
    graph.append(_)

dx=[-1,1,0,0]
dy=[0,0,1,-1]
result=0
def bfs(L):
    q=copy.deepcopy(S)
    global result
    while q:
        v, i = q.popleft()
        for  a in range(4):
            if 0<= v+dx[a] <n and 0<=i+dy[a] < m:
                if graph[v+dx[a]][i+dy[a]] == 0:
                    graph[v+dx[a]][i+dy[a]] = graph[v][i]+1
                    if graph[v][i]+1 > result:
                        result=graph[v][i]+1
                    q.append((v+dx[a],i+dy[a]))
                
                else:
                    continue

            
if len(S)==m*n:
    a=2
else:
    for i in range(len(S)):
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

