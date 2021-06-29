#include <iostream>
#include <stdlib.h>
#include <stdio.h>      /* printf */
#include <math.h>       /* pow */
#include <vector>
#include <algorithm>

void print_array(std::vector<int> list)
{
  for(int i = 0; i < list.size(); ++i){
    if(i>0) std::cout << " ";
    std::cout << list[i];
  }
  std::cout << std::endl;
}

int main(void){

    int num;
    std::cin >> num;
    if (num>100) {
        std::cout << "list too big" << std::endl;
        return 1;
    }
    std::vector<int> list;
    for(int i = 0; i < num; i++){
    int value;
    std::cin >> value;
    list.push_back(value);
    }

    int swapNumber=0;
    for (int j=0; j < list.size(); j++) {
        for (int k=list.size()-1; k>j; k--) {
            if(list[k]<list[k-1]) {
                std::swap(list[k],list[k-1]);
                swapNumber++;
            }
        }
            
    }

    print_array(list);
    std::cout << swapNumber << std::endl;

    return 0;
}
