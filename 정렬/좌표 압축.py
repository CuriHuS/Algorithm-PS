import sys
N=int(input())
arr=list(map(int,sys.stdin.readline().split()))
arr_sort=sorted(set(arr))
arr_dict={}
for i in range(len(arr_sort)):
    arr_dict[arr_sort[i]]=i

for i in range(len(arr)):
    arr[i]=arr_dict[arr[i]]
    print(arr[i], end=" ")
