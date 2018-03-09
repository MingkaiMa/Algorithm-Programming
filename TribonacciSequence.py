def tribonacci(signature, n):
    if n == 0:
        return []
    if n <= 3:
        return [signature[n - 1]]
    previous = signature[0]
    middle = signature[1]
    current = signature[2]
    numbers = [previous, middle]
    nb = 2
    while nb < n:
        numbers.append(current)
        previous, middle, current = middle, current, previous + middle + current
        nb += 1
    return numbers