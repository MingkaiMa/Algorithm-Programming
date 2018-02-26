
def duplicate(L, size):
    if len(L) <= 0:
        return False


    zero_count = 0
    
    for i in range(0, size):


        if L[abs(L[i])] > 0:
   
            L[abs(L[i])] = -L[abs(L[i])]
            continue

        if L[abs(L[i])] < 0:

            print(abs(L[i]), 'is repeated')
            return True

        if L[abs(L[i])] == 0:
            if zero_count == 0:
                zero_count += 1
                continue

            print('0 is repeated')
            return True


    return False
                


