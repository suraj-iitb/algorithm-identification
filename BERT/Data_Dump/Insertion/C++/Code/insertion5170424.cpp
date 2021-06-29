#include <iostream>
#include <vector>

void printArray(const std::vector<int> numbers, int size) {
    int index = 0; 
    for (;index < size; ++index) {
        std::cout << numbers[index]; 
        if (index != size - 1) {
            std::cout << ' '; 
        }
    }
    std::cout <<"\n";
}

void insertionSort(const std::vector<int> numbers, int size) {
    std::vector<int> newArray(size);
    int index = 0;
    for (;index < size;  ++index) { // Making a copy of the initial array: 
        newArray[index] = numbers[index]; 
    }
    index = 1; 
    for (;index < size;  ++index) {
        int key = newArray[index];
        int secIndex = index - 1;
        while (secIndex >= 0 && key < newArray[secIndex]) {
            newArray[secIndex + 1] = newArray[secIndex];
            secIndex--;
        }
        newArray[secIndex + 1] = key; 
        printArray(newArray, size); 
    }
}

int main() {
    int size = 0;
    std::cin >> size; 
    std::vector<int> numbers(size); 
    int index = 0;
    for (;index < size; ++index) {
        std::cin >> numbers[index]; 
    }
    printArray(numbers, size);
    try
    {
        insertionSort(numbers, size);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
