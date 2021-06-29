#include <iostream>

void insertionSort(int * A, int N) {
    for(int i=1; i<N; i++) {
        std::cout << A[0];
        for(int k=1; k < N; k++) {
            std::cout <<  " " << A[k];
        }
        std::cout << std::endl;
        int v = A[i];
        int j = i-1;
        while (j>=0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
}

int main() {
    int num;
    std::cin >> num;
    int *arr = new int(num);
    for (int k=0; k< num; k++) {
        std::cin >> arr[k];
    }
    insertionSort(arr, num);
    std::cout << arr[0];
    for(int i=1; i < num; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;
    return 0;
}
