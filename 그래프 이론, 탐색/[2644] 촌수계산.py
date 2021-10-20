from collections import deque
n=int(input())
x,y=map(int,input().split())
m=int(input())
graph=[[0]*(n+1) for _ in range(n+1)]
visit_list=[0]*(n+1)
for i in range(m):
    a,b=map(int,input().split())
    graph[a][b]=graph[b][a] = 1
def bfs(v, end):
    q=deque()
    q.append(v)
    while q:
        v=q.popleft()
        if v==end:
            break
        for i in range(1,n+1):
            if visit_list[i]==0 and graph[v][i]==1:
                q.append(i)
                graph[v][i]=graph[i][v]+1

bfs(x,y)


# 위 코드는 bfs를 활용해서 이동 거리만큼 graph에 값을 추가함.
# 추가사항 1. END지점을 정해주어야 함.
# 추가사항 2. END지점에 도달하지 못 할 경우를 추가해야함.
