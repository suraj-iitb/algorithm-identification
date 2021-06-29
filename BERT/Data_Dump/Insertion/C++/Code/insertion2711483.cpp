#include <iostream>
#include <stdio.h>

void print_array(int n, int* a)
{
    for (int i = 0; i < n; i++) {
        std::cout << a[i];
        if (i != n - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}


int main()
{
    int number;
    std::cin >> number;

    int array[number];
    for (int i = 0; i < number; i++) {
        std::cin >> array[i];
    }

    for (int i = 1; i < number; i++) {
        print_array(number, array);
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
    print_array(number, array);
}

