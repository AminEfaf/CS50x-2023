while True:
    cardNumber = input("Number: ")
    if cardNumber.isnumeric():
        break
    else:
        continue

evens = 0
odds = 0

reversedCardNumber = list(int(digit) for digit in cardNumber)[::-1]

for i, digit in enumerate(reversedCardNumber):
    if (i + 1) % 2 == 0:
        oddDigits = digit * 2
        if oddDigits > 9:
            odds += int(oddDigits / 10) + (oddDigits % 10)
        else:
            odds += oddDigits
    else:
        evens += digit

sum = evens + odds

if cardNumber and cardNumber[0:2].isdigit():
    strat = int(cardNumber[0:2])
else:
    strat = -1

if (sum % 10) == 0:
    if strat in [34, 37] and len(cardNumber) == 15:
        print("AMEX")
    elif strat in range(51, 56) and len(cardNumber) == 16:
        print("MASTERCARD")
    elif int(cardNumber[0]) == 4 and len(cardNumber) in [13, 16]:
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
