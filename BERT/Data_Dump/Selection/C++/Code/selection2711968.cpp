#include <iostream>

int main()
{
    int number;
    std::cin >> number;

    int list[number];
    for (int i = 0; i < number; i++) {
        std::cin >> list[i];
    }

    int count = 0;
    for (int i = 0; i < number; i++) {
        int min = i;
        for (int j = i; j < number; j++) {
            if (list[j] < list[min]) {
                min = j;
            }
        }
        if (min != i) {
            int tmp = list[i];
            list[i] = list[min];
            list[min] = tmp;
            count++;
        }
    }

    for (int i = 0; i < number; i++) {
        std::cout << list[i];
        if (i != number - 1) {
            std::cout << " ";
        } else {
            std::cout << std::endl;
        }
    }

    std::cout << count << std::endl;
}

