#include <iostream>

int main(){
    //I/O section
    int n;
    std::cin >> n;

    int *arr = new int[n];
    int i = 0;
    for(; i < n; ++i){
        std::cin >> arr[i];
    }
    //std::cout << "\n";

    int k;
    for(k = 0; k < n; ++k){
        std::cout << arr[k] << ( (k < n - 1)? " " : "");
    }
    std::cout << std::endl;

    //insertionSort section
    for(i = 1; i < n; ++i){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;

        //process output
        for(k = 0; k < n; ++k){
            std::cout << arr[k] << ( (k < n - 1)? " " : "");
        }
        std::cout << "\n";
    }
}
