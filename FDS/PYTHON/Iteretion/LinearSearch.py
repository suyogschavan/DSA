def SearchByLinear(list1, key):
    for i in range (len(list1)):
        if(key == list1[i]):
            print ("Key element found on index number ",i-1)
            return;
        if(i == len(list1)-1):
            print("There is no key element into this list")

a_list = [1,2,3,4,54,56,6,67]
keyElement = int(input("Enter the key element to search "))
SearchByLinear(a_list, keyElement)

        
        
        