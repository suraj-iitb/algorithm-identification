#include <iostream>

int main() {

  int i, j, num, check, temp;
  int ary[110];

  std::cin >> num;

  for (i = 0; i <= num - 1; i++) std::cin >> ary[i];

  for (i = 0; i <= num - 2; i++) std::cout << ary[i] << " ";
  std::cout << ary[num - 1] << std::endl;

  for (i = 1; i <= num - 1; i++) {

    check = i;

    while (check >= 1 && ary[check - 1] > ary[check]) {

      temp           = ary[check];
      ary[check]     = ary[check - 1];
      ary[check - 1] = temp;

      check --;
    }

    //Output
    for (j = 0; j <= num - 2; j++) std::cout << ary[j] << " ";
    std::cout << ary[num - 1] << std::endl;
  }

  return 0;
}

