from collections import deque
import sys
m,n= map(int,input().split())
graph=[]
for _ in range(n):
    graph.append(list(map(int,sys.stdin.readline().split())))
dx=[-1,1,0,0]
dy=[0,0,1,-1]
a=True
result=0
def bfs(v,i):
    q=deque()
    q.append((v,i))
    global result
    while q:
        v, i = q.popleft()
        for  a in range(4):
            if 0<= v+dx[a] <n and 0<=i+dy[a] < m:
                if graph[v+dx[a]][i+dy[a]] == 0:
                    graph[v+dx[a]][i+dy[a]] = 1
                    bfs(v+dx[a], i+dy[a])
                else:
                    continue

bfs(n-1,m-1)
for i in range(n):
    if 0 in graph[i]:
        print(-1)
        a=False
        break
if a == True:
    print(result)
    
"""
1.일단, result 값을 어떻게 추가해야할 지 생각
2.또한 bfs를 n-1,m-1 좌표에서만 시작했던 것을 수정
3.이미 토마토가 모두 익어있을 때는 어떻게 해야할지 생각.
