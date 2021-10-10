N=int(input())
M=int(input())
graph=[[0] * (N+1) for _ in range(N+1)]

for _ in range(M):
    a,b=map(int,input().split())
    graph[a][b] = graph[b][a] = 1

visit_list=[ 0* 1 for _ in range(N+1) ]
def dfs(v):
    visit_list[v]=1
    for i in range(1, N+1):
        if graph[v][i] == 1 and visit_list[i]==0:
            dfs(i)

dfs(1)

print(visit_list.count(1)-1)
