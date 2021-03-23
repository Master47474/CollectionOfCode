



def ordofZ(sizeG):
    result = [1] * sizeG
    for z in range(1, sizeG):
        i = 1
        temp = z
        while((temp + z) % sizeG != z):
            i += 1
            temp += z
        result[z] = i

    for i in range(sizeG):
        print(i , ":" , result[i])




ordofZ(36)
