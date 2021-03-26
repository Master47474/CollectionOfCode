



def ordofZ(sizeG, ordOf = None):
    result = [1] * sizeG
    for z in range(1, sizeG):
        i = 1
        temp = z
        while((temp + z) % sizeG != z):
            i += 1
            temp += z
        result[z] = i

    NordOf = 0
    for i in range(sizeG):
        if(result[i] == ordOf):
            NordOf += 1
        print(i , ":" , result[i])

    if(ordOf != None):
        print(f"Number of order {ordOf} is {NordOf}")



ordofZ(168, 84)
