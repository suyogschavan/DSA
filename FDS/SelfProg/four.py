size=int(input("Enter the size of list: "))
roll=[int(input())for i in range(size)]
print(roll)

# Linear Search
def searchByLinear(roll):
    key = int(input("Enter the roll no. you wanna search for.: "))
    for i in range(len(roll)):
        if key == roll[i]:print("Found at: ", roll[i])
        elif roll[i]==len(roll)-1 : print("Not found")

def searchBySentinel(roll):
    key = int(input("Enter the no. you wanna search for: "))
    roll.append(key)
    i = 0
    while roll[i]!=key:
        i+=1
    if i == size:return "Not found"
    else : return "Found at: ",i

