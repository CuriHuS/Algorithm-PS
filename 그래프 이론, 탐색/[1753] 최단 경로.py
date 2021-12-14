import sys
V,E=map(int,input().split())
K=int(input())
L=[]

def dfs(v, end):
    visit[v]=1
    global result
    result=0
    graph=[0]*(1+V)
    for a,b,c in L:
        #print(a,b,c)
        if visit[b]==0 and a==v:
            graph[b]=graph[a]+c
            if b==end:
                result=graph[b]
                return result
            else:
                #print("#1")
                dfs(b, end)
    return False

for i in range(E):
    L.append(list(map(int,sys.stdin.readline().split())))
for i in range(1, V+1):
    if i==K:
        print(0)
    else:
        result=0
        visit=[0]*(V+1)
        dfs(K, i)
        if result==False:
            print("INF")
        else:
            print(result)



# end=4 일 때 오류 발생 
