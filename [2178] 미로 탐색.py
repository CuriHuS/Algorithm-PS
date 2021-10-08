from collections import deque
import sys
read = sys.stdin.readline


graph=[]
n,m = map(int,input().split())
for _ in range(n):
    graph.append(list(map(int,input())))
x,y=0,0
dx=[-1,1,0,0]
dy=[0,0,1,-1]

def bfs(v,i):
    print(graph)
    for a in range(3):
        print(v,i,a)
        
        if 0<=  v+dx[a] < n and 0<=i+dy[a] < m:
            if graph[v+dx[a]][i+dy[a]] == 1:
                graph[v+dx[a]][i+dy[a]] += graph[v][i]
                bfs(v+dx[a],i+dy[a])
        else:
            continue
            
bfs(x,y)

print(graph[n-1][m-1])

### 정답 ###
"""
from collections import deque
import sys
read = sys.stdin.readline


graph=[]
n,m = map(int,input().split())
for _ in range(n):
    graph.append(list(map(int,input())))
x,y=0,0
dx=[-1,1,0,0]
dy=[0,0,1,-1]

def bfs(v,i):
    q=deque()
    q.append((v,i))
    while q:
        v, i = q.popleft()
        for a in range(4):
            if 0<=  v+dx[a] < n and 0<=i+dy[a] < m:
                if graph[v+dx[a]][i+dy[a]] == 1:
                    graph[v+dx[a]][i+dy[a]] += graph[v][i]
                    q.append((v+dx[a],i+dy[a]))
            else:
                continue
            
bfs(x,y)

print(graph[n-1][m-1])
"""
