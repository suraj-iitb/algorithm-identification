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
    while (1) {
        bool bubbled = false;
        for (int i = 0; i < number - 1; i++) {
            if (list[i] > list[i + 1]) {
                int tmp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = tmp;
                count++;
                bubbled = true;
            }
        }
        if (!bubbled) {
            break;
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
