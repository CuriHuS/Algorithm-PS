from collections import deque
n=int(input())
x,y=map(int,input().split())
m=int(input())
graph=[[0]*(n+1) for _ in range(n+1)]
visit_list=[0]*(n+1)
count_list=[1]*(n+1)
for i in range(m):
    a,b=map(int,input().split())
    graph[a][b]=graph[b][a] = 1

def bfs(v, end):
    q=deque()
    q.append(v)
    while q:
        v=q.popleft()
        if v==end:
            print(v)
            return True
        for i in range(1,n+1):
            if visit_list[i]==0 and graph[v][i]==1:
                print(v,i, q, visit_list) #정답 코드에선 제외
                visit_list[i]=1
                q.append(i)
                graph[i][v]=graph[v][i]+count_list[v] #v,i 노드가 연결되어 있는데, v->i로 탐색 시 x->y 진행 방향 하에서 몇 번째 깊이인지 파악
                print(graph, count_list) # 정답 코드에선 제외
                if graph[i][v] +1> count_list[v]:
                    count_list[i]=graph[i][v]
                    print("count:", count_list) #정답 코드에선 제외
                if i==end:
                    print(count_list[v]) #x->y까지 무사히 도착 시, 노드끼리의 최단 거리 
                    return True
    print(-1)    
visit_list[x]=1 #시작 위치로 돌아가는 것 방지
bfs(x,y)

# v: 방문할 노드. i: 해당 노드에서 다음 방문할 노드
# count_list: 노드의 깊이 저장 리스트(x->y로 진행할 때 노드끼리의 최단 연결 거리를 알기 위함)
# 
