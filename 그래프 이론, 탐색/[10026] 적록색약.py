from collections import deque

N=int(input())
q1=deque()
q2=deque()
graph=[[ [0] for i in range(N) ] for i in range(N) ]
for i in range(N):
    v=str(input())
    for j in range(N):
        graph[i][j]=v[j]


visit_list_CB=[ [0 for i in range(N) ] for i in range(N) ]
visit_list_N=[ [0 for i in range(N) ] for i in range(N) ]

ColorBlind_count= 0
Normal_count = 0


dx=[-1,1,0,0]
dy=[0,0,-1,1]

""" 
def check(L):
    for i in range(len(L)):
        print(L[i])
"""

def color_check(a,b): #색약이 R, G를 같다고 보는 것을 확인하는 함수 True: 구분 못함 False: 구분 함
    if a=='B':
        if b=='B':
            return True
        else:
            return False
    else:
        if b=='B':
            return False
        else:
            return True


def ColorBlind(L): #색약자
    global ColorBlind_count
    for n in range(N):
        for m in range(N):
            if visit_list_CB[n][m] == 0: # 다른 BFS와 달리 시작 및 시작해야될 좌표가 정해져있지 않으므로 모든 좌표의 경우를 본다.
                L.append((n,m))
                ColorBlind_count += 1 #다른 색을 만나는 부분에서 +1
                while L: #L이 비어있지 않으면 실행한다.
                    v,i = L.popleft() #방문해야할 곳 : 이전 방문 좌표와 색이 같았을 때 or 위에 이중 for문에서 내려온 경우(다른 색을 만났을 때)
                    color = graph[v][i] #기존 좌표의 색
                    for a in range(4): # 네 방향 확인 (상하좌우)
                        nx = v+dx[a]
                        ny = i+dy[a]
                        if 0<= nx < N and 0<= ny < N and visit_list_CB[nx][ny] == 0 and color_check(color, graph[nx][ny]):
                            # 다음 방문할 좌표의 색이 같고 방문한 적이 없었다면 방문해준다.
                            L.append((nx,ny))
                            visit_list_CB[nx][ny]=1
                
def Normal(L): # 정상인(색약자의 color_check 외에 똑같음)
    global Normal_count
    for n in range(N):
        for m in range(N):
            if visit_list_N[n][m]==0:
                L.append((n,m))방문하지 않았다면방문할 큐에 추가해준다
                Normal_count += 1 
                visit_list_N[n][m]=1 #이미 큐에는 들어가 있으므로 방문했다고 처리
                while L:
                    v,i = L.popleft()
                    color = graph[v][i]
                    for a in range(4):
                        nx = v+dx[a]
                        ny = i+dy[a]
                        if 0<= nx < N and 0<= ny < N and visit_list_N[nx][ny]==0 and color == graph[nx][ny]:
                            # 다음 방문할 좌표의 색이 같고 방문한 적이 없었다면 count를 추가하지 않게 방문해준다.
                            L.append((nx,ny))
                            visit_list_N[nx][ny]=1

Normal(q2)
ColorBlind(q1)
print(Normal_count)
print(ColorBlind_count)
