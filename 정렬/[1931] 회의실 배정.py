T=int(input())
L=[]
answer=[]
for i in range(T):
    L.append(list(map(int,input().split())))
    L[i][0],L[i][1] = L[i][1],L[i][0]
L.sort(reverse=True)
i=0
j=1
while i<len(L):
    print(i,j,L,answer)
    if i+j>=len(L):
        answer.append(L[i+j-1])
        print("#0")
        break
    elif L[i][1]>=L[i+j][0]:
        answer.append(L[i])
        i=i+j
        j=1
        print("#1")
    elif L[i][0]>L[i+j][1] and L[i][1]<L[i+j][1]:
        i=i+j
        j=1
        print("#2")
    elif i>=len(L)-1:
        answer.append(L[i])
        print("#3")
        break
    else:
        j+=1
        print("#4")
print(len(answer))


#print("#n") 구문은 테스트용, print("#n") 구문 제거 시 정답 코드
