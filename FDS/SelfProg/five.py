def sortBySELECTION(l):
    for i in range(len(l)):
        for j in range(len(l)):
            if l[j]>= l[i]:
                temp = l[j]
                l[j]=l[i]
                l[i]=temp
    return l

def sortByBUBBLE(l):
    for j in range(len(l)-1):
        for i in range(len(l)-1):
            if l[i]>l[i+1]:
                temp = l[i]
                l[i]=l[i+1]
                l[i+1]= temp
    return l

def bestFive(l):
    for i in range(1, 6):
        print(i,": ",sorted[len(sorted)-i])

size = int(input("Enter the size of array: "))
arr=[float(input())for i in range(size)] #List comperihensan Method
# print(sortByBUBBLE(arr))
sorted = sortBySELECTION(arr)
print(sortBySELECTION(arr))