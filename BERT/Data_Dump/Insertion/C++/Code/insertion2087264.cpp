#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
int main(int const argc, char const** argv){
  int n;
  std::cin >> n;
  std::vector<int> vec;;
  for(int i = 0; i<n; ++i){
    int j;
    std::cin >> j;
    vec.push_back(j);
  }

  
  for(int i = 0; i<n - 1; ++i){
    std::cout << vec[i] << " ";
  }
  std::cout << vec[n - 1] << "\n";

  for(int i = 1; i<n; ++i){
    int v = vec[i];
    int j = i - 1;
    while(j >= 0 &&  vec[j]>v){
      vec[j + 1] = vec[j];
      j--;
      vec[j + 1] = v;
    }
    for(int i = 0; i<n - 1; ++i){
      std::cout << vec[i] << " ";

    }
    std::cout << vec[n - 1] << "\n";
  

  }

}
