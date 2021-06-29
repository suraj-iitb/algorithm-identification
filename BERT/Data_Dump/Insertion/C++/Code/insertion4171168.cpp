#include <iostream>

void PrintArray(int arr[], int length){
    for(int i = 0; i < length; ++i){
        std::cout << arr[i] << ((i == length-1) ? "\n" : " ");
    }
}

void InsertionSort(int arr[], int length){
    PrintArray(arr, length);
    for(int i = 1; i < length; ++i){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
        PrintArray(arr, length);
    }
}

int main(void){
    int length ;
    std::cin >> length;
    int* arr = new int[length];
    for(int i = 0; i < length; ++i) std::cin >> arr[i];
    InsertionSort(arr, length);
    delete[] arr;
}
