import sys
N=int(input())
T=[0] * (N+1)
P=[0] * (N+1)
dp=[0]*(N+2)
for i in range(1,N+1):
    a,b=map(int, sys.stdin.readline().split())
    T[i]=a
    P[i]=b
for i in range(N, 0, -1): #역순으로 실행
    if T[i]+i > N+1: #시간 초과시
        dp[i]=dp[i+1]
    else: # 시간 가능
        dp[i]= max(dp[i+1], P[i]+dp[i+T[i]])
        #뒷날에 일한 값과 오늘 일했을 때 더 큰 값을 저장
        #P[i] 오늘 일한 값 + dp[i+T[i]] 오늘 일할 때 걸리는 시간 전에 일했던 값
        #dp[i+T[i]] 즉, 3일차에 이틀이 걸린다하면 5일차의 dp값을 가져온다.
print(dp[1])

#참고: https://www.acmicpc.net/board/view/66558
