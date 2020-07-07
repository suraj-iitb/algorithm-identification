def main():
  input()
  ary = list(map(int,input().split()))

  print(*ary)
  for i in range(1, len(ary)):
    v = ary[i]
    j = i - 1
    while (j >= 0) and (ary[j] > v):
      ary[j + 1] = ary[j]
      j -= 1
    ary[j + 1] = v
    print(*ary)

if __name__ == '__main__':
  main()

