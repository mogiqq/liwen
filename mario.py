while True:
    n = input("Height: ")
    
    if n.isnumeric() == True:
        if 0 < int(n) < 9:
            break

n = int(n)
for i in range(1, n+1):
    if i < n:
        print(" " * (n-i) + "#" * (i))
    elif i == n:
        print("#" * n)

    