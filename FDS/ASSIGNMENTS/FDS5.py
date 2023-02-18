arr1 = [98.98, 35.90, 99.00, 91.91, 56.90, 20.20, 89.07, 50.50, 91.40, 93.56]

def selection(arr1):
    for i in range(len(arr1)):
        for j in range(len(arr1)):
            if arr1[i]<arr1[j]:
                temp = arr1[i]
                arr1[i] = arr1[j]
                arr1[j]=temp
    return arr1

def Bubble(arr1):
    for j in range(len(arr1)):
        for i in range(len(arr1)-1):
            if arr1[i]>arr1[i+1]:
                temp = arr1[i]
                arr1[i]= arr1[i+1]
                arr1[i+1] = temp
    return arr1


print("\nSorting by selection sort: ",selection(arr1))
print("Sorting by Bubble Sort   :  ",Bubble(arr1))
print("Top five Scores: ")
print("1st: ",arr1[len(arr1)-1], "\n2nd: ", arr1[len(arr1)-2])
print("3rd: ", arr1[len(arr1)-3])
print("4th: ", arr1[len(arr1)-4])
print("5th: ", arr1[len(arr1)-5], "\n")