#include <limits.h>
#include <iostream>
#include <vector>

void insertionSort(std::vector<int> &data, int dataLength);

int main(void)
{
    int dataLength = 0;         // データ数
    // データ数を入力
    std::cin >> dataLength;

    std::vector<int> data(dataLength);   // ソートデータ

    for (int i = 0; i < dataLength; i++) {
        std::cin >> data[i];
    }

    std::cout << data[0];
    for (int k = 1; k < dataLength; k++) {
        std::cout << " " << data[k];
    }
    std::cout << "\n";
    insertionSort(data, dataLength);

    return 0;
}

void insertionSort(std::vector<int> &data, int dataLength)
{
    for (int i = 1; i < dataLength; i++) {
        int v = data[i];

        int j = i - 1;
        while (j >= 0 && data[j] > v) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = v;

        std::cout << data[0];
        for (int k = 1; k < dataLength; k++) {
            std::cout << " " << data[k];
        }
        std::cout << "\n";
    }
    return;
}
