import sys
sys.setrecursionlimit(10**6)
# 위 두 줄은 백준에서 재귀 깊이 설정으로 없으면 Recursion Error 발생
def dfs(x,y):
    if x<0 or x > M-1 or y<0 or y>N-1:
        return False
    if graph[y][x]==1:
        graph[y][x]=0
        dfs(x,y+1)
        dfs(x,y-1)
        dfs(x+1,y)
        dfs(x-1,y)
        return True
    return False
T=int(input())
for t in range(T):
    M,N,K=map(int, input().split())
    graph=[[0]*M for _ in range(N)]
    for _ in range(K):
        v,i = map(int,input().split())
        graph[i][v] = 1
    count=0
    for i in range(M):
        for a in range(N):
            if dfs(i,a)==True:
                count+=1
            else:
                continue
    print(count)

