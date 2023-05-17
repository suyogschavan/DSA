#Assignment A-1 Problem Statement : Consider telephone book database of N clients. Make use of a hash table
#implementation to quickly look up client‘s telephone number.
#Make use of two collision handling techniques and compare them using
#number of comparisons required to find a set of telephone numbers




from LinearProbing import hashTable
from Record import Record


def input_record():
    record = Record()
    name = input("Enter Name:")
    number = int(input("Enter Number:"))
    record.set_name(name)
    record.set_number(number)
    return record
    

choice1 = 0
while(choice1 != 2):
    print("************************")
    print("1. Linear Probing      *")
    print("2. Exit                *")
    print("************************")

    choice1 = int(input("Enter Choice"))
    if choice1>2:
        print("Please Enter Valid Choice")

    if choice1 == 1:
        h1 = hashTable()
        choice2 = 0
        while(choice2 != 4):
            print("************************")
            print("1. Insert              *")
            print("2. Search              *")
            print("3. Display             *")
            print("4. Back                *")
            print("************************")

            choice2 = int(input("Enter Choice"))
            if choice2>4:
                print("Please Enter Valid Choice")

            if(choice2==1):
                record = input_record()
                h1.insert(record)

            elif(choice2 == 2):
                record = input_record()
                position = h1.search(record)

            elif(choice2 == 3):
                h1.display()

        

    

        

            
                
                
                
                
            
            
        






