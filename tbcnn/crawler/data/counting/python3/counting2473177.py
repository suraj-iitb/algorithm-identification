def CountingSort(A, B, k, n):
    C = [0 for i in range(k)]   #  for i = 0 to k { C[i] = 0 }

    # /* C[i] ??? i ???????????°????¨?????????? */
    for j in range(n):
        C[A[j]] += 1
#        print("j:{} Aj:{} C[Aj]:{}".format(j,A[j], C[A[j]]))

    # /* C[i] ??? i ??\????????°???????????°????¨??????????*/
    for i in range(k):
#        print("\ti:{} Ci:{} Ci-1:{}".format(i,C[i], C[i-1]))
        C[i] = C[i] + C[i-1]

    for j in reversed(range(n)):
#        print("j:{} Aj:{} C[Aj]:{} k:{}".format(j,A[j], C[A[j]],k))
        B[C[A[j]]] = A[j]
        C[A[j]] -= 1

def main():
    """ ????????? """
    num = int(input().strip())
    A = list(map(int,input().split()))
    max = 0
    for i in range(num):
        if max < A[i]:
            max = A[i]
    if max < num:
        max = num
    max += 2
    B = [0 for i in range(num + 2)]
    CountingSort(A, B, max, num)
    print(" ".join(map(str,B[1:num+1])))

if __name__ == '__main__':
    main()
