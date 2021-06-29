#include <iostream>

int main(int argc, char const* argv[])
{
    const int index_max = 2000000;
    const int data_max  = 10000;
    int       n;
    std::cin >> n;
    int data[index_max];
    int backet[data_max];
    for (int i = 0; i < n; i++) {
        std::cin >> data[i];
        backet[data[i]]++;
    }

    int cnt = 0;
    for (int i = 0; i < data_max; i++) {
        for (int j = 0; j < backet[i]; j++) {
            if (cnt) {
                std::cout << " ";
            }
            std::cout << i;
            cnt++;
        }
    }
    std::cout << std::endl;

    return 0;
}

