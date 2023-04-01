import sys
sys.setrecursionlimit(10**6)
def dfs(x,y):
    global count
    if x<0 or x > M-1 or y<0 or y>N-1:
        return False
    if graph[y][x]==1:
        graph[y][x]=0
        count += 1
        dfs(x,y+1)
        dfs(x,y-1)
        dfs(x+1,y)
        dfs(x-1,y)
        return True
    return False
answer=[]

while True:
    N,M= map(int,input().split())
    graph=[]
    for i in range(N):
        graph.append(list(map(int, sys.stdin.readline().split())))

    for i in range(M):
        for a in range(N):
            count=0
            if dfs(i,a)==True:
                answer.append(count)
    if len(answer)==0:
        print(0)
        print(0)
        break
    else:
        answer.sort()
        print(len(answer))
        print(answer[-1])
        break
