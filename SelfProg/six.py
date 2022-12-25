# Count Sort
def countSort(l, N):
    l2 = [0 for i in range(10)]
    result=[]
    # print(l2)
    for i in range(len(l)):
        l2[l[i]]=l.count(l[i])
    for i in range(len(l)):
        while l2[i]>0:
            result.append(i)
            l2[i]=l2[i]-1
    return result

def RadixSort(l):
    maximum = max(l)
    N=1
    while maximum//N>0:
        countSort(l, N)
# list1=[int(input())for i in range(10)]
list1=[9, 2, 4, 1, 5, 3, 2, 2, 5, 3]
print(countSort(list1))