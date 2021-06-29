#include<iostream>

void print_list(int* a, int n){
  for(int i = 0; i < n - 1; i++){
    std::cout << a[i] << " ";
  }
  std::cout << a[n - 1] << std::endl;
}

void selectionSort(int* a, int n){
  int swap_count = 0;
  for(int i = 0; i < n - 1; i++){
    int minj = i;
    for(int j = i; j < n; j++){
      if(a[j] < a[minj]){
	minj = j;
      }
      
    }
    if(i != minj){
      int t = a[i]; a[i] = a[minj]; a[minj] = t;
      swap_count++;
    }
  }

  print_list(a, n);
  std::cout << swap_count << std::endl;
}

int main(){
  int n;
  std::cin >> n;

  int a[n];
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }
  
  selectionSort(a, n);
 
  return 0;
}

