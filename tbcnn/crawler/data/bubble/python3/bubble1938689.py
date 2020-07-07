def main():
  element_num = int(input())
  elements = [int(s) for s in input().split()]
  swap_count = 0

  for i in range(1, element_num):
    for j in reversed(range(i, element_num)):
      if elements[j-1] > elements[j]:
        elements[j-1], elements[j] = elements[j], elements[j-1]
        swap_count += 1

  print(' '.join(list(map(str, elements))))
  print(swap_count)
  return 0

if __name__ == '__main__':
  main()
