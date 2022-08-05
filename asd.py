import heapq
import sys
N=int(input())
Q=[]
for i in range(N):
    a=int(sys.stdin.readline())
    if a==0:
        if len(Q)==0:
            print(0)
        else:
            print(heapq.heappop(Q)[1])
    else:
        heapq.heappush(Q, [abs(a),a])
        
