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
    int min = i;

    for(int j = i; j < n; j++){
      if(array[j] < array[min]){
	min = j;
      }
    }
    
    if(i != min){
      std::swap(array[i], array[min]);
      count++;
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
