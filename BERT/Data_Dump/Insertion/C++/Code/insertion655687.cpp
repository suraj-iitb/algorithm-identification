#include <iostream>
#include <vector>

void print(std::vector<int>& array){
  bool first = true;
  for(int i = 0; i < array.size(); i++){
    if(!first){
      std::cout << " ";
    }else{
      first = false;
    }

    std::cout << array[i];
  }

  std::cout << std::endl;
}

int main(int argc,char* argv[]){
  int n;
  std::vector<int> array;

  std::cin >> n;

  for(int i = 0; i < n; i++){
    int tmp;
    std::cin >> tmp;
    array.push_back(tmp);
  }

  print(array);
  for(int j = 1; j < n; j++){
    int key = array[j];
    
    int i = j - 1;
    while(i >= 0 && array[i] > key){
      array[i+1] = array[i];
      i--;
    }

    array[i + 1] = key;
    print(array);
  }

  return 0;  
}
