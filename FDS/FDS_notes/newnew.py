
# matrix1 = [[int(input()) for i in range(2)]for j in range(2)]
# print(matrix1)
# print()
# # For dislay
# for i in range(2):
#     for j in range(2):
#         print(matrix1[i][j], end=" ")
#     print()

# # For Addition
# print("Addition of two matrix")
# for i in range(2):
#     for j in range(2):
#         print(matrix1[i][j]+matrix1[i][j], end=" ")
#     print()

# # Substraction
# print("\nSubstraction of two matrix\n")
# for i in range(2):
#     for j in range(2):
#         print(matrix1[i][j]-matrix1[i][j], end=" ")
#     print()

# # Multiplication
# row1 = int(input("Enter the row number for matrix1: "))
# col2 = int(input("Enter the col number for matrix2: "))
# col_row = int(input("Enter the col number for matrix1 and Row number for matrix2: "))
# print("\nEnter the Elements for matrix 1: ")
# matrix1 = [[int(input()) for i in range(col_row)] for j in range(row1)]
# print("\nEnter the Elements for matrix 2: ")
# matrix2 = [[int(input()) for i in range(col2)] for j in range(col_row)]
# # print(matrix1)
# print("Matrix1: ")
# for i in range(row1):
#     for j in range(col_row):
#         print(matrix1[i][j], end=" ")
#     print()
# print("Matrix2: ")
# for i in range(col_row):
#     for j in range(col2):
#         print(matrix2[i][j], end=" ")
#     print()

# result = [[0 for i in range(col2)] for j in range(row1)]
# for i in range(row1):
#     for j in range(col2):
#         for k in range(col_row):
#             result[i][j]=result[i][j]+matrix1[i][k]*matrix2[k][j]
            
# print('\nMultiplication: ')
# for i in range(row1):
#     for j in range(col2):
#         print(format(result[i][j], "<4"),end=" ")
#     print()

# Transpose of Matrix
row = int(input("Enter the no. of rows: "))
col = int(input("Enter the no. of colms: "))

matrix1 = [[int(input()) for i in range(col)]for j in range(row)]
result = [[0 for i in range(row)]for j in range(col)]

for i in range(col):
    for j in range(row):
        print(format(matrix1[j][i]), end=" ")
        # result[i][j]=matrix1[j][i]
    print()

# for i in range(col):
#     for j in range(row):
#         print(format(result[i][j]), end=" ")
#     print()