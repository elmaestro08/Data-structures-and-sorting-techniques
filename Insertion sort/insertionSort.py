def ins(A):
    for j in range(1,len(A)):
        key = A[j]
        i = j-1
        while i >= 0 and A[i] > key:
            A[i+1] = A[i]
            i -= 1
        A[i+1] = key
    return A

def main():
    A = [6,4,1,2,5,3]
    print(ins(A))

if __name__ == '__main__':
    main()