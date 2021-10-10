#이것이 코딩테스트다 149page
#DFS/BFS 관련 문제

N,M=map(int,input().split())
graph=[]
for _ in range(N):
    graph.append(list(map(int,input())))
count=0

def dfs(x,y):
    if x < 0 or x > N-1 or y < 0 or y > M-1:
        return False
    if graph[x][y] == 0:
        graph[x][y]=1
        dfs(x+1, y)
        dfs(x-1, y)
        dfs(x, y+1)
        dfs(x, y-1)
        return True
    return False

for i in range(N):
    for a in range(M):
        if dfs(i,a)==True:
            count+=1
        else:
            continue
print(count)
