# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_D
sample_input = list(range(3))
sample_input[0] = '''5
5
1
4
3
2'''
sample_input[1] = '''3
3
2
1'''
sample_input[2] = '''5
5
1
4
3
2'''
give_sample_input = None
if give_sample_input is not None:
    sample_input_list = sample_input[give_sample_input].split('\n')
    def input():
        return sample_input_list.pop(0)
        
# main
def print_list(l):
    output = ''
    for elem in l:
        output += str(elem) + ' '
    output = output.rstrip()
    print(output)

def determine_G(n):
    G = []
    pot = 1
    while True:
        pot *= 2
        if pot-1 > n:
            break
        G.append(pot-1)
    G.reverse()
    return G

def log_m_floor(n):
    m = 2
    pot = 1
    power = 0
    while (pot < n):
        pot *= 2
        power += 1
    return power

def insertion_sort(A, n, g):
    cnt = 0
    for i in range(g, n):
        v = A[i]
        j = i - g
        while (j >= 0 and A[j] > v):
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v
    return cnt

def shell_sort(A, n):
    cnt = 0
    G = determine_G(n)
    m = len(G)
    if m == 0:
        print(1)
        print(1)
        print(0)
        return
    print(m)
    print_list(G)
    for i in range(m):
        cnt += insertion_sort(A, n, G[i])
    print(cnt)
        
num_of_data = int(input())
data = []
for i in range(num_of_data):
    data.append(int(input()))
shell_sort(data, num_of_data)
for d in data:
    print(d)
