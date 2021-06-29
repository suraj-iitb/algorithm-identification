#include <stdio.h>
#include <iostream>
#include <vector>

int main(){
  int N;
  std::cin >> N;

  std::vector<int> vec(N);
  for (int i=0;i<N;i++){
    std::cin >> vec.at(i);
  }

  int count =0;
  bool flg = true;
  while (flg) {
    flg = false;
    for (int i=N-1 ; i > 0 ; i--  ) {
      if (vec.at(i)  < vec.at(i-1)) {
        int v1 = vec.at(i);
        vec.at(i) = vec.at(i-1);
        vec.at(i-1) = v1;
        flg =true;
        count++;
      }
    }
  }

  std::cout << vec.at(0);
  for (int i=1;i < N;i++){
    std::cout << " " << vec.at(i);
  }
  std::cout << std::endl << count << std::endl;

}
