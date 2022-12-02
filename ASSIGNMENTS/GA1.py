# Implement SET operations on arrayLinear data structure without using built-in functions.
GroupA={"Suyog", "Ritesh", "Suyash", "Aakash", "Aaditya"}     # Cricket
GroupB={"Ritesh", "Anil", "Aanand", "Jay", "Aakash", "Suyog" }  # Badminton
GroupC={"Suyash", "Aaditya", "Suyog", "Sourav", "Sai", "Kabir"}   #Football
AnB=set()
AnBcompl=set()
q3N, q4N = 0, 0

# 1. list of student who play both cricket and badminton i.e A∩B
for i in GroupA:
    for j in GroupB:
        if i==j:
            AnB.add(i)
print("Students who play both cricket as well as badminton: ",AnB)

# 2. List of student who play either cricket or badminton but not both i.e 
for i in GroupA:
        if i not in GroupB:AnBcompl.add(i)
for i in GroupB:
    if i not in GroupA:AnBcompl.add(i)
print("List of students who play either cricket or badminton: ", AnBcompl)

# 3. Number of student who play neither cricket nor badminton: 
for i in GroupC:
    if i not in GroupA and GroupB: q3N=q3N+1
print("Number of students who play neither cricket nor badminton is: ", q3N)

# 4. Number of student who play cricket and football but not badminton.
for i in GroupA and GroupC:
    if i not in AnB: q4N=q4N+1
print("Number of students who play cricket and football but not badminton: ",q4N)