import numpy as np
import time as time
from multiprocessing import Pool, cpu_count

# ---------- Sequential Vector Addition ----------
def sequential_add(A, B):
    C = []
    for i in range(len(A)):
        C.append(A[i] + B[i])
    return C

# ---------- Parallel Worker ----------
def add_pair(pair):
    return pair[0] + pair[1]

# ---------- Parallel Vector Addition ----------
def parallel_add(A, B):
    with Pool(cpu_count()) as p:
        C = p.map(add_pair, zip(A, B))
    return C

# ---------- Main ----------
if __name__ == "__main__":
    N = 100000

    # Generate vectors
    A = np.random.randint(0, 100, N)
    B = np.random.randint(0, 100, N)

    print(A)
    print (B)
    

    # Sequential
    start = time.time()
    C_seq = sequential_add(A, B)
    end = time.time()
    print("Sequential Time:", end - start)

    # Parallel
    start = time.time()
    C_par = parallel_add(A, B)
    end = time.time()
    print("Parallel Time:", end - start)

    # Verification
    print("Results same:", np.all(np.array(sequential_add) == np.array(parallel_add)))