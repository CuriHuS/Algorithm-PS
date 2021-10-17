import sys
sys.setrecursionlimit(10**6)
def dfs(x,y):
    if x<0 or x > w-1 or y<0 or y>h-1:
        return False
    if graph[y][x]==1:
        graph[y][x]=0
        dfs(x,y+1)
        dfs(x,y-1)
        dfs(x+1,y)
        dfs(x-1,y)
        dfs(x+1,y+1)
        dfs(x-1,y+1)
        dfs(x+1,y-1)
        dfs(x-1,y-1)
        return True
    return False

while True:
    w, h = map(int,input().split())
    count=0
    if w==0 and h==0:
        break
    graph=[[0]*w for _ in range(h)]
    for i in range(h):
        graph[i]=list(map(int,input().split()))
    for i in range(w):
        for a in range(h):
            if dfs(i,a)==True:
                count+=1
            else:
                continue
    print(count)
