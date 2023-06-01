n = int(input("Enter the length of table: "))
dict1 = dict()
for i in range(n):
    dict1[i]=None

def hash(n):
    return n%len(dict1)

def insert(str):
    b = len(str)
    a = hash(b)
    if(dict1[a]==None):
        dict1[a]=str
    else:
        while(1):
            a=a+1
            if(a==len(dict1)):
                a = 0
            if(dict1[a]==None):
                dict1[a]=str
                return

insert("Suyog")
insert("Souls")
insert("another")
insert("thing")
insert("Suyash")
insert("Suyash3")


for i in dict1:
    print(i,"-->",dict1[i])