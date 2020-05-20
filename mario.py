while True:
    print("Height: ", end="")
    n = int(input())
    if 0 < n < 9:
        for j in range(n):
            if j < n:
                print(" " * (n-(j+1)) + "#" * (j+1))
            elif j == n-1:
                print("#" * n)
        break
    