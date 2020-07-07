
test_case_1_num = int(input())
test_case_1 = list(map(int,input().split()))

print(" ".join(map(str, test_case_1)))
for i in range(1, test_case_1_num):
    t = test_case_1[i]
    p = i
    for j in range(0, i):
        if t > test_case_1[j]:
            continue
        else:
            for k in reversed(range(j,i)):
                test_case_1[k + 1] = test_case_1[k]
                p -= 1
            break

    test_case_1[p] = t

    print(" ".join(map(str, test_case_1)))
