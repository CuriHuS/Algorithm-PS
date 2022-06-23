from collections import deque
N,M = map(int,input().split())
graph=dict()
for i in range(M):
    a,b = map(int,input().split())
    if a not in graph:
        graph[a]=[b]
    else:
        graph[a]+=[b]
    if b not in graph:
        graph[b]=[a]
    else:
        graph[b]+=[a]
    
visit_list=[0]*(N+1)

def bfs(v):
    q=deque()
    q.append(v)
    visit_list[v]=1
    while q:
        v=q.popleft()
        for a in graph[v]:
            if visit_list[a]==0:
                q.append(a)
                visit_list[a]=1
    return True
count=0

for i in graph.keys():
    if visit_list[i]==0:
        if bfs(i) is True:
            count+=1
count+=visit_list.count(0)-1 # 연결된 노드가 없는 정점도 포함

print(count)
