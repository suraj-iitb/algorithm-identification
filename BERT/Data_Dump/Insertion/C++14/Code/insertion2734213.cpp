#include <iostream>

void print_array(int* array, int n) {
  for (int i = 0; i < n; ++i) {
    if (i) {
      std::cout << " ";
    }
    std::cout << array[i];
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[])
{
  int n;
  std::cin >> n;
  int* a = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  print_array(a, n);

  int v, j;
  for (int i = 1; i < n; ++i) {
    v = a[i];
    j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;

    print_array(a, n);
  }
  return 0;
}

