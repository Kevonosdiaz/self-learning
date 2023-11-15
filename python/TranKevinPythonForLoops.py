# Python for-loops - CPSC 413 Assignment 6 Fall 2023
# Name: Kevin Tran
# Execute program using "python3 TranKevinPythonForLoops.py 4000"

import sys
import math

sys.set_int_max_str_digits(0)

F = int(sys.argv[1])

# Begin replace this part with own code
# Initialize both arrays/lists to 0
A = [[0 for i in range(F)] for j in range(F)]
B = [0 for i in range(F)]

total = 1  # A counter of total number of for-loop combinations so far, used for B[]
value = (
    1  # Stores the current number of for-loop combos for cell A[f,d], added to total
)

for f in range(F):  # Looping through number of for-loops (f)
    # Handle base case (rest of column is 0), too lazy to separate from loop :)
    if f == 0:
        A[0][0] = 1
        B[0] = 1
    else:
        total = 0
        for d in range(F):  # Loop through nesting depth values
            if d == 0: # Catch first row
                value = B[f - 1]
                A[f][d] = value
            elif d - 2 < 0: # Catch second row
                value = A[f][d - 1]
                A[f][d] = value
            else:
                value = A[f][d - 1] - A[f - 1][d - 2]
                A[f][d] = value
            # Update total with the number of combos for this execution
            total += value
    # Get total for just this f value
    B[f] = total


#     Two nested for-loops only
#     one outer for-loop, and one inner for-loop
# End replace this part with own code

# Please print to standard output whether
# your algorithm is space efficient or not

spaceefficient = False  # put a boolean value here
if spaceefficient:
    print("linear space - quadratic time")
else:
    print("quadratic space - quadratic time")

# Write answer to standard output
step = math.ceil(F / 5)
for b in range(F - 1, 0, -step):
    print(B[b])
