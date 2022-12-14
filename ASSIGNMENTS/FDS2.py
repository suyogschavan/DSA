# write a python program to compute various string operations.
string = str(input("Enter the string: "))

# a. To display word with the longest length.
def longestWord(string):
    long = max(string.split(), key=len)
    print("The longest word is: '",long,"' with length: ", len(long))

# b. To determines the frequency of occurence of particular character in the string.
def frequency(string):
    key = str(input("Enter the string that you wan't to see frequency: "))
    print("Frequency of letter ",key," is : ", string.count(key))

# c. To check wether given string is palindrome or not
def isPalindrome(string):
    if(string[::-1]==string):
        print("This is PALINDROME")
    else:
        print("This is not a PALINDROME")

# d. To display index of first appearance of the substring.
def getIndex(string):
    subStr = str(input("Enter the subString you wan't to search : "))
    for i in range (len(string)):
        if string[i]==subStr:
            print("Sub string found at index: ",i)
        if string[i]==(len(string))-1:
            print("Not found...")

# e. To count the occurences of each word in a given string 
def occurenceofEach(string):
    counts = dict()
    words = string.split(" ")

    for word in words:
        if word in counts:
            counts[word] += 1
        else:
            counts[word] = 1
    print(counts)

            
longestWord(string)
frequency(string)
isPalindrome(string)
getIndex(string)
occurenceofEach(string)