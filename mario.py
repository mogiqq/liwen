while True:
    n = input("Height: ")
    if n.isnumeric() == True:
        if 0 < int(n) < 9:
            break
        
n = int(n)
s = " "
hash = "#"

for i in range(1, n+1):
    print(s*(n-i) + hash*i + s*2 + hash*i)

