import fastpower as fp







total = 200000 #check the first 1 million numbers

#if g^p-1 mod p is equal to 1 then its flagged as a prime since the equation is true
flaggedOnFirst = 6
flaggedOnSecond = 6
flaggedOnThird = 6
flaggedOnForth = 6
#to account for 2, 3, 5, 7, 11, 13
totalPrime = 0

actualPrimes = 16385 #Estiamte < 200k
#actualPrimes = 9592 < 100k
#actualPrimes = 78498 < 1m

#args
g1 = 3
g2 = 5
g3 = 7
g4 = 13
# Power is I (A)
# MOD is I (m)



for i in range(14,total+1):
    if(i % 2 == 0):
        continue
    print(i)
    if (fp.fastPo(g1, i-1, i) != 1):
        continue
    flaggedOnFirst += 1
    if (fp.fastPo(g2, i-1, i) != 1):
        continue
    flaggedOnSecond += 1
    if(fp.fastPo(g3, i-1, i) != 1):
        continue
    flaggedOnThird += 1
    if(fp.fastPo(g4, i-1, i) != 1):
        continue
    flaggedOnForth += 1

print("For the first ", total, " ints the following happened")
print(flaggedOnFirst , " numbers FLT was true for one equation")
print(flaggedOnSecond , " numbers FLT was true for first two equations")
print(flaggedOnThird , " numbers FLT was true for three equations")
print(flaggedOnForth , " numbers FLT was true for all four equations")
print(actualPrimes , " numbers are actual primes in the first ",total," ints")
print("\n-----------------------------\nStats Are")
print((flaggedOnFirst/total) * 100 , "% flagged on first")
print((flaggedOnSecond/total) * 100 , "% flagged on first two")
print((flaggedOnThird/total) * 100 , "% flagged on three")
print((flaggedOnForth/total) * 100 , "% flagged on all four")
print((actualPrimes/total) * 100 , "% are primes in first ", total)
