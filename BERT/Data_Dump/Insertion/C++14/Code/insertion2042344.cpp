//
// Created by tac on 2016/10/23.
//

#include <cstdlib>
#include <iostream>

namespace {
const int ARRAY_SIZE = 100;
int array[ARRAY_SIZE];

void print_array(const int array[], const int n) {
    std::string sep {""};
    for (int i = 0; i < n; ++i) {
        std::cout << sep;
        std::cout << array[i];
        sep = " ";
    }
    std::cout << std::endl;
    return;
}

//1 insertionSort(A, N) // N??????????´??????????0-?????????????????????A
//2   for i ??? 1 ?????? N-1 ?????§
//3     v = A[i]
//4     j = i - 1
//5     while j >= 0 ?????? A[j] > v
//6       A[j+1] = A[j]
//7       j--
//8     A[j+1] = v
void sort_array(int array[], const int n) {
    print_array(array, n);
    for (int i = 1; i < n; ++i) {
        int v = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > v) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = v;
        print_array(array, n);
    }
    return;
}

}

int main() {
    int n;
    int s;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> s;
        array[i] = s;
    }
    sort_array(array, n);
    return EXIT_SUCCESS;
}
