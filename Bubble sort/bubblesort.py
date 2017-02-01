def bubble(A):
    for i in range(len(A)-1):
        for j in range(len(A)-i-1):
            if A[j]>A[j+1]:
                A[j],A[j+1] = A[j+1],A[j]
    return A

def main():
    A = [6, 5, 4, 3, 2, 1]
    print(bubble(A))

if __name__ == '__main__':
    main()