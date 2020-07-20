#include<iostream>

void print_list(int* a, int n){
  for(int i = 0; i < n - 1; i++){
    std::cout << a[i] << " ";
  }
  std::cout << a[n - 1] << std::endl;
}

void bubbleSort(int* a, int n){
  bool sorted = false;
  int swap_count = 0;
  while(!sorted){
    sorted = true;
    for(int i = n - 1; i > 0; i--){
      if(a[i] < a[i - 1]){
	int t = a[i]; a[i] = a[i - 1]; a[i - 1] = t;
	sorted = false;
	swap_count++;
      }
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
  
  bubbleSort(a, n);
 
  return 0;
}

