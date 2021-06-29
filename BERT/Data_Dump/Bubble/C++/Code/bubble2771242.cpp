#include <iostream>
#include <stdlib.h>

using namespace std;
int main(){
  int N;
  int count=0;
  std::cin >> N;
  int A[N];
  for(int i=0;i<N;i++){
    std::cin >> A[i];
  }
  bool flag=true;
  while(flag){
    flag=false;
    for(int i=N-1;i>=1;i--){
      if(A[i]<A[i-1]){
        count++;
        flag=true;
        int tmp=A[i];
        A[i]=A[i-1];
        A[i-1]=tmp;
      }
    }
  }
  for(int i=0;i<N-1;i++){
    std::cout << A[i]<<" " ;
  }
  std::cout << A[N-1] << '\n';

  std::cout << count << '\n';


}

