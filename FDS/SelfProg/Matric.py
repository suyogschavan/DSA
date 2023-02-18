row = int(input("enter the row number: "))
col = int(input("enter the column number: "))

print("Enter the elements for matrix1: \n")
matrix1 = [[int(input()) for i in range(col)] for j in range(row)]
print("matrix1: ")
for i in range(row):
    for j in range(col):
        print(matrix1[i][j], end=" ")
    print()
print("Enter the elements for matrix2: \n")
matrix2 = [[int(input()) for i in range(col)] for j in range(row)]
print("matrix2: ")
for i in range(row):
    for j in range(col):
        print(matrix2[i][j], end=" ")
    print()

# ADDITION
print("\nAddition of matrices...")
for i in range(row):
    for j in range(col):
        print(matrix1[i][j]+matrix2[i][j], end = " ")
    print()

# Multiplication
print("\nMultiplication of matrices....")
for i in range(row):
    for j in range(col):
        print(matrix1[i][j]*matrix2[i][j])
        



