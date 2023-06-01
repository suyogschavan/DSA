# With Chaining

def display(hashTable):
    for i in range(len(hashTable)):
        print(i, end = " ")
        
        for j in hashTable[i]:
            print("-->", end=" ")
            print(j, end=" ")
        
        print()
        

hashTable = [[]for _ in range(10)]

def Hashing(keyvalue):
    return keyvalue%len(hashTable)

def insert(hashtable, keyvalue, value):
    hash_key = Hashing(keyvalue)
    hashtable[hash_key].append(value)
    

insert(hashTable, 10, 'Allahabad')
insert(hashTable, 20, 'Soul')


display(hashTable)