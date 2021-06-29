#include <iostream> 
#include <vector> 
#include <utility> 

void print(std::vector<int> numArray) {
    int index = 0; 
    int size = numArray.size();
    for (; index < size; ++index) {
        std::cout << numArray[index];
        if (index != size - 1) {std::cout <<  ' ';}
    }
    std::cout << '\n'; 
}

std::pair<int, std::vector<int> > selectionSort(std::vector<int> numArray) {
    std::pair<int, std::vector<int> > returnValues;
    int index = 0; 
    int size = numArray.size();
    int numSwaps = 0;
    for (; index < size; ++index) {
        int minIndex = index;
        int secIndex = index;
        for (; secIndex < size; ++secIndex) {
            if (numArray[secIndex] < numArray[minIndex]) {
                minIndex = secIndex;
            }
        }
        std::swap<int>(numArray[index], numArray[minIndex]);
        if (minIndex != index) {numSwaps++;}
        
    }
    returnValues.first = numSwaps;
    returnValues.second = numArray;
    return returnValues;
}

int main (void) {
    std::pair<int, std::vector<int> > returnValues;
    int size = 0;
    std::cin >> size; 
    std::vector<int> numArray(size);
    int index = 0;
    for (;index < size; ++index) {
        std::cin >> numArray[index];
    }
    try {
        returnValues = selectionSort(numArray);
    } catch(...) {
        std::cout << "err"<< "\n";
    }
    
    print(returnValues.second);
    std::cout << returnValues.first << "\n" ;
}
