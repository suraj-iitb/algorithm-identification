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

void SelectionSort(std::vector<int> &listToSort, int &swapCounter){
    int mini;
    for (int i=0; i<listToSort.size(); i++) {
        mini = i;
        for (int j=i; j<listToSort.size(); j++) {
            if(listToSort[j]<listToSort[mini]) {
                mini = j;
            }
        }

        std::swap(listToSort[i],listToSort[mini]);
        if (i!=mini) swapCounter++;
    }
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
    
    SelectionSort(list, swapNumber);

    print_array(list);
    std::cout << swapNumber << std::endl;

    return 0;
}
