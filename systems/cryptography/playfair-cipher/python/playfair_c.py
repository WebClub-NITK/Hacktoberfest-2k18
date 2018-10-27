def main_func():
    input_key = input("Enter the key:")
    key = generate_key(input_key)
    print(key)
    p_t = input("Enter plaintext:")
    
    cipher_text = encrypt(p_t, key)
    print("Encrypted text:", cipher_text)
    
    #plain_text = decrypt(cipher_text, key)
    #print(plain_text)


def generate_key(string):
    key = []
    for i in range(len(string)):
        if not string[i] in key and string[i] != "j":
            key.append(string[i])
    remain = [chr(i) for i in range(ord('a'), ord('z') + 1) if not chr(i) in key and chr(i) != "j"]
    key.extend(remain)
    return [key[i:i + 5] for i in range(0, len(key), 5)]

def encrypt(plain_t, key):
    if not type(key) is list:
        key = generate_key(key)
    plain_t = plain_t.lower().replace(" ", "")
    p_t_grouped = []
    i = 0
    while i < len(plain_t):
        if i == len(plain_t) - 1:
            p_t_grouped.append(list(plain_t[i:i + 2]))
            i += 2
            continue
        if (plain_t[i] == plain_t[i + 1]):
            plain_t = plain_t[:i + 1] + "x" + plain_t[i + 1:]
        p_t_grouped.append(list(plain_t[i:i+ 2]))
        i += 2 
    if len(p_t_grouped[-1]) == 1:
        p_t_grouped[-1].append("x")
    
    cipher_t = ""
    for i in range(len(p_t_grouped)):
        for j in range(len(key)):
            for k in range(len(key[j])):
                if key[j][k] == p_t_grouped[i][0]:
                    r1 = j
                    c1 = k
                if key[j][k] == p_t_grouped[i][1]:
                    r2 = j
                    c2 = k
        if r1 == r2:
            cipher_t += key[r1][(c1 + 1) % len(key[r1])]
            cipher_t += key[r2][(c2 + 1) % len(key[r2])]
        elif c1 == c2:
            cipher_t += key[(r1 + 1) % len(key)][c1]
            cipher_t += key[(r2 + 1) % len(key)][c2]
        else:
            cipher_t += key[r1][c2]
            cipher_t += key[r2][c1]
    return cipher_t
def decrypt(cipher_t, key):
    if not type(key) is list:
        key = generate_key(key)
    c_t_grouped = [list(cipher_t[i:i + 2]) for i in range(0, len(cipher_t), 2)]
    
    plain_t = ""
    for i in range(len(c_t_grouped)):
        r1, r2 = None, None
        c1, c2 = None, None
        for j in range(len(key)):
            for k in range(len(key[j])):
                if key[j][k] == c_t_grouped[i][0]:
                    r1 = j
                    c1 = k
                if key[j][k] == c_t_grouped[i][1]:
                    r2 = j
                    c2 = k
        if r1 == r2:
            plain_t += key[r1][(c1 - 1) % len(key[r1])]
            plain_t += key[r2][(c2  - 1) % len(key[r2])]
        elif c1 == c2:
            plain_t += key[(r1 - 1) % len(key)][c1]
            plain_t += key[(r2 - 1) % len(key)][c2]
        else:
            plain_t += key[r1][c2]
            plain_t += key[r2][c1]
    return plain_t

main_func()