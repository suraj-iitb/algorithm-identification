#include <iostream>

void ArrayDump(int *A, int N)
{
    for (int i = 0; i < N; i++) {
        std::cout << *(A + i);
        if (i != N - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int SelectionSort(int *A, int N)
{
    int exchange_num = 0;
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            int tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
            exchange_num++;
        }
    }
    return exchange_num;
}

int main(int argc, char* argv[])
{
    int array_size = 0;
    int array[100];

    std::cin >> array_size;
    for (int i = 0; i < array_size; i++) {
        std::cin >> array[i];
    }

    int exchange_num = SelectionSort(array, array_size);
    ArrayDump(array, array_size);
    std::cout << exchange_num << std::endl;
}
