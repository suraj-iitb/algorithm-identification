#!/usr/bin/python

import sys


def main():
  length = int(input())
  elements = list(map(int, input().split()))
  print(" ".join(str(i) for i in elements))

  sorted_list = [elements[0]]
  for i in range(1, length):
    element = elements[i]
    for j in range(0, len(sorted_list) + 1):
      if j == len(sorted_list):
        sorted_list.append(element)
      elif element < sorted_list[j]:
        sorted_list.insert(j, element)
        break
    output_list = sorted_list[0:i+1] + elements[i+1:]
    print(" ".join([str(i) for i in output_list]))

  return 0

if __name__ == '__main__':
  main()
