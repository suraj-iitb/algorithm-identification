#include <iostream>

class Insertion{
public:
  void trace(int *A, int N){
      for(int i = 0; i < N; ++i){
          if(i > 0) std::cout << " ";
          std::cout << A[i];
      }
      std::cout << std::endl;
      return;
  } 
  void insertion_sort(int *A, int N){
      for(int i = 1; i < N; ++i){
          int v = A[i];
          int j = i - 1;
          while(j >= 0 && v < A[j]){
            A[j + 1] = A[j];
            --j;
          }
          A[j + 1] = v;
          trace(A, N);
      }
  }  
};

int main(){
    Insertion ins;
    int A[100];
    int N;
    
    std::cin >> N;
    for(int i = 0; i < N; ++i){
        std::cin >> A[i];
    }
    ins.trace(A, N);
    ins.insertion_sort(A, N);
    return 0;
}
