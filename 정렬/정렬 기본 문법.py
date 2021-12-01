# 선택 정렬

array=[7,5,9,0,3,1,6,2,4,8]
for i in range(1, len(array)):
    for j in range(i, 0, -1): #인덱스가 i부터 1까지 감소하면 반복하는 문법.
        if array[j] < array[j-1]:
             array[j],array[j-1]=array[j-1],array[j]
        else: #자기보다 작은 데이터를 만나면 멈춘다.
            break
print(array)


# 퀵 정렬
array=[5,7,9,0,3,1,6,2,4,8]

def quick_sort(array, start, end):
    if start >= end:
        return
    pivot=start
    left=start+1
    right=end
    while left<=right:
        while left <= end and array[left]<=array[pivot]:
            left+=1
        while right>start and array[right] >= array[pivot]:
            right -=1
        if left>right:
            array[right], array[pivot] = array[pivot],array[right]
        else:
            array[left],array[right]=array[right],array[left]
    quick_sort(array,start,right-1)
    quick_sort(array,right+1,end)

quick_sort(array, 0, len(array)-1)
print(array)

# 파이썬을 활용한 퀵 정렬

array=[5,7,9,0,3,1,6,2,4,8]

def quick_sort(array):
    if len(array)<=1:
        return array
    pivot=array[0]
    tail=array[1:] # 피벗을 제외한 리스트
    left_side=[x for x in tail if x <= pivot] #분할된 왼쪽 부분
    right_side=[x for x in tail if x> pivot]

    return quick_sort(left_side)+[pivot]+quick_sort(right_side)

print(quick_sort(array))

# 계수 정렬

array=[7,5,9,0,3,1,6,2,9,1,4,8,0,5,2]
count= [0] * (max(array)+1)

for i in range(len(array)):
    count[array[i]]+=1
    
for i in range(len(count)):
    for j in range(count[i]):
        print(i, end=" ")
