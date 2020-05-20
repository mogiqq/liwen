while True:
    n = int(input("Height (1 to 8): "))
    if 0 < n < 9:
        for j in range(n):
            if j < n:
                print(" " * (n-(j+1)) + "#" * (j+1))
            elif j == n-1:
                print("#" * n)
        break
    else:
        int(input("Height (1 to 8): "))
    