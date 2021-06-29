#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
template<class T>
void printvec(std::vector<T> vec){
  std::size_t n = vec.size();
  for(int i = 0; i<n - 1; ++i){
    std::cout << vec[i] << " ";
  }
  std::cout << vec[n - 1] << std::endl;
}

int main(int const argc, char const** argv){
  int n;
  std::cin >> n;
  std::vector<int> vec;
  for(int i = 0; i<n; ++i){
    int j;
    std::cin >> j;
    vec.push_back(j);
  }
  int count = 0;
  int flag = 1;

  for(int i = 0;i<n ; ++i){
    for(int j = i; j>0; --j){
      if(vec[j - 1]>vec[j]){
	std::swap(vec[j - 1], vec[j]);
	count++;
      }
    }
  }

  for(int j = n - 1; j != 0; j--){
    if(vec[j]<vec[j - 1]){
      std::swap(vec[j], vec[j - 1]);
      count++;
      flag = 1;
    }
  }
  
  printvec(vec);
  
  std::cout << count << std::endl;
  
}
