while True:
    num = input("Number: ")
    if num.isnumeric() == True:
        break
num = list(map(int, num))


def main():
    clen = len(num)
    first = num[0]
    second = num[1]
    
    if (clen == 15) and (first == 3) and (second == 4 or second == 7):
        if checksum_odd() == 0:
            print("AMEX")
    elif (clen == 16) and (first == 5) and (second <= 5):
        if checksum_even() == 0:
            print("MASTERCARD")
    elif (clen == 13) and (first == 4):
        if checksum_odd() == 0:
            print("VISA")
    elif (clen == 16) and (first == 4):
        if checksum_even() == 0:
            print("VISA")
    else:
        print("INVALID")


def checksum_even():
    sum = 0
    for i in range(0, len(num), 2)[::-1]:
        if num[i] < 5:
            sum += num[i] * 2
        else:
            sum += (((num[i] * 2) // 10) + ((num[i] * 2) % 10))

    for i in range(1, len(num), 2)[::-1]:
        sum += num[i]

    return sum % 10


def checksum_odd():
    sum = 0
    for i in range(1, len(num), 2)[::-1]:
        if num[i] < 5:
            sum += num[i] * 2
        else:
            sum += (((num[i] * 2) // 10) + ((num[i] * 2) % 10))

    for i in range(0, len(num), 2)[::-1]:
        sum += num[i]

    return sum % 10

   
main()