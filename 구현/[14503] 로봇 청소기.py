N,M=map(int,input().split())
r,c,d=map(int,input().split())
L=[]
count=0
for i in range(N):
    L.append(list(map(int,input().split())))

# x가 세로 방향, y가 가로방향으로 움직인다.
L[r][c]=2

def test(t):
    for i in range(len(t)):
        print(t[i], end="\n")
        
def direct_change(a):
    #a=방향
    if a==0:
        a=3
    else:
        a-=1
    return a

def back_check(x,y,direct):
    global r
    global c
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
        elif L[x][y]==2:
            r=x
            c=y
            return True
        else:
            L[x][y]=2
            r=x
            c=y
            return True
        
def move(x,y,direct): #왼쪽 방향부터 천천히 검색하는 알고리즘으로 변경. 또한 보는 방향의 왼쪽임. y-1 매커니즘 아님.
    for i in range(4):
        if direct==0 and y-1>=0:
            if L[x][y-1] == 0:
                L[x][y-1]=2
                direct=direct_change(direct)
                move(x,y-1,direct)
                break
            else:
                direct=direct_change(direct)
        elif direct==1 and x-1>=0:
            if L[x-1][y] ==0:
                L[x-1][y]=2
                direct=direct_change(direct)
                move(x-1,y,direct)
                break
            else:
                direct=direct_change(direct)
        elif direct==2 and y+1<M:
            if L[x][y+1]==0:
                L[x][y+1]=2
                direct=direct_change(direct)
                move(x,y+1,direct)
                break
            else:
                direct=direct_change(direct)
        elif direct==3 and x+1<N:
            if L[x+1][y]==0:
                L[x+1][y]=2
                direct=direct_change(direct)
                move(x+1,y,direct)
                break
            else:
                direct=direct_change(direct)
        if i==3:
            if back_check(x,y,direct)==True:
                L[r][c]=2
                move(r,c,direct)
                break
            else:
                break

move(r,c,d)
for i in range(N):
    count+=L[i].count(2)
print(count)
