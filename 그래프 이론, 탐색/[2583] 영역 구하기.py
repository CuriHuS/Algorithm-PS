import sys
sys.setrecursionlimit(10**6)
def dfs(x,y):
    global count
    if x<0 or x > M-1 or y<0 or y>N-1:
        return False
    if graph[y][x]==1:
        graph[y][x]=0
        count += 1
        #print(y,x,count)
        #show(graph,N)
        dfs(x,y+1)
        dfs(x,y-1)
        dfs(x+1,y)
        dfs(x-1,y)
        return True
    return False
answer=[]

"""
# 그래프 형태 확인 함수
def show(g, n):
    for i in range(n-1, -1, -1):
        print(g[i]) """

#입력 코드
while True:
    N,M,K = map(int,input().split())
    if M==0 and N==0:
        break
    graph=[[1]*M for _ in range(N)]

    # graph 그리기 0: 직사각형으로 덮인 부분 1: 빈 부분
    for i in range(K):
        a,b,c,d = map(int,input().split())
        for w  in range(a, c):
            for h in range(b, d):
                graph[h][w] = 0
    #show(graph, N)

    #이게 돼야 됨.
    for i in range(M):
        for a in range(N):
            count=0
            if dfs(i,a)==True:
                #print("count: ", count)
                answer.append(count)
            else:
                continue
    answer.sort()
    print(len(answer))
    print(*answer)
    break #while문을 안 끝내주면 오류가 발생함.
