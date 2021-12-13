import sys
from collections import deque
T=int(input())

for i in range(T):
    command_list=list(map(str,sys.stdin.readline().strip()))
    n=int(input())
    s=sys.stdin.readline().strip()
    if s=="[]":
        array=deque()
    else:
        a=list(map(int, s[1:-1].split(",")))
        array=deque()
        for j in a:
            array.append(j)

    reverse_count=0
    try:
        for a in command_list:
            if a=="R":
                reverse_count+=1
            elif a=="D":
                if reverse_count%2==0:
                    array.popleft()
                else:
                    array.pop()
        if len(array)==0:
            print("[]")
        else:
            if reverse_count%2==0:
                print(str(list(array)).replace(" ", ""))
            else:
                array.reverse()
                print(str(list(array)).replace(" ", ""))

    except:
        print("error")
