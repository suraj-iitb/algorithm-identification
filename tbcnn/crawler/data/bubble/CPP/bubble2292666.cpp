#include<iostream>

int main(){
  int N;
  std::cin >> N;
  
  int A[100];
  for(int i=0;i<N;++i){
    std::cin >> A[i];
  }
  
  int not_sort = 1,change=0;
  while(not_sort){
    not_sort = 0;
    for(int i=0;i<N-1;++i){
      if(A[i]>A[i+1]){
        int tmp;
        tmp = A[i];
        A[i] = A[i+1];
        A[i+1] =tmp;
        not_sort = 1;
        change++;
      }
    }
    
  }
  
  for(int i=0;i<N;++i){
    std::cout << A[i];
    if(i!=N-1){
      std::cout << " ";
    }else{
      std::cout << std::endl;
    }
    
  }
  
  std::cout << change << std::endl;
  
  return 0;
}
