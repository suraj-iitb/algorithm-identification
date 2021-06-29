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

std::pair<int, std::vector<int> > bubbleSort(std::vector<int> numArray) {
    std::pair<int, std::vector<int> > returnValues;
    int index = 0; 
    int size = numArray.size();
    int numSwaps = 0;
    for (; index < size; ++index) {
        int secIndex = size - 1;
        for (; secIndex > index; --secIndex) {
            if (numArray[secIndex] < numArray[secIndex - 1]) {
                std::swap<int>(numArray[secIndex], numArray[secIndex - 1]);
                numSwaps++;
            }
        }
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
        returnValues = bubbleSort(numArray);
    } catch(...) {
        std::cout << "err"<< "\n";
    }
    
    print(returnValues.second);
    std::cout << returnValues.first << "\n" ;
}
