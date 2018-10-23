mapping_dictionary = {0: 'a',
                      1: 'b',
                      2: 'c',
                      3: 'd',
                      4: 'e',
                      5: 'f',
                      6: 'g',
                      7: 'h',
                      8: 'i',
                      9: 'j',
                      10: 'k',
                      11: 'l',
                      12: 'm',
                      13: 'n',
                      14: 'o',
                      15: 'p',
                      16: 'q',
                      17: 'r',
                      18: 's',
                      19: 't',
                      20: 'u',
                      21: 'v',
                      22: 'w',
                      23: 'x',
                      24: 'y',
                      25: 'z'}
plain_text = input().lower()  # just to ensure input will be always lower case
otp = input().lower()  # just to ensure input will be always lower case
if len(otp) < len(plain_text):  # if user enters OTP less than Plain Text length.
    print('In One Time Pad Encryption, Length of One Time Pad should be equal or more than length of Plain text')
    print('For more info, read article at https://en.wikibooks.org/wiki/Cryptography/One_time_pads')
    exit(0)
cipher_list = []
for i in range(len(plain_text)):
    reverse_dic = dict((v, k) for k, v in mapping_dictionary.items())
    key_sum_mod26 = (reverse_dic[plain_text[i]] + reverse_dic[otp[i]]) % 26
    cipher_list.append(mapping_dictionary[key_sum_mod26])
cipher_text = ''.join(cipher_list)
print(cipher_text)
