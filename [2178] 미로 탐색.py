from collections import deque
import sys
read = sys.stdin.readline


graph=[]
n,m = map(int,input().split())
for _ in range(n):
    graph.append(list(map(int,input())))
v,i=0,0
def bfs(v,i):
    print(graph)
    try:
        if graph[v+1][i] == 1:
            graph[v+1][i]+=graph[v][i]
            bfs(v+1,i)
        if graph[v][i+1] == 1:
            graph[v][i+1]+=graph[v][i]
            bfs(v,i+1)
        if graph[v-1][i] == 1:
            graph[v-1][i]+=graph[v][i]
            bfs(v-1,i)
        if graph[v][i-1] == 1:
            graph[v][i-1]+=graph[v][i]
            bfs(v,i-1)
    except:
        0
            
bfs(v,i)

# 문제점: if 단계에서 bfs 재귀함수가 걸리면서 if 한번하고 재귀걸리고 다른 if가서 또 재귀함. -> 이거 
