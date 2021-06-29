#include<iostream>


void print_list(int* a, int n){
  for(int i = 0; i < n - 1; i++){
    std::cout << a[i] << " ";
  }
  std::cout << a[n - 1] << std::endl;
}

void insertionSort(int* a, int n){
  print_list(a, n);
  for(int i = 1; i < n; i++){
    int v = a[i];
    int j = i - 1;
    while(i >= 0 && a[j] > v){
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;

    print_list(a, n);
  }
}

int main(){
  int n;
  std::cin >> n;

  int a[n];
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }
  
  insertionSort(a, n);
 
  return 0;
}

