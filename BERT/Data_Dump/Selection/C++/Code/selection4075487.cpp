#include <iostream>
#include <utility>
#include <algorithm>

int count = 0;

void selectionSort(int* num, int N)
{
  for(int i=0; i<N-1; ++i){
    int minj = i;
    for(int j=i+1; j<N; ++j){
      /*
        std::cout << "i = " << i << " / num[" << j << "] = "
        << num[j] << " / num[minj] = " << num[minj]
        << " / minj = " << minj << std::endl;
      */
      if( num[j] < num[minj] ){
        minj = j;
      }
    }
    if( i != minj ){
      std::swap(num[i], num[minj]);
      count++;
    }
  }
}


int main()
{
  int n;
  std::cin >> n;

  int num[n];
  for(int i=0; i<n; ++i){
    std::cin >> num[i];
  }

  selectionSort(num, n);

  for(int i=0; i<n; ++i){
    if(i != 0) std::cout << " ";
    std::cout << num[i];
  }
      std::cout << std::endl;
    std::cout << count << std::endl;

    return 0;
}
