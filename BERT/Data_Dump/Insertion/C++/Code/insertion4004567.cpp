#include <stdio.h>
#include <iostream>
#include <vector>

int pvec(std::vector<int> vec) {
  std::cout << vec.at(0);
  for (int i =1; i< vec.size();i++){
    std::cout << " " << vec.at(i) ;
  }
  std::cout << std::endl;
}

int main(){
  int N ;
  std::cin >> N;

  std::vector<int> vec(N);
  for (int i=0; i < N ; i++) {
    std::cin >> vec.at(i);
  }


  pvec(vec);
  /* insertion sort */
  int v ;
  int j ;
  for (int i=1; i < vec.size() ; i++) {
    v = vec.at(i);
    j = i -1;
    while( j >=0 and vec.at(j) > v ) {
      vec.at(j+1) = vec.at(j);
      j--;
    }
    vec.at(j+1) = v;
    pvec(vec);
  }

}
