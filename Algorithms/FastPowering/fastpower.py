
g = 7
A = 4
m = 9
"""
print("Lets Fast Power (Modulo N)")
g = int(input("input the base >"))
A = int(input("input the exponent >"))
m = int(input("input the modulo >"))
"""

# break the A (power) into its binary components
Ab = bin(A)
strAb = str(Ab)[2:]
lstrAb = len(strAb)-1

#compute g^(2^A_i) Mod N for all A_i and multiply then modulo
solution = 1
for bit in range(0, len(strAb)):
    #get the binary value (2^i)
    if(strAb[lstrAb - bit] == "1"):
        binaryValue = 2**(bit)
        # place g ^ (2^i) then MOD m
        basePowBVmod = (g**binaryValue) % m
        # multiply the current product value to g ^ (2^i)
        solution *= basePowBVmod
        # Solution MOD m to be consistent
        solution = solution % m


print(solution)
