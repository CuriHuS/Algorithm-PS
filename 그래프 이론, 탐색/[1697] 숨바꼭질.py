from collections import deque
n,k = map(int,input().split())

visit_list=[0]*100001 # 중복 제외
count_list=[1]*100001 # 거리

def bfs(v, end):
    q=deque()
    q.append(v)
    while q:
        v=q.popleft()
        if v==end:
            return True
        if 0<= v-1 <= 100000 and visit_list[v-1]==0:
            q.append(v-1)
            visit_list[v-1]=1
            count_list[v-1]+=count_list[v]
        if 0<= v+1 <= 100000 and visit_list[v+1]==0:
            q.append(v+1)
            visit_list[v+1]=1
            count_list[v+1]+=count_list[v]
        if 0<= v*2 <= 100000 and visit_list[v*2]==0:
            q.append(v*2)
            visit_list[v*2]=1
            count_list[v*2]+=count_list[v]

bfs(n,k)
print(count_list[k]-1)
