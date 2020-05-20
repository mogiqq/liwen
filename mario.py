while True:
    print("Height: ", end="")
    n = int(input())
    
    if 0 < n < 9:
        break


for i in range(1, n+1):
    if i < n:
        print(" " * (n-i) + "#" * (i))
    elif i == n:
        print("#" * n)

    