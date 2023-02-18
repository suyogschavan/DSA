def SortBySelection(list1):
    list2 = list()
    for i in range(len(list1)+1):
        for j in range(len(list1)+1):
            if(list1[i]>list1[j]):
                list2.append(list1[j])
        
    return list2


list1 = [5, 3, 2, 1, 0]
print("Sorted by Selection: ", SortBySelection(list1))
            