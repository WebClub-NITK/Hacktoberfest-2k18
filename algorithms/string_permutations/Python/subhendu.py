#String Permutations
def permutations(str, index = 0):
    if index == len(str):
        print "".join(str)
    for i in range(index, len(str)):
        strCopy = [character for character in str]
        strCopy[index], strCopy[i] = strCopy[i], strCopy[index]
        permutations(strCopy, index + 1)

