# 1. sentinel search 
def sentinel(l, key):
    l.append(key)
    i = 0 
    while(l[i] != key):
        i +=1
    if(i == len(l)):return None
    else:return i

# 2. Binary search technique
def binary(l, key):
    start = 0
    last = len(l)-1
    for i in range(len(l)-1):
        mid = round((start+last)/2)
        if(l[mid] == key):return mid
        if(l[mid]>key):last = mid
        if(l[mid]<key):start = mid+1


# 3.  Fibonacci search technique
def fibonacci_search(l, key):
    size = len(l)
    start = -1
    f0 = 0
    f1 = 1
    f2 = 1
    while(f2 < size):
        f0 = f1
        f1 = f2
        f2 = f1 + f0
    while(f2 > 1):
        index = min(start + f0, size - 1)
        if l[index] < key:
            f2 = f1
            f1 = f0
            f0 = f2 - f1
            start = index
        elif l[index] > key:
            f2 = f0
            f1 = f1 - f0
            f0 = f2 - f1
        else:
            return index
    if (f1) and (l[size - 1] == key):
        return size - 1
    return None

def run():
    list1 = [1, 3, 5, 6, 7, 8, 23, 34, 45, 56, 78]
    print("List: ",list1)
    key = int(input("Enter the element to search: "))
    print("\n1. sentinel search")
    print("2. binary search")
    print("3. fibonacci search")
    print("4. EXIT")

    choice = int(input("Enter the choice: "))
    if choice==1:
        print(sentinel(list1, key))
        run()
    if choice==2:
        print(binary(list1, key))
        run()
    if choice==3:
        print(fibonacci_search(list1, key))
        run()
    if choice==4:
        return

run()