N = int(input())
numbers = list(map(int,input().split()))

def trace(numbers):
  a = str(numbers[0])
  for i in range(1,len(numbers)):
    a += " "
    a += str(numbers[i])
  print(a)

trace(numbers)
for current_i in range(1,N):
  for compare_i in range(current_i-1,-1,-1):

    if(numbers[compare_i] > numbers[current_i]):
      hoge = numbers[compare_i]
      numbers[compare_i] = numbers[current_i]
      numbers[current_i] = hoge

      current_i = compare_i
  trace(numbers)



