import sys
from collections import deque
T=int(input())

for i in range(T):
    command_list=list(map(str,sys.stdin.readline().strip()))
    n=int(input())
    array=list(map(str,sys.stdin.readline().strip()))
    modified_array=deque()
    modify_index=[]
    reverse_count=0
    print(array, len(array))
    for _ in range(len(array)):
        try:
            if int(array[_]) is True:
                try:
                    if int(array[_+1]) is True:
                        modified_array.append(int(array[_]))
                        modify_index.append(len(modified_array))
                        continue
                    else:
                        modified_array.append(int(array[_]))
                        modify_index.append(len(modified_array))
                        continue
                except:
                    modified_array.append(int(array[_]))
            else:
                try:
                    if int(array[_+1]) is True:
                        modified_array.append(int(array[_]))
                        modify_index.append(len(modified_array))
                        continue
                    else:
                        modified_array.append(int(array[_]))
                        modify_index.append(len(modified_array))
                        continue
                except:
                    modified_array.append(int(array[_]))           
        except:
            continue
    print(modified_array)
    print(modify_index)
    mi=modify_index
    memory=mi[-1]
    for j in range(len(modify_index),0, -1):
        if j-memory==1:
            modified_array[mi[j]]=int(str(modified_array[mi[j]])+str(modified_array[mi[j-1]])+str(modified_array[mi[j-2]]))
        else:
            modified_array[mi[j]]=int(str(modified_array[mi[j]])+str(modified_array[mi[j-1]]))
        memory=j
        print(modified_array)
    print(modified_array)
    try:
        for a in command_list:
            if a=="R":
                reverse_count+=1
            elif a=="D":
                if reverse_count%2==0:
                    modified_array.popleft()
                else:
                    modified_array.pop()
        if len(modified_array)==0:
            print("[]")
        else:
            if reverse_count%2==0:
                print("[", end="")
                for j in range(len(modified_array)-1):
                    print(modified_array[j],end=",")
                print(modified_array[-1],end="]")
            else:
                modified_array.reverse()
                pprint("[", end="")
                for j in range(len(modified_array)-1):
                    print(modified_array[j],end=",")
                print(modified_array[-1],end="]")

    except:
        print("error")
