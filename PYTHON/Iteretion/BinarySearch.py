def BinarySearch(list1, key):
    list2 = sortByBubble(list1)
    begining = 0
    end = len(list2)-1
    for i in range(len(list2)-1):
        
        mid = round((begining + end)/2)
        if(list2[mid]==key):
            print("Key found at index ",mid)
            return
        if(list2[mid]<key): 
            begining = mid+1
            
        if(list2[mid]>key): 
            end = mid - 1
        

def sortByBubble(list1):
    for i in range(len(list1)-1):
        for j in range(len(list1)-1):
            if(list1[j]>list1[j+1]):
                temp = list1[j]
                list1[j] = list1[j+1]
                list1[j+1]=temp
    print("Sorted List- ",list1)
    return list1


list1 = [3, 2, 5, 0, 1, 7]
key = 5
BinarySearch(list1, key)
