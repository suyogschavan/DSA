# # largest word in string
# str1 = input("Enter the string ")
# s=str1.split()
# max = 0

# for ele in s:
#     if len(ele)>max:
#         max = len(ele)
#         maxWord = ele
# print("Word with maximum length : ", maxWord)


# # Frequency 
# word = str(input("Enter the string you wan't to see the freq of occ: "))
# print("Frequency of ",word," is: ",str1.count(word))

# Palindrome
str2 = str(input("Check palindrome or not Enter the string: "))
# rev = ''.join(reversed(str2))
# if str2==rev:print("Yes")
if ''.join(reversed(str2))==str2:print("YEAHHH")
# else:print("No")

# str1=str(input("Enter the main string: "))
# key = str(input("Enter the substring: "))
# print("Element found at: ",str1.find(key))
