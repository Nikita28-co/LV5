import multiprocessing as mp

def compute(part):
    return min(part), max(part), sum(part)

if __name__ == "__main__":
    # arr = list(map(int, input("Enter elements: ").split()))
    p=int(input("size: "))
    arr=[]
    for i in range (p):
        ele=int(input())
        arr.append(ele)
    

    n = len(arr)

    mid = n // 2
    chunks = [arr[:mid], arr[mid:]]

    with mp.Pool(2) as p:
        result = p.map(compute, chunks)

    min_val = min(r[0] for r in result)
    max_val = max(r[1] for r in result)
    total = sum(r[2] for r in result)

    print("Min:", min_val)
    print("Max:", max_val)
    print("Sum:", total)
    print("Avg:", total / n)

# if __name__ == "__main__":
#     main()