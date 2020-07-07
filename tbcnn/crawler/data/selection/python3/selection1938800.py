def main():
  element_num = int(input())
  elements = [int(s) for s in input().split()]
  swap_count = 0

  for i in range(0, element_num - 1):
    min_val = elements[i + 1]
    min_index = i + 1
    for j in range(i + 1, element_num):
      if elements[j] < min_val:
        min_val = elements[j]
        min_index = j
    if elements[i] > elements[min_index]:
      elements[i], elements[min_index] = elements[min_index], elements[i]
      swap_count += 1

  print(' '.join(list(map(str, elements))))
  print(swap_count)

  return 0


if __name__ == '__main__':
  main()
