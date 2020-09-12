#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc,char* argv[]){
  int n;
  std::cin >> n;

  std::vector<int> array(n);

  for(int i = 0; i < n; i++){
    std::cin >> array[i];
  }
  
  int count = 0;
  for(int i = 0; i < n; i++){
    for(int j = n - 1; j >= i + 1; j--){
      if(array[j] < array[j - 1]){
	std::swap(array[j], array[j-1]);
	count++;
      }
    }
  }
  
  bool first = true;
  for(int i = 0; i < n; i++){
    if(!first){
      std::cout << " ";
    }else{
      first = false;
    }
    
    std::cout << array[i];
  }
  std::cout << std::endl;
  std::cout << count << std::endl;

  return 0;
  
}
