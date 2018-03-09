def sort_array(source_array):
    if len(source_array) == 0:
        return source_array

    L = source_array[:]

    R = []
    T = []
    for i in L:
        if i % 2 == 0:
            R.append(i)
        else:
            R.append(None)
            T.append(i)

    T.sort()
    T.reverse()

    for i in range(len(R)):
        if R[i] is None:
            R[i] = T.pop()

    return T