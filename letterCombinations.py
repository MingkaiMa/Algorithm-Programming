
def letterCombinations(digits):
    digit_map = {
    '2': 'abc',
    '3': 'def',
    '4': 'ghi',
    '5': 'jkl',
    '6': 'mno',
    '7': 'pqrs',
    '8': 'tuv',
    '9': 'wxyz',
    }


    L = ['']

    for char in digits:
        letters = digit_map.get(char, '')

 #       L = [prefix + letter for prefix in L for letter in letters]

        T = []


        for i in L:
            for l in letters:
                T.append(i + l)

        L = T
    

    print(L)
