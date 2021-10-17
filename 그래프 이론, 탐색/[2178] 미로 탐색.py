from collections import deque
import sys
import copy
m,n= map(int,input().split())
graph=[]
for _ in range(n):
    graph.append(list(map(int,sys.stdin.readline().split())))
dx=[-1,1,0,0]
dy=[0,0,1,-1]
a=3
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

S=deque() # 1 좌표 큐
for i in range(n):
    for j in range(m):
        if graph[i][j] == 1:
            S.append((i,j))
        elif graph[i][j] == 0:
            a=0
            
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

# 시간 줄여야됨
