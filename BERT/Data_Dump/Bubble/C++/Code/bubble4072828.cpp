#include <iostream>
#include <utility>

int count = 0;
void bubbleSort(int num[], int N)
{
  for(int i=0; i<N-1; ++i){
    for(int j=N-1; j>i; --j){
      if(num[j] < num[j-1]){
        std::swap(num[j], num[j-1]);
        count++;
      }
    }
  }
}

int main(){
  int n;
  std::cin >> n;

  int num[n];
  for(int i=0; i<n; ++i){
    std::cin >> num[i];
  }
  bubbleSort(num, n);
  for(int i=0; i<n; ++i){
    if(i != 0) std::cout << " ";
    std::cout << num[i];
  }
  std::cout << std::endl;
  std::cout << count << std::endl;
  return 0;
}
