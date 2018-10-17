import itertools

def vigenere(inputText, key):
    inputText = inputText.replace(" ", "").lower()
    key = key.replace(" ", "").lower()
    outputText = ""
    for letter, key_index in zip(inputText, itertools.cycle(key)):

        # skip non alphabets
        if not letter.isalpha():
            outputText += letter
            continue
        
        distance = ord(key_index) - ord('a')
        newChar = ord(letter) + distance

        if newChar > ord('z'):
            outputText += chr(newChar - 26)
        else:
            outputText += chr(newChar)

    return outputText



def main():
    inputText = input("Please input plain text: ")        # get input plain text
    key = input("Please input keyword: ")                 # get key
    print("input = {}\nkey = {}".format(inputText, key))
    output = vigenere(inputText, key)

    print("Output is: {}".format(output))
    

if __name__ == "__main__":
    main()