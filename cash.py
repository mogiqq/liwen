coins = [0.25, 0.1, 0.05, 0.01]
count = 0

while True:
    change = input("Change owed: ")
    if change.replace(".", "").isdigit() == True:
        if float(change) >= 0:
            break

change = float(change)
for i in range(len(coins)):
    while change > coins[i] or change == coins[i]:
            multipy = int(change / coins[i])
            change = round(change % coins[i], 2)
            count += multipy
    if change == 0:
        break

print(f"{count}")




