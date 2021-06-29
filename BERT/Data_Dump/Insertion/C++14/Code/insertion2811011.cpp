// InsertionSort.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

bool insertionSort(std::vector<int> &array, int n);

int main()
{
    int n = 0;
    std::string input;
    std::getline(std::cin, input);
    n = std::stoi(input);

    std::vector<int> array;
    std::getline(std::cin, input);
    std::stringstream ss(input);

    std::string buf;
    while (ss >> buf) {
        array.push_back(std::stoi(buf));
    }

    insertionSort(array, array.size());
    
    return 0;
}

bool insertionSort(std::vector<int> &array, int n)
{
    for (int i = 0, j = 0; i < n; i++) {
        auto v = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > v) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = v;

        for (int k = 0; k < n; k++) {
            std::cout << array[k];
            if (k != n - 1) {
                std::cout << " ";
            }

        }
        std::cout << std::endl;
    }

    return true;
}
