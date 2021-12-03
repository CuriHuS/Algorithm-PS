N,M=map(int,input().split())
r,c,d=map(int,input().split())
L=[]
count=0
for i in range(N):
    L.append(list(map(int,input().split())))

# x가 세로 방향, y가 가로방향으로 움직인다.
L[r][c]=2
count+=1

def test(t):
    for i in range(len(t)):
        print(t[i], end="\n")
        
def direction_change(a):
    #a=방향
    if a==3:
        a=0
    else:
        a+=1

def back_check(x,y,direct):
    if direct==0:
        x+=1
    elif direct==1:
        y-=1
    elif direct==2:
        x-=1
    elif direct==3:
        y+=1

    if 0<=x < N and 0<=y < M:
        if L[x][y]==1:
            return False
        else:
            r=x
            c=y
            return True

dx=[-1,1,0,0]
dy=[0,0,1,-1]
        
def move(x,y,direct): #왼쪽 방향부터 천천히 검색하는 알고리즘으로 변경. 또한 보는 방향의 왼쪽임. y-1 매커니즘 아님.
    global count
    check=0
    for i in range(4):
        if 0<= x+dx[i] < N and 0<= y+dy[i] < M:
            if L[x+dx[i]][y+dy[i]]==0:
                check+=1
                
    if check==0: #청소공간 없음.
        if back_check(x,y,direct) == False:
            print("C")
            return False
        else:
            print("D")
            move(r,c,direct)
    else: #청소 공간 있음.
        if x>= 0 and y-1>=0:
            if L[x][y-1]==0:
                L[x][y-1]=2
                print("E")
                count+=1
                move(x,y-1,direct)
            elif L[x-1][y]==0:
                L[x-1][y]=2
                count+=1
                
        else:
            print("F")
            direction_change(direct)
            count+=1
            move(x,y,direct)

move(r,c,d)
print(count)
            
            
        
